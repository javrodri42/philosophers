/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:12:06 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/15 11:44:11 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	sem_wait(philo->state->forks_mutex);
	printing(philo, " has taken a fork\n", 0);
	sem_wait(philo->state->forks_mutex);
	printing(philo, " has taken a fork\n", 0);
}

void	leave_forks(t_philo *philo)
{
	printing(philo, " is sleeping\n", 0);
	sem_post(philo->state->forks_mutex);
	sem_post(philo->state->forks_mutex);
	usleep(philo->state->time_to_sleep);
}

void	eat(t_philo *philo)
{
	sem_wait(philo->mutex);
	philo->eating = 1;
	philo->last_eat = gettime();
	philo->limit = philo->last_eat + philo->state->time_to_die;
	printing(philo, " is eating 🍔\n", 0);
	philo->state->total_eat_count++;
	usleep(philo->state->time_to_eat * 1000);
	//philo->eat_count++;
	philo->eating = 0;
	sem_post(philo->mutex);
	sem_post(philo->eat_count_mutex);
}  
