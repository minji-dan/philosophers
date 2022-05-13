/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:38:12 by mkim2             #+#    #+#             */
/*   Updated: 2022/05/08 14:43:08 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_input(const char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		return (0);
	if (*str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str)
		return (0);
	return (1);
}

static int	check_arg(int argc, char **argv, int *ret)
{
	int	tmp;

	if (argc == 6)
	{
		ft_atoi(argv[5], &tmp);
		if (tmp == 0)
			return (0);
		*ret = tmp;
		return (1);
	}
	*ret = 0;
	return (1);
}

static int	valid(t_info *info)
{
	if (info->num_of_philo < 1 || info->num_of_philo > 200)
		return (print_err("num_of_philo is error\n"));
	if (info->time_to_die == 0 || info->time_to_eat == 0
		|| info->time_to_sleep == 0)
		return (print_err("time error \n"));
	return (1);
}

int	handle_argc(t_dining *dining, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!check_input(argv[i]))
			return (print_err("Error\n"));
	}
	if (!ft_atoi(argv[1], &(dining->info.num_of_philo)) || !ft_atoi(argv[2], \
				&(dining->info.time_to_die)) || !ft_atoi(argv[3], \
				&(dining->info.time_to_eat)) || !ft_atoi(argv[4], \
				&(dining->info.time_to_sleep)) || !check_arg(argc, argv, \
				&(dining->info.num_must_eat)))
		return (print_err("Error\n"));
	dining->info.eat_finish = 0;
	dining->info.finish = 0;
	dining->info.ret_err = 0;
	return (valid(&dining->info));
}
