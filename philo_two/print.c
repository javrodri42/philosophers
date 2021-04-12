/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:01:13 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/12 13:10:19 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	printing(t_philo *philo, char *str, int n)
{
	sem_wait(philo->state->write_mutex);
	printf("%llu\t%i%s", gettime() - philo->state->start,
		philo->position + 1, str);
	if (n == 1)
		return (0);
	sem_post(philo->state->write_mutex);
	return (0);
}
