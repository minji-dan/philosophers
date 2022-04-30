
#include "../include/philo.h"

static void table_status(t_dining *dining)
{
}

static void dest_philo(t_dining *dining, int i)
{
}

void philos(t_dining *dining)
{
    int i;
    void *tmp;

    i = 0;
    pthread_mutex_lock(&(dining->info.waiting));
    while (i < dining->info.num_of_philo)
    {
        tmp = (void *)&dining->philos[i];
        if (pthread_create(&(dining->philos[i].threadID), NULL, routine, tmp))
        {
            dining->info.retERR = 1;
            print_err("Error!\n");
            break;
        }
        i++;
    }
    dining->info.start_time = ft_get_time();
    pthread_mutex_unlock(&(dining->info.waiting));
    if (!dining->info.retERR)
        table_status(dining);
    dest_philo(dining, i);
}