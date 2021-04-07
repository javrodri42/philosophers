/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:28:22 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/07 12:08:51 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philos_initialize(t_state *state)
{
	int	i;

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

int	initialize_mutex(t_state *state)
{
	int	i;

	pthread_mutex_init(&state->write_mutex, NULL);
	pthread_mutex_init(&state->somebody_dead_mutex, NULL);
	pthread_mutex_lock(&state->somebody_dead_mutex);
	state->forks_mutex = (pthread_mutex_t *)
		malloc(sizeof(*(state->forks_mutex)) * state->amount);
	if (!state->forks_mutex)
		return (1);
	i = 0;
	while (i < state->amount)
		pthread_mutex_init(&state->forks_mutex[i++], NULL);
	return (0);
}

int	initialize_threads(t_state *state)
{
	int			i;
	pthread_t	thread_id;
	void		*philo;

	i = 0;
	printf("-----aqui-----\n");
	state->start = gettime();
	if (state->must_eat_count > 0)
	{
		if (pthread_create(&thread_id, NULL,
				&count_monitor, (void *)state) != 0)
			return (1);
		pthread_detach(thread_id);
	}
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
