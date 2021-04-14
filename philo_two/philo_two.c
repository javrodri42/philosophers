/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:45:05 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/14 14:16:59 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error(char *error, t_state *state)
{
	free_state(state);
	write(1, error, ft_strlen(error));
	return (1);
}

int	free_state(t_state *state)
{
	int		i;
	char	semaphore[255];

	sem_unlink("sem_fork");
	sem_unlink("sem_write");
	sem_unlink("sem_dead");
	if (state->philos)
	{
		i = 0;
		while (i < state->amount)
		{
			semaphore_name("sem_philo", (char *) semaphore, i);
			sem_unlink(semaphore);
			semaphore_name("sem_philoeat", (char *) semaphore, i);
			sem_unlink(semaphore);
		}
		free(state->philos);
	}
	return (1);
}

int	parse_arguments(int argc, char **argv, t_state *state)
{
	if (argc < 5 || argc > 6)
		return (error("Error: bad arguments -1\n", state));
	state->amount = ft_atoi(argv[1]);
	state->time_to_die = ft_atoi(argv[2]);
	state->time_to_eat = ft_atoi(argv[3]);
	state->time_to_sleep = ft_atoi(argv[4]);
	state->total_eat_count = 0;
	state->must_eat_count = 0;
	if (state->amount < 2 || state->amount > 200
		|| state->time_to_die < 60 || state->time_to_eat < 60
		|| state->time_to_sleep < 60 || state->must_eat_count < 0)
		return (error("Error: bad arguments -2\n", state));
	if (argc == 6)
		state->must_eat_count = ft_atoi(argv[5]);
	state->forks_mutex = NULL;
	state->philos = (t_philo *)malloc(sizeof(*(state->philos)) * state->amount);
	if (!state->philos)
		return (1);
	philos_initialize(state);
	return (initialize_semaphores(state));
}

int	main(int argc, char **argv)
{
	t_state	state;

	if (parse_arguments(argc, argv, &state))
		return (0);
	if (initialize_threads(&state))
		return (0);
	sem_wait(state.somebody_dead_mutex);
	free_state(&state);
	return (0);
}
