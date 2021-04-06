#include "philosophers.h"

void    take_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->state->forks_mutex[philo->left_fork]);
    print(philo, "has taken a fork\n", 0);
    pthread_mutex_lock(&philo->state->forks_mutex[philo->right_fork]);
    print(philo, "has taken a fork\n", 0);
}

void    leave_forks(t_philo *philo)
{
    print(philo, " is sleeping\n", 0);
    pthread_mutex_unlock(&philo->state->forks_mutex[philo->left_fork]);
    pthread_mutex_unlock(&philo->state->forks_mutex[philo->right_fork]);
    usleep(philo->state->time_to_sleep);
}

void    eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex);
    philo->eating = 1;
    philo->last_eat = gettime();
    philo->limit = philo->last_eat + philo->state->time_to_die;
    print(philo, " is eating\n", 0);
    usleep(philo->state->time_to_eat * 1000);
    philo->eat_count++;
    philo->eating = 0;
    pthread_mutex_unlock(&philo->mutex);
    pthread_mutex_unlock(&philo->eat_mutex);
}
