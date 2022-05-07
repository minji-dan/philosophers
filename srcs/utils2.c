#include "../include/philo.h"

void	free_all(t_dining *t_dining)
{
	int i;

	i = -1;
	pthread_mutex_destroy(&t_dining->info.print);
	pthread_mutex_destroy(&t_dining->info.eating);
	pthread_mutex_destroy(&t_dining->info.waiting);
	if (t_dining->info.forks_arr)
		free(t_dining->info.forks_arr);
	if (t_dining->info.fork_mu)
	{
		while (++i < t_dining->info.num_of_philo)
			pthread_mutex_destroy(&(t_dining->info.fork_mu[i]));
		free(t_dining->info.fork_mu);
	}
	if (t_dining->philos)
		free(t_dining->philos);
}

int	print_err(const char *str)
{
	int ret;
	int len;

	ret = 0;
	len = 1;
	while (len - ret > 0)
	{
		len = ft_strlen(str);
		if (str)
			ret = write(2, str, len);
		if (ret == -1)
			break ;
	}
	return (0);
}

void	print_state(char *msg, t_info *info, int pid)
{
	pthread_mutex_lock(&(info->print));
	if (!(info->finish) && !(info->eat_finish))
	{
		printf("%lld ", get_time() - info->start_time);
		printf("%d ", pid + 1);
		printf("%s\n", msg);
	}
	pthread_mutex_unlock(&(info->print));
}
