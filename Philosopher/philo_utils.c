/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:58:03 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/19 19:30:04 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int			minus;
	long int	res;

	res = 0;
	minus = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		minus *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10 + (*str - '0'));
		if (res * minus > 2147483647)
			ft_error();
		else if (res * minus < 0)
			ft_error();
		str++;
	}
	return (minus * res);
}

void	take_forks(t_rules *rules, t_philo *philo)
{
	pthread_mutex_lock(&rules->forks[philo->l_fork]);
	t_printf("has taken a fork", rules, philo);
	pthread_mutex_lock(&rules->forks[philo->r_fork]);
	t_printf("has taken a fork", rules, philo);
}

void	ft_eats(t_rules *rules, t_philo *philo)
{
	t_printf("is eating", rules, philo);
	philo->count_eat++;
	philo->last_eat = get_time();
	ft_my_sleep(rules->time_t_eat);
	pthread_mutex_unlock(&rules->forks[philo->l_fork]);
	pthread_mutex_unlock(&rules->forks[philo->r_fork]);
}

void	ft_sleep(t_rules *rules, t_philo *philo)
{
	t_printf("is sleeping", rules, philo);
	ft_my_sleep(rules->time_t_sleep);
}

void	ft_think(t_rules *rules, t_philo *philo)
{
	t_printf("is thinking", rules, philo);
}
