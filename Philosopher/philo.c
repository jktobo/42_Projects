/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:29:49 by dkaratae          #+#    #+#             */
/*   Updated: 2023/02/26 21:03:14 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int mails = 0;
pthread_mutex_t  mutex;

void    ft_init_str(t_date *st, char **av, int ac)
{
    st->philosophers = ft_atoi(av[1]);
    st->time_die = ft_atoi(av[2]);
    st->time_eat = ft_atoi(av[3]);
    st->time_sleep = ft_atoi(av[4]);
    if (ac == 6)
        st->opt_arg = ft_atoi(av[5]);
    else
        st->opt_arg = -1;
}

// void    *philo(void *args)
// {
//     int *f = (int*)args;
//     int i = *f;
//     printf("Philo is eating %d\n", i);
//     printf("end!\n");
//     return (NULL);
// }
void    *philo()
{
    int i = -1;
    pthread_mutex_lock(&mutex);
    while (++i < 1000000)
        mails++;
    pthread_mutex_unlock(&mutex);
    return (NULL);
}

int main(int ac, char **av)
{
    int i;
    t_date *st;
    pthread_t *pt;
    pthread_mutex_init(&mutex, NULL);
    st = (t_date *)malloc(sizeof(t_date) + 1);
    i = 0;
    ft_checker(ac, av);
    ft_init_str(st, av, ac);
    pt = malloc(sizeof(pt) * st->philosophers);
    while (i < st->philosophers)
    {
        pthread_create(&pt[i], NULL, &philo, NULL) ;
        usleep(3);
        i++;
    }
    i = 0;
    while (i < st->philosophers)
    {
        pthread_join(pt[i], NULL);
        i++;
    }
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d\n", mails);
    return (0);
}


// +++++++++++++++++++++++++++++



// long    get_time(void)
// {
//     struct timeval  tp;
//     long            milliseconds;

//     gettimeofday(&tp, NULL);
//     milliseconds = tp.tv_sec * 1000;
//     milliseconds += tp.tv_usec / 1000;
//     return (milliseconds);
// }

// void ft_my_sleep(long ms)
// {
//     struct timeval  now;
//     long  start;

// ();
//     gettimeofday(&now, NULL);
//     while (get_time() - start < ms)
//     {
//         usleep(100);
//         gettimeofday(&now, NULL);
//     }
// }

// int main(void)
// {
//     long start_time;
		
//     start_time = get_time();

//     while (1)
//     {
//         printf("%ld\n", get_time() - start_time);
//         // usleep(200000);
//         ft_my_sleep(500);
//     }
// }
// ++++++++++++++++++++++++++++++++++++++++

// void ft_my_sleep(int ms)
// {
//     struct timeval  now;
//     struct timeval  start;
//     gettimeofday(&now, NULL);
//     gettimeofday(&start, NULL);
//     while ((((now.tv_sec - start.tv_sec) * 1000) + ((now.tv_usec - start.tv_usec) / 1000)) < ms)
//     {
//         usleep(100);
//         gettimeofday(&now, NULL);
//     }
// }


// long    get_time(void)
// {
//     struct timeval  tp;
//     long            milliseconds;

//     gettimeofday(&tp, NULL);
//     milliseconds = tp.tv_sec * 1000;
//     milliseconds += tp.tv_usec / 1000;
//     return (milliseconds);
// }

// int main(void)
// {
//     long start_time;
		
//     start_time = get_time();

//     while (1)
//     {
//         printf("%ld\n", get_time() - start_time);
//         // usleep(200000);
//         ft_my_sleep(500);
//     }
// }