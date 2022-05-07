#include "../include/philo.h"

int main(int argc, char **argv)
{
    t_dining dining;

    if (argc != 5 && argc != 6)
        return (print_err("Error\n"));
    handle_argc(&dining, argc, argv);
    if (!init(&dining))
    {
        free_all(&dining);
        return (-1);
    }
    philos(&dining);
    return (0);
}