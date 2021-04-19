/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:57:51 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/19 14:08:08 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdint.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_philo
{
	int				position;
	int				eating;
	uint64_t		limit;
	uint64_t		last_eat;
	int				left_fork;
	int				right_fork;
	struct s_state	*state;
	int				eat_count;
	sem_t			*mutex;
	sem_t			*eat_count_mutex;
}		t_philo;

typedef struct s_state
{
	int				amount;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				must_eat_count;
	int				total_eat_count;
	uint64_t		start;
	t_philo			*philos;
	sem_t			*forks_mutex;
	sem_t			*write_mutex;
	sem_t			*somebody_dead_mutex;
}					t_state;

int			main(int argc, char **argv);
int			error(char *error, t_state *state);
int			ft_strlen(char *str);
int			ft_atoi(const char *str);
int			parse_arguments(int argc, char **argv, t_state *state);
int			initialize_philos(t_state *state);
int			free_state(t_state *state);
int			initialize_threads(t_state *state);
uint64_t	gettime(void);
void		*dead_monitor(void *arg_philo);
void		*routine(void *arg_philo);
void		*count_monitor(void *arg_state);
int			initialize_semaphores(t_state *state);
void		take_forks(t_philo *philo);
void		leave_forks(t_philo *philo);
void		eat(t_philo *philo);
int			printing(t_philo *philo, char *str, int n);
int			ft_strcpy(char *dst, const char *src);
char		*semaphore_name(char const *src, char *dst, int pos);
sem_t		open_semaphore(char *name, int value);

#endif