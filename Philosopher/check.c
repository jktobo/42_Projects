/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:51:24 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/07 03:06:39 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_died(t_philo *philo)
{
	if (philo->st_rul->must_die == 1)
        {
            ft_print_died(philo->st_rul);
            return (1);
        }
	return (0);
}

int is_died(t_rules *rules)
{
    int i;
    
    i = 0;
    while (!rules->must_die)
    {
        size_t sum;
        pthread_mutex_lock(&rules->m_print);
        sum = get_time() - rules->philo[i].last_eat;
        if (rules->philo[i].last_eat == 0)
        {
            pthread_mutex_unlock(&rules->m_print);
            if (i == rules->philosophers)
                i = 0;
            continue;
        }
        pthread_mutex_unlock(&rules->m_print);
        pthread_mutex_lock(&rules->m_print);
        if (sum > (size_t)rules->philo[i].st_rul->time_die) {
            
            pthread_mutex_unlock(&rules->m_print);
            return (1);
        }
        pthread_mutex_unlock(&rules->m_print);
        i++;
        if (i == rules->philosophers)
            i = 0;
    }
    return (0);
}