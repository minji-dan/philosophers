#include "../include/philo.h"

void free_all(t_dining *t_dining)
{
    int i;

    i = -1;
    pthread_mutex_destroy(&t_dining->info.print);
    pthread_mutex_destroy(&t_dining->info.eating);
    pthread_mutex_destroy(&t_dining->info.waiting);
    if (t_dining->info.forks_arr)
        free(t_dining->info.forks_arr);
    if (t_dining->info.fork_mu)
    {
        while (++i < t_dining->info.num_of_philo)
            pthread_mutex_destroy(&(t_dining->info.fork_mu[i]));
        free(t_dining->info.fork_mu);
    }
    if (t_dining->philos)
        free(t_dining->philos);
}
