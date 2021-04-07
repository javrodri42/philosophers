/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:12:06 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/07 13:00:19 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->forks_mutex[philo->left_fork]);
	printing(philo, " has taken a fork\n", 0);
	pthread_mutex_lock(&philo->state->forks_mutex[philo->right_fork]);
	printing(philo, " has taken a fork\n", 0);
}

void	leave_forks(t_philo *philo)
{
	printing(philo, " is sleeping\n", 0);
	pthread_mutex_unlock(&philo->state->forks_mutex[philo->left_fork]);
	pthread_mutex_unlock(&philo->state->forks_mutex[philo->right_fork]);
	usleep(philo->state->time_to_sleep);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->eating = 1;
	philo->last_eat = gettime();
	philo->limit = philo->last_eat + philo->state->time_to_die;
	printing(philo, " is eating\n", 0);
	usleep(philo->state->time_to_eat * 1000);
	philo->eat_count++;
	philo->eating = 0;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->eat_mutex);
}
