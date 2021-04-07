/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:01:13 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/07 12:59:41 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	printing(t_philo *philo, char *str, int n)
{
	pthread_mutex_lock(&philo->state->write_mutex);
	printf("%llu\t%i%s", gettime() - philo->state->start,
		philo->position + 1, str);
	if (n == 1)
		return (0);
	pthread_mutex_unlock(&philo->state->write_mutex);
	return (0);
}
