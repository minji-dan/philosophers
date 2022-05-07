#include "../include/philo.h"

int ft_isspace(char c)
{
    return ((9 <= c && c <= 13) || c == ' ');
}

int ft_isdigit(char c)
{
    return (('0' <= c && c <= '9'));
}

int ft_atoi(const char *str, int *ret)
{
    long long result;

    result = 0;
    while (ft_isspace(*str))
        str++;
    if (*str == '+')
        str++;
    while (ft_isdigit(*str))
    {
        result = result * 10 + (*str - '0');
        if (result > 2147483647)
            return (0);
        str++;
    }
    *ret = (int)result;
    return (1);
}

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        ++i;
    return (i);
}