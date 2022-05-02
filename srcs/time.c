#include "../include/philo.h"

long long get_time(void)
{
    struct timeval time;
    long long ret;

    gettimeofday(&time, NULL);
    ret = time.tv_sec * 1000 + time.tv_usec / 1000;
    return (ret);
}

void check_time(t_info *info, int mode)
{
    long long start;
    long long curr;
    long long dur;
    long long tmp;

    if (mode == 1)
        dur = info->time_to_eat;
    else if (mode == 2)
        dur = info->time_to_sleep;
    tmp = dur * 1000 / 2;
    start = ft_get_time();
    while (!(info->finish))
    {
        curr = ft_get_time();
        if (dur <= (curr - start) || tmp == 1)
            return;
        usleep(tmp);
        tmp /= 2;
    }
}