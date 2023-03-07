/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:29:49 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/07 04:58:35 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>


void    t_printf(char *str, t_rules *rules, t_philo *philo)
{
    pthread_mutex_lock(&rules->m_print);
    printf("%ld %d %s\n", print_get_time(philo), philo->id, str);
    pthread_mutex_unlock(&rules->m_print);
}

int ft_print_eat(t_rules *rules, t_philo *philo)
{
    if (philo->left_fork == philo->right_fork)
        return (1);
    pthread_mutex_lock(&philo->st_rul->forks[philo->right_fork]);
    pthread_mutex_lock(&philo->st_rul->forks[philo->left_fork]);
    t_printf("has taken a fork", rules, philo);
    t_printf("has taken a fork", rules, philo);
    t_printf("is eating", rules, philo);
    pthread_mutex_lock(&rules->last_meal_mutex);
    philo->last_eat = get_time();
    pthread_mutex_unlock(&rules->last_meal_mutex);
    philo->count_eat++;
    pthread_mutex_unlock(&philo->st_rul->forks[philo->left_fork]);
    pthread_mutex_unlock(&philo->st_rul->forks[philo->right_fork]);
    return (0); 
}

int ft_print_sleep(t_rules *rules)
{
    t_printf("is sleeping", rules, rules->philo);
    ft_my_sleep(rules->philo, rules->time_sleep);
    return (0); 
}

int ft_print_think(t_rules *rules)
{
    t_printf("is thinking", rules, rules->philo);
    return (0); 
}

int ft_print_died(t_rules *rules)
{
    t_printf("died", rules, rules->philo);
    return (0); 
}

void    *philo(void *args)
{
    t_philo *philo = (t_philo *)args;

    if (philo->id % 2 == 0)
        usleep(50);
    while (1)
    {
        if (check_died(philo) == 1)
            return (0);
        while (ft_print_eat(philo->st_rul, philo) != 0)
        {
            if (check_died(philo) == 1)
                return (0);
            // usleep(100);
        }
        ft_print_eat(philo->st_rul, philo);

        // if (ft_my_sleep(philo, philo->st_rul->time_eat) == 1)
        //     return (0);
        
        if (check_died(philo) == 1)
            return (0);
        ft_print_sleep(philo->st_rul);
        // if (ft_my_sleep(philo, philo->st_rul->time_sleep) == 1)
        //     return (0);
        ft_print_think(philo->st_rul);

    }
    return (NULL);
}

int main(int ac, char **av)
{
    int i;
    t_rules rules;

    if (ft_checker(ac, av) == 1)
        return (0);
    init_rules(&rules, av, ac);
    init_philo(&rules);
    i = -1;
    while (++i < rules.philosophers)
        pthread_mutex_init(&rules.forks[i], NULL);
    rules.start_time = get_time();
    i = -1;
    while (++i < rules.philosophers)
    {   
        pthread_create(&rules.ph[i], NULL, &philo, &rules.philo[i]);
    
        // (rules.philo[i].last_eat) = get_time();
    }
    i = -1;
    while (++i < rules.philosophers)
		pthread_detach(rules.ph[i]);
    while (1)
    {
        // i = 0;
		// int	temp = 0;
        // while (i < rules.philosophers)
        // {
        //     if (rules.philo[i].count_eat >= rules.opt_arg + 1)
        //         temp++;
        //     i++;
        // }
        // if (temp == rules.philosophers)
        // {
		// 	break;
        // }
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
