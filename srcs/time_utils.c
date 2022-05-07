#include "../include/philo.h"

long long get_time(void)
{
    struct timeval time;
    long long ret;

    gettimeofday(&time, NULL); //time과의 차이: 마이크로초 단위까지 알려줌
    ret = time.tv_sec * 1000 + time.tv_usec / 1000;
    return (ret);
}

void check_time(t_info *info, int mode)
{
    long long dur;
    long long start;
    long long curr;
    long long tmp;

    dur = 0;
    if (mode == 1)
        dur = info->time_to_eat;
    else if (mode == 2)
        dur = info->time_to_sleep;
    tmp = dur * 1000 / 2;
    start = get_time();
    while (!(info->finish))
    {
        curr = get_time();
        if (curr - start >= dur || tmp == 1)
            return;
        usleep(tmp);
        if (tmp > 500)
            tmp /= 2;
    }
}