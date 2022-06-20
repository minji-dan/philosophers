/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:46:20 by mkim2             #+#    #+#             */
/*   Updated: 2022/06/20 14:47:24 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static int	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == ' ');
}

static int	ft_isdigit(char c)
{
	return (('0' <= c && c <= '9'));
}

static void	check_input(const char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		print_err("arguments error\n");
	if (*str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str)
		print_err("arguments error\n");
}

int	ft_atoi(const char *str)
{
	long long	result;

	result = 0;
	check_input(str);
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		if (result > 2147483647)
			print_err("arguments error\n");
		str++;
	}
	return (result);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}
