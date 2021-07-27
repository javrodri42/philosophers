/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:01:13 by javrodri          #+#    #+#             */
/*   Updated: 2021/07/01 13:25:28 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	printing(t_philo *philo, char *str, int n)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->state->write_mutex);
	time = gettime();
	ft_putnbr(time - philo->state->start);
	write(1, "\t", 1);
	ft_putnbr(philo->position + 1);
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
	write (1, "\n", 1);
	if (n == 1)
		return (0);
	if (pthread_mutex_unlock(&philo->state->write_mutex))
		return (1);
	return (0);
}
