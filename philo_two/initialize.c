/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:36:26 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/26 14:06:08 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	initialize(int argc, char **argv, t_state *state)
{
	state->amount = ft_atoi(argv[1]);
	state->time_to_die = ft_atoi(argv[2]);
	state->time_to_eat = ft_atoi(argv[3]);
	state->time_to_sleep = ft_atoi(argv[4]);
	state->must_eat_count = 0;
	if (argc == 6)
		state->must_eat_count = ft_atoi(argv[5]);
	if (state->amount < 2
		|| state->amount > 200
		|| state->time_to_die < 60
		|| state->time_to_sleep < 60
		|| state->time_to_eat < 60
		|| state->must_eat_count < 0)
		return (1);
	state->total_eat_count = 0;
	state->forks_mutex = NULL;
	state->philos
		= (t_philo *)malloc(sizeof(*(state->philos)) * state->amount);
	if (!(state->philos))
		return (1);
	if (initialize_philos(state))
		return (1);
	return (initialize_semaphores(state));
}

int	initialize_philos(t_state *state)
{
	int		i;
	char	semaphore[250];

	i = 0;
	while (i < state->amount)
	{
		state->philos[i].eating = 0;
		state->philos[i].position = i;
		state->philos[i].left_fork = i;
		state->philos[i].right_fork = (i + 1) % state->amount;
		state->philos[i].eat_count = 0;
		state->philos[i].state = state;
		semaphore_name("semaphorePhilo", (char *)semaphore, i);
		state->philos[i].mutex = open_semaphore(semaphore, 1);
		if (state->philos[i].mutex < 0)
			return (1);
		semaphore_name("semaphorePhiloeat", (char *)semaphore, i);
		state->philos[i].eat_count_mutex = open_semaphore(semaphore, 0);
		if (state->philos[i].eat_count_mutex < 0)
			return (1);
		i++;
	}
	return (0);
}

int	initialize_semaphores(t_state *state)
{
	state->forks_mutex = open_semaphore("semaphoreFork", state->amount);
	if (state->forks_mutex < 0)
		return (1);
	state->write_mutex = open_semaphore("semaphoreWrite", 1);
	if (state->write_mutex < 0)
		return (1);
	state->somebody_dead_mutex = open_semaphore("semaphoreDead", 0);
	if (state->somebody_dead_mutex < 0)
		return (1);
	return (0);
}

int	initialize_threads(t_state *state)
{
	int			i;
	pthread_t	id;
	void		*philo;

	if (state->must_eat_count > 0)
	{
		if (pthread_create(&id, NULL, &count_monitor, (void *)state) != 0)
			return (1);
		pthread_detach(id);
	}
	state->start = gettime();
	i = 0;
	while (i < state->amount)
	{
		philo = (void *)(&state->philos[i]);
		if (pthread_create(&id, NULL, &routine, philo) != 0)
			return (1);
		pthread_detach(id);
		usleep(100);
		i++;
	}
	return (0);
}
