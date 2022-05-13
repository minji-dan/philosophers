/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:43:47 by mkim2             #+#    #+#             */
/*   Updated: 2022/05/08 14:44:00 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_dining	dining;

	if (argc != 5 && argc != 6)
		return (print_err("Error\n"));
	handle_argc(&dining, argc, argv);
	if (!init(&dining))
	{
		free_all(&dining);
		return (-1);
	}
	philos(&dining);
	return (0);
}
