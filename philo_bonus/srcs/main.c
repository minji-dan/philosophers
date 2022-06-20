/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:39:42 by mkim2             #+#    #+#             */
/*   Updated: 2022/06/20 14:40:46 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_dining	dining;

	if (argc != 5 && argc != 6)
		print_err("Error\n");
	handle_argc(&dining, argc, argv);
	if (dining.info->num_of_philo < 1)
	{
		print_err("Error\n");
	}
	philos(&dining);
	return (0);
}
