#include "../include/philo.h"

static int	waiting_others(t_info *info)
{
	pthread_mutex_lock(&(info->waiting));
	pthread_mutex_unlock(&(info->waiting));
	if (info->retERR)
		return (0);
	return (1);
}

void	*routine(void *philo)
{
	t_info	*info;
	t_philo	*curr;

	curr = (t_philo *)philo;
	info = curr->info;
	if (!waiting_others(info))
		return (NULL);
	curr->check_last_eat_time = get_time();
	if (curr->my_seat % 2)
		usleep(10000);
	while (!info->finish && !info->eat_finish)
	{
		if (philo_state(info, curr))
			break ;
		print_state("is sleeping", info, curr->my_seat);
		check_time(info, 2);
		print_state("is thinking", info, curr->my_seat);
		usleep(100);
	}
	return (NULL);
}
