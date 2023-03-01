/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:29:49 by dkaratae          #+#    #+#             */
/*   Updated: 2023/02/27 17:29:11 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t forks[NUM_FORKS];
pthread_t ph[NUM_PHILOSOPHERS];

void    ft_init_str(t_rules *st, char **av, int ac)
{
    int philos;

    philos = ft_atoi(av[1]);
    st->philosophers = ft_atoi(av[1]);
    st->time_die = ft_atoi(av[2]);
    st->time_eat = ft_atoi(av[3]);
    st->time_sleep = ft_atoi(av[4]);
    if (ac == 6)
        st->opt_arg = ft_atoi(av[5]);
    else
        st->opt_arg = -1;
    st->ph[philos];
    st->forks[];
}

void    *philo(void *args)
{
    int id = *(int*)args;
    int l_fork = id;
    int r_fork = (id + 1) % NUM_FORKS;

    while (1)
    {
        printf("Philo %d is thinking\n", id);

        pthread_mutex_lock(&forks[l_fork]);
        printf("Philo %d has taken a left fork %d\n", id, l_fork);
        pthread_mutex_lock(&forks[r_fork]);
        printf("Philo %d has taken a right fork %d\n", id, r_fork);
        pthread_mutex_unlock(&forks[r_fork]);        
        pthread_mutex_unlock(&forks[l_fork]);
        usleep(10000);
    }
    return (NULL);
}

int main(int ac, char **av)
{
    int i;
    t_rules *rules = NULL;

    ft_checker(ac, av);
    ft_init_str(rules, av, ac);
    i = -1;
    while (++i < rules->philosophers)
        pthread_mutex_init(&forks[i], NULL);
    i = -1;
    while (++i < rules->philosophers)
    {
        pthread_create(&ph[i], NULL, &philo, &i);
    }
    i = -1;
    while (++i < rules->philosophers)
    {
        pthread_join(ph[i], NULL);
    }
    i = -1;
    while (++i < rules->philosophers)
        pthread_mutex_destroy(&forks[i]);
    return (0);
}
// int main(int ac, char **av)
// {
//     int i;
//     // t_philo *st = NULL;
//     t_rules *rules = NULL;
//     pthread_t pt[ft_atoi(av[1])];

//     ft_checker(ac, av);
//     rules = malloc(sizeof(t_rules) * ft_atoi(av[1]));
//     ft_init_str(rules, av, ac);
//     i = -1;
//     while (++i < ft_atoi(av[1]))
//     {
//         pthread_create(&pt[i], NULL, &philo, &i) ;
//     }
//     i = -1;
//     while (++i < ft_atoi(av[1]))
//     {
//         pthread_join(pt[i], NULL);
//     }
//     // pthread_mutex_destroy(&mutex);
//     return (0);
// }


