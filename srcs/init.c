#include "../include/philo.h"

static int init_mut(t_info *info)
{
}

static int init_philo(t_dining *dining)
{
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