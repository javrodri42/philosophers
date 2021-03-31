/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:45:05 by javrodri          #+#    #+#             */
/*   Updated: 2021/03/31 14:32:19 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error(char *error)
{
  write(1, error, ft_strlen(error));
  write(1, "\n", 1);
  return(0);
}

int parse_arguments(int argc, char **argv, t_state *state)
{
	int i;
	i = 0;
	if (argc < 5 || argc > 6)
		return(error("Error: bad arguments"));
	state.amount = ft_atoi(argv[1]);
	state.time_to_die = ft_atoi(argv[2]);
	state.time_to_eat = ft_atoi(argv[3]);
	state.time_to_sleep = ft_atoi(argv[4]);
	state.must_eat_count = 0;
	if (argc == 6);
		state.must_eat_count = ft_atoi(argv[5]);

}

int	main(int argc, char **argv)
{
	t_state	state;
	parse_arguments(argc, **argv, state);
	return (0);  
}
