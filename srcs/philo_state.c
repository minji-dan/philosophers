#include "../include/philo.h"

static void acq_fork(t_info *info, int fork_num, int my_seat
{
    pthread_mutex_lock(&(info->fork_mu[fork_num]));
    info->forks_arr[fork_num]++;
    /**/
}

static void put_fork(t_info *info, int fork_num)
{
    info->forks_arr[fork_num]--;
    pthread_mutex_unlock(&(info->fork_mu[fork_num]));
}

static void eating(t_info *info, t_philo *philo)
{
    pthread_mutex_lock(&(info->eating));
    /**/
    philo->check_last_eat_time = ft_get_time();
    pthread_mutex_unlcok(&(info->eating));
    /**/
    philo->eat_time++;
}

int philo_state(t_info *info, t_philo *philo)
{
    acq_fork(info, philo->l_fork, philo->my_seat);
    if (philo->r_fork == philo == philo->l_fork)
    {
        release_fork(info, philo->l_fork);
        return (1);
    }
    acq_fork(info, philo->r_fork, philo->my_seat);
    eating(info, philo);
    put_fork(info, philo->l_fork);
    put_fork(info, philo->r_fork);
    if (info->eat_finish || info->finish)
        return (1);
    return (0);
}