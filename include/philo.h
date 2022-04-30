#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef pthread_mutex_t t_mutex;
typedef pthread_t t_thread;

typedef struct s_philo
{
    int my_seat;
    int l_fork;
    int r_fork;
    int eat_time;
    long long check_last_eat_time;

    t_info *info;
    t_thread threadID;
} t_philo;

typedef struct s_info
{
    t_mutex *fork_mu;

    int num_of_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_must_eat;

    int retERR;
    int *forks_arr;

    long long cur_time;
    long long start_time;

    t_philo *philos;

    t_mutex print;
    t_mutex eating;
    t_mutex waiting;
} t_info;

typedef struct s_dining
{
    t_philo *philos;
    t_info info;
} t_dining;

int ft_isspace(char c);
int ft_isdigit(char c);
int ft_atoi(const char *str, int *ret);
int ft_strlen(const char *str);
int print_err(const char *str);

int check_input(const char *str);
static int check_arg(int argc, char **argv, int *ret);
int handle_argc(t_dining *dining, int argc, char **argv);

#endif