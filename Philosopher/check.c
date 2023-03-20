/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:51:24 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/20 15:44:22 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	t_printf(char *str, t_rules *rules, t_philo *philo)
{
	pthread_mutex_lock(&philo->st_rul->g);
	if (!philo->st_rul->on_off)
	{
		pthread_mutex_unlock(&philo->st_rul->g);
		return ;
	}
	pthread_mutex_unlock(&philo->st_rul->g);
	pthread_mutex_lock(&rules->print);
	printf("%ld %d %s\n", print_get_time(philo), philo->id, str);
	pthread_mutex_unlock(&rules->print);
}

int	ft_check_count_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->st_rul->check);
	if (philo->count_eat == philo->st_rul->opt_arg)
	{
		philo->ate = 1;
		philo->st_rul->count_ate++;
		pthread_mutex_unlock(&philo->st_rul->check);
		return (1);
	}
	pthread_mutex_unlock(&philo->st_rul->check);
	return (0);
}

int	ft_check_time_died(t_rules *rules, int i)
{
	pthread_mutex_lock(&rules->g);
	if (!rules->philo[i].ate && \
		(get_time() - rules->philo[i].last_eat) > rules->time_t_die)
	{
		pthread_mutex_unlock(&rules->g);
		t_printf("died", rules, &rules->philo[i]);
		pthread_mutex_lock(&rules->g);
		rules->on_off = 0;
		pthread_mutex_unlock(&rules->g);
		return (1);
	}
	pthread_mutex_unlock(&rules->g);
	return (0);
}
