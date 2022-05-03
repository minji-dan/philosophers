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

    int num_of_philo; //철학자의 수, 즉 포크의 갯수
    int time_to_die; //1) 마지막 식사를 시작하고 n 밀리 초 안에 먹기 시작하지않거나 2) 시뮬레이션을 시작한 후 n 밀리 초 안에 먹기 시작하지 않으면 -> 죽음 
    int time_to_eat; //밀리세컨 단위. 철학자가 식사를 하는 시간. 이 시간동안 철학자는 포크 두 개를 들고 있다.
    int time_to_sleep; //밀리세컨 단위. 철학자가 자는 시간
    int num_must_eat; //optional. 모든 철학자가 n번을 다 먹으면 시뮬레이션 중지. 지정하지 않으면 simulation은 철학자가 죽었을 때만 중지 
    int eat_finish;

    int retERR;
    int *forks_arr; // 각 mutex의 상태값 저장.
    //fork 배열을 생성하여 하나의 포크당 뮤텍스를 생성함으로써 해당 철학자가 포크를 집었는지 확인 하는 변수 필요 없이 mutex 그 자체로 확인 가능  

    int finish;

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

static int init_mutex(t_info *info);
static int init_philo(t_dining *dining);
int init(t_dining *dining);

#endif