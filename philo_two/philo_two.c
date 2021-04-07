/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:45:05 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/07 12:20:12 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error(char *error, t_state *state)
{
	free_state(state);
	write(1, error, ft_strlen(error));
	return (0);
}

int	free_state(t_state *state)
{
	int	i;

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
	return (1);
}

int	parse_arguments(int argc, char **argv, t_state *state)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: bad arguments\n");
		return (0);
	}
	state->amount = ft_atoi(argv[1]);
	state->time_to_die = ft_atoi(argv[2]);
	state->time_to_eat = ft_atoi(argv[3]);
	state->time_to_sleep = ft_atoi(argv[4]);
	state->must_eat_count = 0;
	if (argc == 6)
		state->must_eat_count = ft_atoi(argv[5]);
	state->forks_mutex = NULL;
	state->philos = (t_philo *)malloc(sizeof(*(state->philos)) * state->amount);
	if (!state->philos)
		return (1);
	philos_initialize(state);
	return (initialize_mutex(state));
}

int	main(int argc, char **argv)
{
	t_state	state;

	if (parse_arguments(argc, argv, &state))
		error("error: fatal\n", &state);
	if (initialize_threads(&state))
		error("error: fatal\n", &state);
	pthread_mutex_lock(&state.somebody_dead_mutex);
	pthread_mutex_unlock(&state.somebody_dead_mutex);
	free_state(&state);
	return (0);
}
