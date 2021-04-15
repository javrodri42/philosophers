/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:28:22 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/15 12:11:23 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philos_initialize(t_state *state)
{
	char	semaphore[250];
	int		i;

	i = 0;
	while (i < state->amount)
	{
		state->philos[i].position = i;
		state->philos[i].eating = 0;
		state->philos[i].right_fork = (i + 1) % state->amount;
		state->philos[i].left_fork = i;
		state->philos[i].eat_count = 0;
		state->philos[i].state = state;
		semaphore_name("semphilo", (char *)semaphore, i);
		sem_unlink(semaphore);
		state->philos[i].mutex
			= sem_open("semaphore", O_CREAT | O_EXCL, 0644, 1);
		semaphore_name("semphiloeat", (char *)semaphore, i);
		sem_unlink(semaphore);
		state->philos[i].eat_count_mutex
			= sem_open("semaphore", O_CREAT | O_EXCL, 0644, 0);
		i++;
	}
	return (0);
}

int	initialize_semaphores(t_state *state)
{
	sem_unlink("semfork");
	state->forks_mutex
		= sem_open("semfork", O_CREAT, 0644, state->amount);
	if (state->forks_mutex < 0)
		return (1);
	sem_unlink("semwrite");
	state->write_mutex
		= sem_open("semwrite", O_CREAT, 0644, 1);
	if (state->write_mutex < 0)
		return (1);
	sem_unlink("semdead");
	state->somebody_dead_mutex
		= sem_open("semdead", O_CREAT, 0644, 0);
	if (state->somebody_dead_mutex < 0)
		return (1);
	return (0);
}

int	initialize_threads(t_state *state)
{
	int			i;
	pthread_t	thread_id;
	void		*philo;

	if (state->must_eat_count > 0)
	{
		if (pthread_create(&thread_id, NULL,
				&count_monitor, (void *)state) != 0)
			return (1);
		pthread_detach(thread_id);
	}
	state->start = gettime();
	i = 0;
	while (i < state->amount)
	{
		philo = (void *)(&state->philos[i]);
		if (pthread_create(&thread_id, NULL, &routine, philo) != 0)
			return (1);
		pthread_detach(thread_id);
		usleep(100);
		i++;
	}
	return (0);
}
