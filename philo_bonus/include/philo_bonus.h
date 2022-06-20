/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:16:39 by mkim2             #+#    #+#             */
/*   Updated: 2022/06/20 14:23:44 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef pthread_t	t_thread;

typedef struct s_info
{
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_must_eat;
	long long	start_time;
	pid_t		check_pid;
	sem_t		*forks;
	sem_t		*print;
	sem_t		*eating;
	sem_t		*all_eat;
	sem_t		*ready;
	sem_t		*end;
}	t_info;

typedef struct s_philo
{
	int			id;
	int			eat_cnt;
	int			eat_finish;
	long long	time_check;
	t_thread	monitoring;
	t_info		*info;
	pid_t		pid;
}	t_philo;

typedef struct s_dining
{
	t_philo	*philos;
	t_info	*info;
}	t_dining;

int			check_arg(int argc, char **argv);
void		handle_argc(t_dining *dining, int argc, char **argv);

void		init_philo(t_dining *dining);
void		init_forks(t_dining *dining);
void		init_info(t_dining *dining, int argc, char **argv);

int			main(int argc, char **argv);

void		eat_process(t_philo *philo);
void		*philo_state(void *temp);

void		check_routine(void *table_copy);
void		fork_monitoring(t_dining *dining);
void		dest_philo(t_dining *dining);
void		philos(t_dining *dining);

void		philo_print(char *msg, t_info *info, int philo_id);
void		print_err(char *errmessage);

void		waiting_others(t_info *info);
void		check_all_eat(t_info *info, t_philo *philo);
void		routine(t_philo *philo);

long long	get_time(void);
void		check_time(t_info *info, int mode);

int			ft_atoi(const char *str);
int			ft_strlen(char *s);

#endif
