#include "../include/philo.h"

static int	init_fork(t_info *info)
{
	int	i;
	int	num;

	num = info->num_of_philo;
	info->forks_arr = (int *)malloc(sizeof(int) * num);
	if (!info->forks_arr)
		return (0);
	i = -1;
	while (++i < num)
		info->forks_arr[i] = 0;
	info->fork_mu = (t_mutex *)malloc(sizeof(t_mutex) * num);
	if (!info->fork_mu)
		return (0);
	i = -1;
	while (++i < num)
	{
		if (pthread_mutex_init(&(info->fork_mu[i]), NULL))
			return (0);
	}
	return (1);
}

static int	init_mutex(t_info *info)
{
	if (pthread_mutex_init(&info->print, NULL) || pthread_mutex_init(&info->eating, NULL) ||
			pthread_mutex_init(&info->waiting, NULL) || !init_fork(info))
		return (0);
	return (1);
}

static int	init_philo(t_dining *dining)
{
	int i;

	dining->philos = malloc(sizeof(t_philo) * (dining->info.num_of_philo));
	if (!dining->philos)
		return (0);
	i = -1;
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

int	init(t_dining *dining)
{
	t_info	*info;

	info = &dining->info;
	dining->philos = NULL;
	info->fork_mu = NULL;
	info->forks_arr = NULL;
	if (!init_mutex(info))
		return (print_err("Error!\n"));
	if (!init_philo(dining))
		return (print_err("Error!\n"));
	return (1);
}
