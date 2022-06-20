/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:23:54 by mkim2             #+#    #+#             */
/*   Updated: 2022/06/20 14:25:10 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	check_arg(int argc, char **argv)
{
	if (argc == 6)
		return (ft_atoi(argv[5]));
	return (0);
}

void	handle_argc(t_dining *dining, int argc, char **argv)
{
	dining->info = (t_info *)malloc(sizeof(t_info));
	if (!dining->info)
		print_err("initialize failed\n");
	dining->info->num_of_philo = ft_atoi(argv[1]);
	dining->info->time_to_die = ft_atoi(argv[2]);
	dining->info->time_to_eat = ft_atoi(argv[3]);
	dining->info->time_to_sleep = ft_atoi(argv[4]);
	dining->info->num_must_eat = check_arg(argc, argv);
	init_forks(dining);
	init_philo(dining);
}
