/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:44:16 by mkim2             #+#    #+#             */
/*   Updated: 2022/05/08 14:45:59 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	eat_check(t_dining *dining)
{
	int	i;

	i = 0;
	if (dining->info.num_must_eat)
	{
		while (i < dining->info.num_of_philo && dining->philos[i].eat_time \
				>= dining->info.num_must_eat)
			i++;
		if (i == dining->info.num_of_philo)
			dining->info.eat_finish = 1;
	}
}

static void	monitoring(t_dining *dining)
{
	t_philo	*curr;
	int		i;

	usleep(1000);
	while (!dining->info.eat_finish)
	{
		i = 0;
		while (i < dining->info.num_of_philo && !(dining->info.finish))
		{
			pthread_mutex_lock(&(dining->info.eating));
			curr = &(dining->philos[i]);
			if (get_time() - curr->check_last_eat_time > \
					dining->info.time_to_die)
			{
				print_state("died", &dining->info, i);
				dining->info.finish = 1;
			}
			pthread_mutex_unlock(&(dining->info.eating));
			i++;
		}
		if (dining->info.finish)
			break ;
		eat_check(dining);
	}
}

static void	dest_philo(t_dining *dining, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		pthread_join(dining->philos[j].thread_id, NULL);
		j++;
	}
	j = 0;
	while (j < i)
		pthread_mutex_destroy(&(dining->info.fork_mu[j++]));
	pthread_mutex_destroy(&(dining->info.print));
	pthread_mutex_destroy(&(dining->info.eating));
	pthread_mutex_destroy(&(dining->info.waiting));
	free(dining->info.fork_mu);
	free(dining->info.forks_arr);
	free(dining->philos);
}

void	philos(t_dining *dining)
{
	int		i;
	void	*tmp;

	i = 0;
	pthread_mutex_lock(&(dining->info.waiting));
	while (i < dining->info.num_of_philo)
	{
		tmp = (void *)&dining->philos[i];
		if (pthread_create(&(dining->philos[i].thread_id), NULL, routine, tmp))
		{
			dining->info.ret_err = 1;
			print_err("creating thread error!\n");
			break ;
		}
		i++;
	}
	dining->info.start_time = get_time();
	pthread_mutex_unlock(&(dining->info.waiting));
	if (!dining->info.ret_err)
		monitoring(dining);
	dest_philo(dining, i);
}
