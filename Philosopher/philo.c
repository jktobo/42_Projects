/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:29:49 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/07 20:54:46 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>

void    t_printf(char *str, t_rules *rules, t_philo *philo)
{
    pthread_mutex_lock(&rules->m_print);
    printf("%ld %d %s\n", print_get_time(philo), philo->id + 1, str);
    pthread_mutex_unlock(&rules->m_print);
}

int ft_print_eat(t_rules *rules, t_philo *philo)
{
    if (philo->left_fork == philo->right_fork)
        return (1);
    pthread_mutex_lock(&rules->m_forks[philo->right_fork]);
    t_printf("has taken a fork", rules, philo);
    pthread_mutex_lock(&rules->m_forks[philo->left_fork]);
    t_printf("has taken a fork", rules, philo);
    t_printf("is eating", rules, philo);
    return (0); 
}

int ft_print_sleep(t_rules *rules, t_philo *philo)
{
    t_printf("is sleeping", rules, philo);
    return (0); 
}

int ft_print_think(t_rules *rules, t_philo *philo)
{
    t_printf("is thinking", rules, philo);
    if (check_died(philo) == 1)
            return (0);
    return (0); 
}

int ft_print_died(t_rules *rules, t_philo *philo)
{
    t_printf("died", rules, philo);
    return (0); 
}

void    *philo(void *args)
{
    t_philo *philo = (t_philo *)args;

    if (philo->id % 2 == 0)
        usleep(100);
    while (1)
    {
        if (check_died(philo) == 1)
            return (0);
        ft_print_eat(philo->st_rul, philo);
        if (ft_my_sleep(philo, philo->st_rul->time_eat) == 1)
            return (0);
        pthread_mutex_lock(&philo->st_rul->m_count);
        philo->last_eat = get_time();
        philo->count_eat++;
        pthread_mutex_unlock(&philo->st_rul->m_count);
        pthread_mutex_unlock(&philo->st_rul->m_forks[philo->left_fork]);
        if (check_died(philo) == 1)
            return (0);
        pthread_mutex_unlock(&philo->st_rul->m_forks[philo->right_fork]);
        if (check_died(philo) == 1)
            return (0);
        ft_print_sleep(philo->st_rul, philo);
        if (ft_my_sleep(philo, philo->st_rul->time_sleep) == 1)
            return (0);
        if (check_died(philo) == 1)
            return (0);
        ft_print_think(philo->st_rul, philo);
    }
    return (NULL);
}


int main(int ac, char **av)
{
    int i;
    int check_res;
    t_rules rules;
    int join_flag;

    join_flag = 0;
    if (ft_checker(ac, av) == 1)
        return (0);
    init_rules(&rules, av, ac);
    init_philo(&rules);
    i = -1;
    while (++i < rules.philosophers)
        pthread_mutex_init(&rules.m_forks[i], NULL);
    rules.start_time = get_time();
    i = -1;
    while (++i < rules.philosophers)
        pthread_create(&rules.ph[i], NULL, &philo, &rules.philo[i]);  
    while (1)
    {
        check_res = is_died(&rules);
        if (check_res == 1)
        {
            rules.must_die = 1;
            break;
        }
        if (check_res == 2)
            break;
        if (join_flag == 0)
        {
            i = -1;
            while (++i < rules.philosophers)
                pthread_join(rules.ph[i], NULL);
            join_flag = 1;
        }
    }
    i = -1;
    while (++i < rules.philosophers)
        pthread_mutex_destroy(&rules.m_forks[i]);
    return (0);
}
