/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:40:58 by mkim2             #+#    #+#             */
/*   Updated: 2022/06/20 14:44:21 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	close_free(t_dining *dining)
{
	sem_close(dining->info->forks);
	sem_close(dining->info->print);
	sem_close(dining->info->eating);
	sem_close(dining->info->ready);
	sem_close(dining->info->all_eat);
	sem_close(dining->info->end);
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/eating");
	sem_unlink("/ready");
	sem_unlink("/all_eat");
	sem_unlink("/end");
	free(dining->philos);
	free(dining->info);
}

void	check_routine(void *table_copy)
{
	t_dining	*dining;
	int			i;

	dining = (t_dining *)table_copy;
	usleep(1000);
	i = 0;
	while (i < dining->info->num_of_philo)
	{
		sem_wait(dining->info->all_eat);
		i++;
	}
	sem_post(dining->info->end);
	sem_wait(dining->info->print);
	exit(1);
}

void	fork_monitoring(t_dining *dining)
{
	dining->info->check_pid = fork();
	if (dining->info->check_pid < 0)
		print_err("fork_failed\n");
	if (dining->info->check_pid == 0)
		check_routine(dining);
}

void	dest_philo(t_dining *dining)
{
	int	i;

	sem_wait(dining->info->end);
	i = 0;
	while (i < dining->info->num_of_philo)
	{
		kill(dining->philos[i].pid, SIGTERM);
		i++;
	}
	kill(dining->info->check_pid, SIGTERM);
	close_free(dining);
}

void	philos(t_dining *dining)
{
	int		i;
	t_philo	*philo;

	dining->info->start_time = get_time();
	philo = dining->philos;
	sem_wait(dining->info->ready);
	i = 0;
	while (i < dining->info->num_of_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
			print_err("fork Error\n");
		if (philo[i].pid == 0)
			routine(&philo[i]);
		i++;
	}
	sem_post(dining->info->ready);
	fork_monitoring(dining);
	dest_philo(dining);
}
