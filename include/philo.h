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
} t_philo;

typedef struct s_info
{
    pthread_mutex_t *fork_mu;

    int num_of_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_must_eat;

    long long cur_time;
    long long start_time;

    t_philo *philos;

    pthread_mutex_t print;
    pthread_mutex_t eating;
} t_info;

typedef struct s_table
{
    t_philo *philos;
    t_info info;
} t_table;

#endif