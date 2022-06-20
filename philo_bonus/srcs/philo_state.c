/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:27:13 by mkim2             #+#    #+#             */
/*   Updated: 2022/06/20 14:29:29 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	eat_process(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	sem_wait(info->forks);
	philo_print("has taken a fork", info, philo->id);
	sem_wait(info->forks);
	philo_print("has taken a fork", info, philo->id);
	sem_wait(info->eating);
	philo_print("is eating", info, philo->id);
	philo->time_check = get_time();
	sem_post(info->eating);
	check_time(info, 1);
	philo->eat_cnt++;
	sem_post(info->forks);
	sem_post(info->forks);
}

void	*philo_state(void *temp)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)temp;
	info = philo->info;
	while (1)
	{
		sem_wait(info->eating);
		if (get_time() - philo->time_check > info->time_to_die)
		{
			sem_wait(info->print);
			printf("%lld ", get_time() - info->start_time);
			printf("%d ", philo->id + 1);
			printf("died\n");
			sem_post(info->end);
			exit(1);
		}
		sem_post(info->eating);
		usleep(100);
	}
}
