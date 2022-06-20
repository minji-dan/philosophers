/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:37:23 by mkim2             #+#    #+#             */
/*   Updated: 2022/06/20 14:38:38 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	init_philo(t_dining *dining)
{
	int	i;

	dining->philos = malloc(sizeof(t_philo) * (dining->info->num_of_philo + 1));
	if (!dining->philos)
		print_err("malloc philo failed");
	i = 0;
	while (i < dining->info->num_of_philo)
	{
		dining->philos[i].id = i;
		dining->philos[i].eat_cnt = 0;
		dining->philos[i].info = dining->info;
		dining->philos[i].time_check = 0;
		dining->philos[i].eat_finish = 0;
		i++;
	}
}

void	init_forks(t_dining *dining)
{
	t_info	*info;

	info = dining->info;
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/eating");
	sem_unlink("/ready");
	sem_unlink("/all_eat");
	sem_unlink("/end");
	info->forks = sem_open("/forks", O_CREAT, 0644, info->num_of_philo);
	info->print = sem_open("/print", O_CREAT, 0644, 1);
	info->eating = sem_open("/eating", O_CREAT, 0644, 1);
	info->ready = sem_open("/ready", O_CREAT, 0644, 1);
	info->all_eat = sem_open("/all_eat", O_CREAT, 0644, 0);
	info->end = sem_open("/end", O_CREAT, 0644, 0);
	if (info->forks == NULL || info->print == NULL || info->eating == NULL
		|| info->ready == NULL || info->all_eat == NULL)
		print_err("Error\n");
}

void	init_info(t_dining *dining, int argc, char **argv)
{
	dining->info = (t_info *)malloc(sizeof(t_info));
	if (!dining->info)
		print_err("Error\n");
	dining->info->num_of_philo = ft_atoi(argv[1]);
	dining->info->time_to_die = ft_atoi(argv[2]);
	dining->info->time_to_eat = ft_atoi(argv[3]);
	dining->info->time_to_sleep = ft_atoi(argv[4]);
	dining->info->num_must_eat = check_arg(argc, argv);
	init_forks(dining);
	init_philo(dining);
}
