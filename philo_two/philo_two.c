/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:04:07 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/26 13:54:20 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error(char *error, t_state *state)
{
	free_state(state);
	write(1, error, ft_strlen(error));
	return (1);
}

int	print(t_philo *philo, char *message)
{
	static int	done = 0;
	int			ret;
	uint64_t	time;

	if (sem_wait(philo->state->write_mutex) != 0)
		return (1);
	ret = 1;
	if (!done)
	{
		time = gettime();
		ft_putnbr(time - philo->state->start);
		write(1, "\t", 1);
		ft_putnbr(philo->position + 1);
		write(1, " ", 1);
		write(1, message, ft_strlen(message));
		write (1, "\n", 1);
		if (ft_strncmp(message, "has died", ft_strlen("has died")) == 0)
			done = 1;
		ret = 0;
	}
	if (sem_post(philo->state->write_mutex))
		return (1);
	return (ret);
}

int	free_state(t_state *state)
{
	int		i;
	char	semaphore[255];

	sem_unlink("semaphoreFork");
	sem_unlink("semaphoreWrite");
	sem_unlink("semaphoreDead");
	if (state->philos)
	{
		i = 0;
		while (i < state->amount)
		{
			semaphore_name("semaphorePhilo", (char *)semaphore, i);
			sem_unlink(semaphore);
			semaphore_name("semaphorePhiloeat", (char *)semaphore, i++);
			sem_unlink(semaphore);
		}
		free(state->philos);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_state	state;

	if (argc < 5 || argc > 6)
		return (error("ERROR: BAD ARGUMENTS", &state));
	if (initialize(argc, argv, &state))
		return (error("ERROR: FATAL", &state));
	if (initialize_threads (&state))
		return (error("ERROR: FATAL", &state));
	sem_wait(state.somebody_dead_mutex);
	free_state(&state);
	return (0);
}
