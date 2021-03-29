/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:45:05 by javrodri          #+#    #+#             */
/*   Updated: 2021/03/29 12:52:06 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error(char *error)
{
  write(1, error, ft_strlen(error));
  write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	//t_philo	philo;
	argv = NULL;
	if (argc < 5 || argc > 6)
	  error("Error: bad arguments");
	return (1);	  
}
