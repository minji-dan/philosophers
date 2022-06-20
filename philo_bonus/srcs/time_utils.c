/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:30:24 by mkim2             #+#    #+#             */
/*   Updated: 2022/06/20 14:32:58 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		ret;

	gettimeofday(&time, NULL);
	ret = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ret);
}

void	check_time(t_info *info, int mode)
{
	long long	duration;
	long long	time_start;
	long long	time_cur;

	duration = 0;
	if (mode == 1)
		duration = info->time_to_eat;
	else if (mode == 2)
		duration = info->time_to_sleep;
	time_start = get_time();
	while (1)
	{
		time_cur = get_time();
		if (time_cur - time_start >= duration)
			break ;
		usleep(750);
	}
}
