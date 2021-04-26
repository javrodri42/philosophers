/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:56:51 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/26 13:59:56 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_forks(t_philo *philo)
{
	if (sem_wait(philo->state->forks_mutex))
		return (1);
	if (print(philo, "take fork"))
		return (1);
	if (sem_wait(philo->state->forks_mutex))
		return (1);
	if (print(philo, "take fork"))
		return (1);
	return (0);
}

int	leave_forks(t_philo *philo)
{
	if (sem_post(philo->state->forks_mutex))
		return (1);
	if (sem_post(philo->state->forks_mutex))
		return (1);
	if (print(philo, "sleep"))
		return (1);
	usleep (philo->state->time_to_sleep * 1000);
	return (0);
}

int	eat(t_philo *philo)
{
	if (sem_wait(philo->mutex) != 0)
		return (1);
	philo->eating = 1;
	philo->last_eat = gettime();
	philo->limit = philo->last_eat + philo->state->time_to_die;
	if (print(philo, "is eating"))
		return (1);
	usleep(philo->state->time_to_eat * 1000);
	philo->eat_count++;
	philo->eating = 0;
	if (sem_post(philo->mutex))
		return (1);
	if (sem_post(philo->eat_count_mutex))
		return (1);
	return (0);
}

uint64_t	gettime(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}
