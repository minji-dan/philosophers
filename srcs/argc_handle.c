#include "../include/philo.h"

int check_input(const char *str) //atoi하기 전에 검증
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

//모든 철학자가 인자만큼 식사하고 종료됨. 마지막이 3이라고하면 모든 철학자가 식사 세번하면 끝
static int check_arg(int argc, char **argv, int *ret) 
{
    int tmp;

    if (argc == 6) //실행인자가 6개일때만 실행해야함
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

static int valid(t_info *info)
{
    if (info->num_of_philo < 1 || info->num_of_philo > 200)
        return (print_err("num_of_philo is error\n"));
    if (info->time_to_die == 0 || info->time_to_eat == 0 || info->time_to_sleep == 0)
        return (print_err("time error \n"));
    return (1);
}

int handle_argc(t_dining *dining, int argc, char **argv)
{
    int i;

    i = 0;
    while (++i < argc)
    {
        if (!check_input(argv[i]))
            return (print_err("Error\n"));
    }
    if (!ft_atoi(argv[1], &(dining->info.num_of_philo)) \ //철학자 수
    || !ft_atoi(argv[2], &(dining->info.time_to_die)) ||   //수명 
        !ft_atoi(argv[3], &(dining->info.time_to_eat)) //먹는시간
        || !ft_atoi(argv[4], &(dining->info.time_to_sleep)) \ //자는시간
    || !check_arg(argc, argv, &(dining->info.num_must_eat))) //[모든 철학자의 식사 수]
        return (print_err("Error\n"));
    dining->info.eat_finish = 0;
    dining->info.finish = 0;
    dining->info.restERR = 0;
    return (valid(int argc, char **argv, int *ret));
}