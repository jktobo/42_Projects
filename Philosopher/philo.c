/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:29:49 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/01 15:46:59 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>

// pthread_mutex_t forks[NUM_FORKS];
// pthread_t ph[NUM_PHILOSOPHERS];

void    ft_init_str(t_rules *st, char **av, int ac)
{
    // ft_memset(&st, 0, sizeof(t_rules));
    st->philosophers = ft_atoi(av[1]);
    st->time_die = ft_atoi(av[2]);
    st->time_eat = ft_atoi(av[3]);
    st->time_sleep = ft_atoi(av[4]);
    if (ac == 6)
        st->opt_arg = ft_atoi(av[5]);
    else
        st->opt_arg = -1;

}

void    *philo(void *args)
{
    t_philo philo = *(t_philo*)args;
    philo.right_fork = philo.id;
    philo.left_fork = (philo.id + 1) % philo.test2->philosophers;

    while (1)
    {
        pthread_mutex_lock(&philo.test2->forks[philo.right_fork]);
        printf("%ld %d has taken a fork\n", print_get_time(&philo), philo.id);
        pthread_mutex_lock(&philo.test2->forks[philo.left_fork]);
        printf("%ld %d has taken a fork\n", print_get_time(&philo), philo.id);
        printf("%ld %d is eating\n", print_get_time(&philo), philo.id);
        ft_my_sleep(philo.test2->time_eat);
        pthread_mutex_unlock(&philo.test2->forks[philo.right_fork]);
        pthread_mutex_unlock(&philo.test2->forks[philo.left_fork]);
        printf("%ld %d is sleeping\n", print_get_time(&philo), philo.id);
        ft_my_sleep(philo.test2->time_sleep);
        printf("%ld %d is thinking\n", print_get_time(&philo), philo.id);
    }
    return (NULL);
}

void *ft_memset(void *s, int c, size_t n)
{
    size_t i;
    unsigned char *p;
    unsigned char ch;

    i = -1;
    p = s;
    ch = c;
    while (++i < n)
        p[i] = ch;
    return (s);
}

int main(int ac, char **av)
{
    int i;
    t_rules rules;

    ft_memset(&rules, 0, sizeof(t_rules));
    ft_checker(ac, av);
    ft_init_str(&rules, av, ac);
    rules.start_time = get_time();
    rules.ph = calloc(sizeof(pthread_t), rules.philosophers + 1);
    rules.forks = calloc(sizeof(pthread_mutex_t), rules.philosophers + 1);
    rules.philo = calloc(sizeof(t_philo), rules.philosophers + 1);
    i = -1;
    while (++i < rules.philosophers)
        pthread_mutex_init(&rules.forks[i], NULL);
    
    i = -1;
    while (++i < rules.philosophers) {
        rules.philo[i].id = i;
        rules.philo[i].test2 = &rules;
        pthread_create(&rules.ph[i], NULL, &philo, &rules.philo[i]);
    }
    i = -1;
    while (++i < rules.philosophers)
        pthread_join(rules.ph[i], NULL);
    i = -1;
    while (++i < rules.philosophers)
        pthread_mutex_destroy(&rules.forks[i]);
    return (0);
}

// FORK STATE
// { 0, 0, 0, 0, 0 }

// MUTEX_LOCK
// UPDATE
// { 1, 1, 0, 0, 0 }
// UNLOCK

// if 2 checks

