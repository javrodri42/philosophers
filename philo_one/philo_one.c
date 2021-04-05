/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:45:05 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/05 14:40:37 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error(char *error)
{
  write(1, error, ft_strlen(error));
  return(1);
}

int	free_state(t_state *state)
{
	int i;

	if (state->forks_mutex)
	{
		i = 0;
		while (i < state->amount)
			pthread_mutex_destroy(&state->forks_mutex[i++]);
		free(state->forks_mutex);
	}
	if (state->philos)
	{
		i = 0;
		while (i < state->amount)
		{
			pthread_mutex_destroy(&state->philos[i].mutex);
			pthread_mutex_destroy(&state->philos[i++].eat_mutex);
		}
		free(state->philos);
	}
	pthread_mutex_destroy(&state->write_mutex);
	pthread_mutex_destroy(&state->somebody_dead_mutex);
	return(1);
}

void	philos_initialize(t_state *state)
{
	int i;

	i = 0;
	while (i < state->amount)
	{
		state->philos[i].position = i;
		state->philos[i].eating = 0;
		state->philos[i].eat_count = 0;
		state->philos[i].left_fork = i;
		state->philos[i].right_fork = (i + 1) % state->amount;
		state->philos[i].state = state;
		pthread_mutex_init(&state->philos[i].mutex, NULL);
		pthread_mutex_init(&state->philos[i].eat_mutex, NULL);
		pthread_mutex_lock(&state->philos[i].eat_mutex);
		i++;
	}
}

int parse_arguments(int argc, char **argv, t_state *state)
{
	int i;

	i = 0;
	if (argc < 5 || argc > 6)
		return(error("Error: bad arguments"));
	state->amount = ft_atoi(argv[1]);
	state->time_to_die = ft_atoi(argv[2]);
	state->time_to_eat = ft_atoi(argv[3]);
	state->time_to_sleep = ft_atoi(argv[4]);
	state->must_eat_count = 0;
	if (argc == 6)
		state->must_eat_count = ft_atoi(argv[5]);
	state->forks_mutex = NULL;
	state->philos = (t_philo*)malloc(sizeof(*(state->philos)) * state->amount);
	if (!state->philos)
		return (1);
	philos_initialize(state);

}

int	main(int argc, char **argv)
{
	t_state	state;

	if (parse_arguments(argc, **argv, state))
	{
		free_state(&state);
		error("error: fatal\n");
	}
	return (0);  
}

