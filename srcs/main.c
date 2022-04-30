#include "../include/philo.h"

int main(int argc, char **argv)
{
    t_dining dining;

    if (argc != 5 && argc != 6)
        return (print_err("Error\n"));
    handle_argc(&dining, argc, argv);
    if (!init(&dining))
    {
    }
    philo(&dining);
    return (0);
}