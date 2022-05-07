#include "../include/philo.h"

static void	pickup_fork(t_info *info, int fork_num, int my_seat)
{
	pthread_mutex_lock(&(info->fork_mu[fork_num]));
	info->forks_arr[fork_num]++;
	print_state("has taken a fork", info, my_seat);
}

static void	putdown_fork(t_info *info, int fork_num)
{
	info->forks_arr[fork_num]--;
	pthread_mutex_unlock(&(info->fork_mu[fork_num]));
}

static void	eating(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(info->eating));
	print_state("is eating", info, philo->my_seat);
	philo->check_last_eat_time = get_time();
	pthread_mutex_unlock(&(info->eating));
	check_time(info, 1);
	philo->eat_time++;
}

int	philo_state(t_info *info, t_philo *philo)
{
	pickup_fork(info, philo->l_fork, philo->my_seat);
	if (philo->r_fork == philo->l_fork)
	{
		putdown_fork(info, philo->l_fork);
		return (1);
	}
	pickup_fork(info, philo->r_fork, philo->my_seat);
	eating(info, philo);
	putdown_fork(info, philo->l_fork);
	putdown_fork(info, philo->r_fork);
	if (info->eat_finish || info->finish)
		return (1);
	return (0);
}
