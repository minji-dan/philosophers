
#include "../include/philo.h"

static void eat_check(t_dining *dining)
{
    int i;

    i = 0;
    if (dining->info.num_must_eat)
    {
        while (i < dining->info.num_of_philo && dining->philos[i].eat_time >= dining->info.num_must_eat)
            i++;
        if (i == dining->info.num_of_philo)
            dining->info.eat_finish = 1;
    }
}

static void monitoring(t_dining *dining)
{
    t_philo *curr;
    int i;

    usleep(1000);
    while (!dining->info.eat_finish)
    {
        i = 0;
        while (i < dining->info.num_of_philo && !(dining->info.num_must_eat))
        {
            pthread_mutex_lock(&(dining->info.eating));
            curr = &(dining->philos[i]);
            if (ft_get_time() - curr->check_last_eat_time > dining->info.time_to_die)
            {
                /* */
            }
            pthread_mutex_unlock(&(dining->info.eating));
            i++;
        }
        if (dining->info.finish)
            break;
        eat_check(dining);
    }
}

static void dest_philo(t_dining *dining, int i)
{
    int j;

    j = 0;
    while (j < i)
    {
        pthread_join(dining->philos[j].threadID, NULL);
        j++;
    }
    j = 0;
    while (j < i)
        pthread_mutex_destroy(&(dining->info.fork_mu[j++]));
    pthread_mutex_destroy(&(dining->info.print));
    pthread_mutex_destroy(&(dining->info.eating));
    pthread_mutex_destroy(&(dining->info.waiting));
    free(dining->info.fork_mu);
    free(dining->info.forks_arr);
    free(dining->philos);
}

void philos(t_dining *dining)
{
    int i;
    void *tmp;

    i = 0;
    pthread_mutex_lock(&(dining->info.waiting)); //이거 왜걸음?
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
    pthread_mutex_unlock(&(dining->info.waiting)); //이거 왜 걸음?
    if (!dining->info.retERR)
        monitoring(dining);
    dest_philo(dining, i);
}