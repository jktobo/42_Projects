/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:33:46 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/19 19:18:36 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_rules(t_rules *rules, int ac, char **av)
{
	rules->count_phil = ft_atoi(av[1]);
	rules->time_t_die = ft_atoi(av[2]);
	rules->time_t_eat = ft_atoi(av[3]);
	rules->time_t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		rules->opt_arg = ft_atoi(av[5]);
	else
		rules->opt_arg = -1;
	rules->count_ate = 0;
	rules->is_run = 1;
	rules->start_time = 0;
}

void	ft_init_mutex(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->count_phil)
		pthread_mutex_init(&rules->forks[i], NULL);
	pthread_mutex_init(&rules->print, NULL);
}

void	ft_init_philo(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->count_phil)
	{
		rules->philo[i].id = i + 1;
		rules->philo[i].r_fork = i;
		rules->philo[i].l_fork = (i + 1) % rules->count_phil;
		rules->philo[i].count_eat = 0;
		rules->philo[i].ate = 0;
		rules->philo[i].last_eat = 0;
		rules->philo[i].st_rul = rules;
	}
}
