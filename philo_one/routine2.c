/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:12:06 by javrodri          #+#    #+#             */
/*   Updated: 2021/07/01 13:24:48 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->forks_mutex[philo->left_fork]);
	printing(philo, " has taken a fork", 0);
	pthread_mutex_lock(&philo->state->forks_mutex[philo->right_fork]);
	printing(philo, " has taken a fork", 0);
}

void	leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->state->forks_mutex[philo->left_fork]);
	pthread_mutex_unlock(&philo->state->forks_mutex[philo->right_fork]);
	printing(philo, " is sleeping", 0);
	usleep(philo->state->time_to_sleep * 860);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	printing(philo, " is eating", 0);
	philo->eating = 1;
	philo->last_eat = gettime();
	philo->limit = philo->last_eat + philo->state->time_to_die;
	usleep(philo->state->time_to_eat * 860);
	philo->eat_count++;
	philo->eating = 0;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->eat_mutex);
}
