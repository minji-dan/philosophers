#include "../include/philo.h"

static int init_mut(t_info *info)
{
}

static int init_philo(t_dining *dining)
{
    int i;

    dining->philos = malloc(sizeof(t_philo) * (dining->info.num_of_philo));
    if (!dining->philos)
        return (0);
    while (++i < dining->info.num_of_philo)
    {
        dining->philos[i].my_seat = i;
        dining->philos[i].l_fork = i;
        dining->philos[i].r_fork = (i + 1) % dining->info.num_of_philo;
        dining->philos[i].eat_time = 0;
        dining->philos[i].info = &dining->info;
        dining->philos[i].check_last_eat_time = 0;
    }
    return (1);
}

int init(t_dining *dining)
{
    t_info *info;

    info = &dining->info;
    dining->philos = NULL;
    info->fork_mu = NULL;
    info->forks_arr = NULL;
    if (!init_mut(info))
        return (print_err("Error!\n"));
    if (!init_philo(dining))
        return (print_err("Error!\n"));
    return (1);
}