/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:45:05 by javrodri          #+#    #+#             */
/*   Updated: 2021/03/31 10:44:49 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error(char *error)
{
  write(1, error, ft_strlen(error));
  write(1, "\n", 1);
  return(0);
}

int parse_arguments(int argc, char **argv, t_philo philo)
{
	int i;
	)
	i = 0;
	if (argc < 5 || argc > 6)
		return(error("Error: bad arguments"));
	philo.number = ft_itoa(argv[1]);
	philo.eating = ft_itoa(argv[2]);
}

int	main(int argc, char **argv)
{
	t_philo	philo;
	parse_arguments(int argc, char **argv);
	return (0);  
}
