/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:25:33 by mkim2             #+#    #+#             */
/*   Updated: 2022/05/08 14:32:37 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_thread;

typedef struct s_info
{
	t_mutex		*fork_mu;
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_must_eat;
	int			eat_finish;
	int			ret_err;
	int			*forks_arr;
	int			finish;
	long long	start_time;
	t_mutex		print;
	t_mutex		eating;
	t_mutex		waiting;
}	t_info;

typedef struct s_philo
{
	int			my_seat;
	int			l_fork;
	int			r_fork;
	int			eat_time;
	long long	check_last_eat_time;
	t_info		*info;
	t_thread	thread_id;
}	t_philo;

typedef struct s_dining
{
	t_philo	*philos;
	t_info	info;
}	t_dining;

int			check_input(const char *str);

int			handle_argc(t_dining *dining, int argc, char **argv);

int			init(t_dining *dining);

int			philo_state(t_info *info, t_philo *philo);

void		philos(t_dining *dining);

void		*routine(void *philo);

long long	get_time(void);
void		check_time(t_info *info, int mode);

int			ft_isspace(char c);
int			ft_isdigit(char c);
int			ft_atoi(const char *str, int *ret);
int			ft_strlen(const char *str);

void		free_all(t_dining *t_dining);
int			print_err(const char *str);
void		print_state(char *msg, t_info *info, int pid);

#endif
