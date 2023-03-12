/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:29:49 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/09 20:15:52 by dkaratae         ###   ########.fr       */
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

// int ft_print_eat(t_rules *rules, t_philo *philo)
// {
//     if (philo->left_fork == philo->right_fork)
//         return (1);
//     pthread_mutex_lock(&rules->m_forks[philo->right_fork]);
//     t_printf("has taken a fork", rules, philo);
//     pthread_mutex_lock(&rules->m_forks[philo->left_fork]);
//     t_printf("has taken a fork", rules, philo);
//     t_printf("is eating", rules, philo);
//     return (0); 
// }

int ft_print_sleep(t_rules *rules, t_philo *philo)
{
	t_printf(" is sleeping", rules, philo);
	if (ft_my_sleep(philo, rules->time_sleep) == 1)
		return (1);
	return (0); 
}

int ft_print_think(t_rules *rules, t_philo *philo)
{
	t_printf("is thinking", rules, philo);
	return (0); 
}

int ft_print_died(t_rules *rules, t_philo *philo)
{
    t_printf("died", rules, philo);
    return (0); 
}

int philo_eats(t_rules *rules, t_philo *philo)
{
	if (philo->left_fork == philo->right_fork)
		return (2) ;
	pthread_mutex_lock(&rules->m_forks[philo->left_fork]);
	pthread_mutex_lock(&rules->m_forks[philo->right_fork]);
	t_printf("has taken a fork", rules, philo);
	t_printf("has taken a fork", rules, philo);
	pthread_mutex_lock(&rules->m_lastmeal);
	philo->last_eat = get_time();
	t_printf("is eating", rules, philo);
	pthread_mutex_unlock(&rules->m_lastmeal);
	pthread_mutex_lock(&rules->m_count);
	philo->count_eat++;
	pthread_mutex_unlock(&rules->m_count);
	pthread_mutex_unlock(&rules->m_forks[philo->left_fork]);
	pthread_mutex_unlock(&rules->m_forks[philo->right_fork]);
	return (ft_my_sleep(philo, rules->time_eat));
}

void    *philo(void *args)
{
	t_philo *philo = (t_philo *)args;
	// int dead;

	// dead = check_death_true(philo);
	if (philo->id % 2 == 0)
		usleep(100);		
	while (check_death_true(philo) != 1)
	{
		while (philo_eats(philo->st_rul, philo) == 2)
		{
			if (check_death_true(philo) == 1)
				break ;
			continue ;			
		}
		if (check_death_true(philo) == 1)
			break;
		if (ft_print_sleep(philo->st_rul, philo) == 1)
			break ;
		if (ft_print_think(philo->st_rul, philo) == 1)
			break ;
	}
	return (NULL);
}

void	*death_check(void *arg)
{
	t_rules *rules = (t_rules *)arg;
	int	i;

	while (check_death_true(rules->philo) == 0)
	{
		i = -1;
		while (++i < rules->philosophers)
		{
			if (get_time() - last_eat_check(rules, rules->philo[i].id) > rules->time_die)
			{
				pthread_mutex_lock(&rules->m_death);
				t_printf("Has Died\n", rules, rules->philo);
				rules->must_die = 1;
				pthread_mutex_unlock(&rules->m_death);
				break ;
			}
		}
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
		pthread_mutex_init(&rules.m_forks[i], NULL);
	rules.start_time = get_time();
	i = -1;
	while (++i < rules.philosophers)
	{
		pthread_create(&rules.ph[i], NULL, &philo, &rules.philo[i]);  
		rules.philo[i].last_eat = get_time();
	}
	pthread_create(&rules.death_thread, NULL, &death_check, &rules);  
	i = -1;
	while (++i < rules.philosophers)
		pthread_join(rules.ph[i], NULL);
	pthread_join(rules.death_thread, NULL);
	i = -1;
	while (++i < rules.philosophers)
	    pthread_mutex_destroy(&rules.m_forks[i]);
	//free
	// while (1)
	// {
	//     check_res = is_died(&rules);
	//     if (check_res == 1)
	//     {
	//         rules.must_die = 1;
	//         break;
	//     }
	//     if (check_res == 2)
	//         break;
	//     if (join_flag == 0)
	//     {
	//         join_flag = 1;
	//     }
	// }
	// return (0);
}
