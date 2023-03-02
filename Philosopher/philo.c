/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:29:49 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/02 21:32:28 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>

void    ft_init_str(t_rules *st, char **av, int ac)
{
    st->philosophers = ft_atoi(av[1]);
    st->time_die = ft_atoi(av[2]);
    st->time_eat = ft_atoi(av[3]);
    st->time_sleep = ft_atoi(av[4]);
    if (ac == 6)
        st->opt_arg = ft_atoi(av[5]);
    else
        st->opt_arg = -1;
    pthread_mutex_init(&st->print, NULL);
    st->count_eat = 0;
    st->last_eat = 0;
    st->must_die = 0;
}

int print_message(t_philo *philo, char c)
{
    pthread_mutex_lock(&philo->test2->print);
    if (c == 'r')
        printf("%ld %d has taken a fork\n", print_get_time(philo), philo->id);
    else if (c == 'l')
        printf("%ld %d has taken a fork\n", print_get_time(philo), philo->id);
    else if (c == 'e')
    {
        printf("%ld %d is eating\n", print_get_time(philo), philo->id);
        philo->test2->last_eat = get_time();
        printf("%d - TIME = %ld\n", philo->id, philo->test2->last_eat);
        philo->test2->count_eat++;
    }
    else if (c == 's')
    {
        printf("%ld %d is sleeping\n", print_get_time(philo), philo->id);
    }
    else if (c == 't')
        printf("%ld %d is thinking\n", print_get_time(philo), philo->id);
    pthread_mutex_unlock(&philo->test2->print);
    return (0);
}

void    *philo(void *args)
{
    t_philo philo = *(t_philo*)args;
    philo.right_fork = philo.id;
    philo.left_fork = (philo.id + 1) % philo.test2->philosophers;

    // if (philo.id % 2 == 0)
    //     ft_my_sleep(25);
    while (1)
    {
        pthread_mutex_lock(&philo.test2->forks[philo.right_fork]);
        print_message(&philo, 'r');
        pthread_mutex_lock(&philo.test2->forks[philo.left_fork]);
        
        print_message(&philo, 'l');
        print_message(&philo, 'e');
        ft_my_sleep(philo.test2->time_eat);
        
        pthread_mutex_unlock(&philo.test2->forks[philo.right_fork]);
        pthread_mutex_unlock(&philo.test2->forks[philo.left_fork]);

        print_message(&philo, 's');
        ft_my_sleep(philo.test2->time_sleep);
        print_message(&philo, 't');
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

int is_died(t_rules *rules)
{
    int i;
    
    i = 0;
    while (rules->philo)
    {
        long sum;

        sum = rules->last_eat - get_time();
        if (sum > rules->time_die)
            return (1);
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    int i;
    t_rules rules;

    ft_memset(&rules, 0, sizeof(t_rules));
    ft_checker(ac, av);
    ft_init_str(&rules, av, ac);
    rules.ph = calloc(sizeof(pthread_t), rules.philosophers + 1);
    rules.forks = calloc(sizeof(pthread_mutex_t), rules.philosophers + 1);
    rules.philo = calloc(sizeof(t_philo), rules.philosophers + 1);
    i = -1;
    while (++i < rules.philosophers)
        pthread_mutex_init(&rules.forks[i], NULL);
    
    i = -1;
    rules.start_time = get_time();
    while (++i < rules.philosophers) {
        rules.philo[i].id = i;
        rules.philo[i].test2 = &rules;
        pthread_create(&rules.ph[i], NULL, &philo, &rules.philo[i]);
    }
    while (1)
    {
        if (is_died(&rules) == 1)
        {
            rules.must_die = 1;
            i = -1;
            while (++i < rules.philosophers)
                pthread_join(rules.ph[i], NULL);
            break;
        }
    }
    
    i = -1;
    while (++i < rules.philosophers)
        pthread_mutex_destroy(&rules.forks[i]);
    return (0);
}
