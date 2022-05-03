
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

static void dest_philo(t_dining *dining, int i) //뮤텍스 객체 파괴 
{
    int j;

    j = 0;
    while (j < i)
    {
        pthread_join(dining->philos[j].threadID, NULL); //스레드 종료 대기
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
    pthread_mutex_lock(&(dining->info.waiting)); /* mutex lock */ 
    while (i < dining->info.num_of_philo)
    {
        tmp = (void *)&dining->philos[i]; //각각의 철학자가 1부터 num_of_philo 숫자 범위 중의 수를 부여받게 됨 
        if (pthread_create(&(dining->philos[i].threadID), NULL, routine, tmp)) /* 스레드 생성 */ 
        //routine : 루틴은 메인 스레드에서 모든 철학자를 생성하기 전까지 대기
        {
            dining->info.retERR = 1; /* 에러체크 */
            print_err("Error!\n"); //에러 출력 
            break;
        }
        i++;
    }
    dining->info.start_time = ft_get_time(); /* 시간 초기화 */ 
    pthread_mutex_unlock(&(dining->info.waiting)); /* mutex unlock */
    if (!dining->info.retERR)
        monitoring(dining);
    dest_philo(dining, i);
}