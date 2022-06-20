/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:44:29 by mkim2             #+#    #+#             */
/*   Updated: 2022/06/20 14:46:14 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	waiting_others(t_info *info)
{
	sem_wait(info->ready);
	sem_post(info->ready);
}

void	check_all_eat(t_info *info, t_philo *philo)
{
	if (info->num_must_eat && philo->eat_cnt
		>= info->num_must_eat && !philo->eat_finish)
	{
		sem_post(info->all_eat);
		philo->eat_finish = 1;
	}
}

void	routine(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	philo->time_check = get_time();
	pthread_create(&(philo->monitoring), NULL, philo_state, (void *)philo);
	waiting_others(info);
	if (philo->id % 2)
		usleep(10000);
	while (1)
	{
		eat_process(philo);
		check_all_eat(info, philo);
		philo_print("is sleeping", info, philo->id);
		check_time(info, 2);
		philo_print("is thinking", info, philo->id);
		usleep(100);
	}
}
