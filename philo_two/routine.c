/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:46:09 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/14 12:43:16 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*dead_monitor(void *arg_philo)
{
	t_philo	*philo;

	philo = (t_philo *)arg_philo;
	while (1)
	{
		sem_wait(philo->mutex);
		if (philo->eating == 0 && gettime() > philo->limit)
		{
			printing(philo, " died\n", 1);
			sem_post(philo->mutex);
			sem_post(philo->state->somebody_dead_mutex);
		}
		sem_post(philo->mutex);
	}
	return ((void *)0);
}

void	*count_monitor(void *arg_state)
{
	t_state	*state;
	int		i;

	state = (t_state *)arg_state;
	while (state->total_eat_count < state->must_eat_count)
	{
		printf("total:%i\n", state->total_eat_count);
		i = 0;
		while (i < state->amount)
			if (sem_wait(state->philos[i++].eat_count_mutex))
				return ((void *)0);
		state->total_eat_count++;
	}
	printing(&state->philos[0], "\e[0;92;40m must eat count reached\e[0m\n", 1);
	sem_post(state->somebody_dead_mutex);
	return ((void *)0);
}

void	*routine(void *arg_philo)
{
	t_philo		*philo;
	pthread_t	thread_id;

	philo = (t_philo *) arg_philo;
	philo->last_eat = gettime();
	philo->limit = philo->last_eat + philo->state->time_to_die;
	if (pthread_create(&thread_id, NULL, &dead_monitor, arg_philo) != 0)
		return ((void *)0);
	pthread_detach(thread_id);
	while (1)
	{
		take_forks(philo);
		eat(philo);
		leave_forks(philo);
		printing(philo, " is thinking\n", 0);
	}
	return ((void *)0);
}
