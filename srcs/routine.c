#include "../include/philo.h"

static int wating_others(t_info *info)
{
    pthread_mutex_lock(&(info->waiting));
    pthread_mutex_unlock(&(info->waiting));
    if (info->retERR)
        return (0); //return error 
    return (1);
}

void *routine(void *philo)
{
    t_info *info;
    t_philo *curr;

    curr = (t_philo *)philo;
    info = curr->info;
    if (!waiting_others(info))
        return (NULL);
    curr->check_last_eat_time = ft_get_time();
    if (curr->my_seat % 2)
        usleep(10000);
    while (!info->finish && !info->eat_finish)
    {
        /**/
    }
    return (NULL);
}