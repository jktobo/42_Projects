/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:51:24 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/19 19:16:26 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	t_printf(char *str, t_rules *rules, t_philo *philo)
{
	if (!rules->is_run)
		return ;
	pthread_mutex_lock(&rules->print);
	printf("%ld %d %s\n", print_get_time(philo), philo->id, str);
	pthread_mutex_unlock(&rules->print);
}

int	ft_check_count_eat(t_philo *philo)
{
	if (philo->count_eat == philo->st_rul->opt_arg)
	{
		philo->ate = 1;
		philo->st_rul->count_ate++;
		return (1);
	}
	return (0);
}

int	ft_check_time_died(t_rules *rules, int i)
{
	if (!rules->philo[i].ate && \
		(get_time() - rules->philo[i].last_eat) > rules->time_t_die)
	{
		t_printf("died", rules, &rules->philo[i]);
		rules->is_run = 0;
		return (1);
	}
	return (0);
}
