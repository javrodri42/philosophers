/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:04:07 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/19 23:55:48 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error(char *error, t_state *state)
{
	free_state(state);
	write(1, error, ft_strlen(error));
	return (1);
}

int	print(t_philo *philo, char* message)
{
	if (sem_wait(philo->state->write_mutex) != 0)
		return (1);
	printf("%llu\t%i%s", gettime() - philo->state->start,
		philo->position + 1, message);
	if (message == " has died")
		return (0);
	if (sem_post(philo->state->write_mutex))
		return (1);
	return (0);
}

int	free_state(t_state *state)
{
  int	i;
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
		semaphore_name("semaphorePhiloeat", (char *)semaphore, i);
		sem_unlink(semaphore);
	}
	free(state->philos);
  }
  return (1);
}
int main(int argc, char **argv)
{
    t_state state;

    if (argc < 5 || argc > 6)
        return (error("ERROR: BAD ARGUMENTS", &state));
    if (initialize(&state, argc, argv))
        return (error("ERROR: FATAL", &state));
    if  (initialize_threads (&state))
        return (error("ERROR: FATAL", &state));
    sem_wait(state.somebody_dead_mutex);
    free_state(&state);
    return(0);
}
