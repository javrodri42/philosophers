/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:46:09 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/06 12:54:47 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *dead_monitor(void *arg_philo)
{
    t_philo *philo;

    philo = (t_philo*)arg_philo;
    while (1)
    {
        pthread_mutex_lock(&philo->mutex);
        if (philo->eating == 0 && gettime() > philo->limit)
        {
            printf("%i has died \n", philo->position);
            pthread_mutex_unlock(&philo->mutex);
            pthread_mutex_unlock(&philo->state->somebody_dead_mutex);
        } 
        pthread_mutex_unlock(&philo->mutex);
        usleep(1000);
    }
}