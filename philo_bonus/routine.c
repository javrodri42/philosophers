/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:57:12 by javrodri          #+#    #+#             */
/*   Updated: 2021/07/05 14:03:29 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*dead_monitor(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	while (1)
	{
		if (sem_wait(philo->mutex) != 0)
			return ((void *)0);
		if (!philo->eating && gettime() > philo->limit)
		{
			if (print(philo, "has died"))
				return ((void *)0);
			if (sem_post(philo->mutex))
				return ((void *)0);
			if (sem_post(philo->state->somebody_dead_mutex))
				return ((void *)0);
			return ((void *)0);
		}
		if (sem_post(philo->mutex))
			return ((void *)0);
	}
	return ((void *)0);
}

void	*count_monitor(void *state_argv)
{
	int		i;
	t_state	*state;

	state = state_argv;
	while (state->total_eat_count < state->must_eat_count)
	{
		i = 0;
		while (i < state->amount)
			if (sem_wait(state->philos[i++].eat_count_mutex))
				return ((void *)0);
		state->total_eat_count++;
	}
	if (print(&state->philos[0], "\e[0;92;40m must eat count reached\e[0m"))
		return ((void *)0);
	if (sem_post(state->somebody_dead_mutex))
		return ((void *)0);
	return ((void *)0);
}

void	*routine(void *philo_arg)
{
	t_philo		*philo;
	pthread_t	id;
	int			aux;

	philo = (t_philo *)philo_arg;
	philo->last_eat = gettime();
	philo->limit = philo->last_eat + philo->state->time_to_die;
	if (pthread_create(&id, NULL, &dead_monitor, philo_arg) != 0)
		return ((void *)1);
	pthread_detach(id);
	while (1)
	{
		if (take_forks(philo))
			return ((void *)0);
		aux = eat(philo);
		if (leave_forks(philo))
			return ((void *)0);
		if (aux)
			return ((void *)0);
		if (print(philo, "is thinking"))
			return ((void *)0);
	}
	return ((void *)0);
}
