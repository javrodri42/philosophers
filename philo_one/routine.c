/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:46:09 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/22 11:44:59 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*dead_monitor(void *arg_philo)
{
	t_philo	*philo;

	philo = (t_philo *)arg_philo;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (!philo->eating && gettime() > philo->limit)
		{
			printing(philo, " died\n", 1);
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_unlock(&philo->state->somebody_dead_mutex);
			return ((void *)0);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(1000);
	}
}

void	*count_monitor(void *arg_state)
{
	t_state	*state;
	int		i;
	int		total;

	state = (t_state *)arg_state;
	total = 0;
	while (total < state->must_eat_count)
	{
		i = 0;
		while (i < state->amount)
			pthread_mutex_lock(&state->philos[i++].eat_mutex);
		total++;
	}
	printing(&state->philos[0], " must eat count reached\n", 1);
	pthread_mutex_unlock(&state->somebody_dead_mutex);
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
