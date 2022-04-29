#include "../include/philo.h"

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        ++i;
    return (i);
}

int print_err(const char *str)
{
    int ret;
    int len;

    ret = 0;
    len = 1;
    while (len - ret > 0)
    {
        len = ft_strlen(str);
        if (str)
            ret = write(2, str, len);
        if (ret == -1)
            break;
    }
    return (-1);
}