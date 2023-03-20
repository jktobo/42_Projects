/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:58:03 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/20 19:52:07 by dkaratae         ###   ########.fr       */
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
		str++;
	}
	return (minus * res);
}

int	take_forks(t_rules *rules, t_philo *philo)
{
	pthread_mutex_lock(&rules->forks[philo->l_fork]);
	t_printf("has taken a fork", rules, philo);
	if (&rules->forks[philo->r_fork] != &rules->forks[philo->l_fork])
	{
		pthread_mutex_lock(&rules->forks[philo->r_fork]);
		t_printf("has taken a fork", rules, philo);
	}
	else
	{
		pthread_mutex_unlock(&rules->forks[philo->l_fork]);
		ft_my_sleep(rules->time_t_die);
		t_printf("died", rules, philo);
		pthread_mutex_lock(&philo->st_rul->g);
		rules->on_off = 0;
		pthread_mutex_unlock(&philo->st_rul->g);
		return (1);
	}
	return (0);
}

void	ft_eats(t_rules *rules, t_philo *philo)
{
	t_printf("is eating", rules, philo);
	pthread_mutex_lock(&rules->g);
	philo->count_eat++;
	philo->last_eat = get_time();
	pthread_mutex_unlock(&rules->g);
	ft_my_sleep(rules->time_t_eat);
	pthread_mutex_unlock(&rules->forks[philo->r_fork]);
	pthread_mutex_unlock(&rules->forks[philo->l_fork]);
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
