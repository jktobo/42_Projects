/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:29:49 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/05 20:35:18 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>


int print_message(t_philo *philo, char c)
{
    pthread_mutex_lock(&philo->test2->m_print);
    if (c == 'r')
        printf("%ld %d has taken a fork\n", print_get_time(philo), philo->id);
    else if (c == 'l')
        printf("%ld %d has taken a fork\n", print_get_time(philo), philo->id);
    else if (c == 'e')
    {
        printf("%ld %d is eating\n", print_get_time(philo), philo->id);
        philo->last_eat = get_time();
        if (philo->test2->opt_arg != -1)
        {
            philo->count_eat++;
            if (philo->count_eat == philo->test2->opt_arg)
			{
                philo->flag_opt = 1;
				printf("FF%d FLAG_OPT %d\n", philo->id, philo->test2->opt_arg);
			}
        }
    }
    else if (c == 's')
        printf("%ld %d is sleeping\n", print_get_time(philo), philo->id);
    else if (c == 't')
        printf("%ld %d is thinking\n", print_get_time(philo), philo->id);
    else if (c == 'd')
        printf("%ld %d died\n", print_get_time(philo), philo->id);
    pthread_mutex_unlock(&philo->test2->m_print);
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
        pthread_mutex_lock(&philo->test2->forks[philo->right_fork]);
        print_message(philo, 'r');
        pthread_mutex_lock(&philo->test2->forks[philo->left_fork]);
        if (check_died(philo) == 1)
            return (0);
        print_message(philo, 'l');
        print_message(philo, 'e');
        if (ft_my_sleep(philo, philo->test2->time_eat) == 1)
            return (0);
        pthread_mutex_unlock(&philo->test2->forks[philo->right_fork]);
        pthread_mutex_unlock(&philo->test2->forks[philo->left_fork]);
        if (check_died(philo) == 1)
            return (0);
        print_message(philo, 's');
        if (ft_my_sleep(philo, philo->test2->time_sleep) == 1)
            return (0);
        print_message(philo, 't');
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
        pthread_create(&rules.ph[i], NULL, &philo, &rules.philo[i]);
    while (1)
    {
        i = 0;
        while (rules.philo[i].flag_opt == 1)
        {
			printf("SF%d FLAG_OPT %d\n", rules.philo[i].id, rules.philo[i].flag_opt);
			// printf("OKKKK!\n");
        	i++;
        }
        if (rules.philosophers == i)
            rules.must_die = 1;
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
