#include "../include/philo.h"

//포크를 들고 내려 놓을 때 mutex로 접근 제한
static void pickup_fork(t_info *info, int fork_num, int my_seat)
{
    pthread_mutex_lock(&(info->fork_mu[fork_num]));
    info->forks_arr[fork_num]++; // 포크 사용여부 나타냄
    print_state("has taken a fork", info, my_seat);
}

static void putdown_fork(t_info *info, int fork_num)
{
    info->forks_arr[fork_num]--; //포크 사용여부 나타냄
    pthread_mutex_unlock(&(info->fork_mu[fork_num]));
}

static void eating(t_info *info, t_philo *philo)
{
    pthread_mutex_lock(&(info->eating));
    print_state("is eating", info, philo->my_seat);
    philo->check_last_eat_time = get_time();
    pthread_mutex_unlock(&(info->eating));
    check_time(info, 1);
    philo->eat_time++;
}

/* pickup과 pickdown 사이에 monitoring */
//철학자들은 반드시 pick()과 putdown()연산을 순서대로 호출해야함
int philo_state(t_info *info, t_philo *philo)
{
    pickup_fork(info, philo->l_fork, philo->my_seat); //pickup left fork
    if (philo->r_fork == philo->l_fork)
    {
        putdown_fork(info, philo->l_fork);
        return (1);
    }
    pickup_fork(info, philo->r_fork, philo->my_seat); //pickup right fork
    eating(info, philo);                              //젓가락 두개를 다 잡을 수 있는지를 주변 철학자 상태로 파악 후
    // 내 양 옆의 철학자가 밥을 먹지 않고 내가 배고픈 상태면 나의 상태를 먹는 중으로 바꿀 수 있음
    //test가 끝나면 mutex lock을 풀고 0으로 만들어서 젓가락 반납
    //putdown에서는 내 상태를 다시 thinking으로 바꾸고
    //내가 젓가락을 점유하고있어서 다른 철학자들이 배고픈데 나를 기다리느라 못먹고 있는지 확인
    //즉, 젓가락을 내려놓을 때 주변 철학자들을 수행하게 할 수 있음
    putdown_fork(info, philo->l_fork); //putdown left fork
    putdown_fork(info, philo->r_fork); //putdown right fork
    if (info->eat_finish || info->finish)
        return (1);
    return (0);
}