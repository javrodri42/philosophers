/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:04:07 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/19 14:16:09 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error(char *error, t_state *state)
{
	free_state(state);
	write(1, error, ft_strlen(error));
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
