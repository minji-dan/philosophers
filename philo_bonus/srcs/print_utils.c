/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:29:40 by mkim2             #+#    #+#             */
/*   Updated: 2022/06/20 14:30:10 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	philo_print(char *msg, t_info *info, int philo_id)
{
	sem_wait(info->print);
	printf("%lld ", get_time() - info->start_time);
	printf("%d ", philo_id + 1);
	printf("%s\n", msg);
	sem_post(info->print);
}

void	print_err(char *errmessage)
{
	write(STDERR_FILENO, errmessage, ft_strlen(errmessage));
	exit(0);
}
