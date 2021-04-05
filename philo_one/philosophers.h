/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:57:51 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/05 14:40:33 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_philo
{
	int				position;
	int				eating;
	uint64_t		limit;
	uint64_t		last_eat;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_mutex;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	struct s_state	*state
}		t_philo;

typedef struct s_state
{
	int				amount;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				must_eat_count;
	t_philo			*philos;
	uint64_t		start;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	somebody_dead_mutex;
}					t_state;

int		main(int argc, char **argv);
int		error(char *error);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
int		parse_arguments(int argc, char **argv, t_state *state);
void	philos_initialize(t_state *state);
int		free_state(t_state *state);

#endif
