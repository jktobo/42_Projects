/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:29:49 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/20 17:37:01 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat_sleep_think(t_philo *philo)
{
	ft_eats(philo->st_rul, philo);
	ft_sleep(philo->st_rul, philo);
	ft_think(philo->st_rul, philo);
}

void	*philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->st_rul->check);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->st_rul->check);
	if (philo->id % 2 == 0)
		usleep(100);
	pthread_mutex_lock(&philo->st_rul->g);
	while (philo->st_rul->on_off)
	{
		if (ft_check_count_eat(philo))
			break ;
		pthread_mutex_unlock(&philo->st_rul->g);
		if (take_forks(philo->st_rul, philo))
		{
			pthread_mutex_lock(&philo->st_rul->g);
			break ;
		}
		ft_eat_sleep_think(philo);
		pthread_mutex_lock(&philo->st_rul->g);
	}
	pthread_mutex_unlock(&philo->st_rul->g);
	return (NULL);
}

void	ft_run_philos(t_rules *rules)
{
	int	i;

	i = -1;
	rules->start_time = get_time();
	while (++i < rules->count_phil)
		pthread_create(&rules->ph[i], NULL, &philo, &rules->philo[i]);
}

void	ft_detach_destroy(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->count_phil)
		pthread_join(rules->ph[i], NULL);
	i = -1;
	while (++i < rules->count_phil)
		pthread_mutex_destroy(&rules->forks[i]);
	pthread_mutex_destroy(&rules->print);
	pthread_mutex_destroy(&rules->check);
	pthread_mutex_destroy(&rules->g);
}

int	main(int ac, char **av)
{
	int		i;
	t_rules	rules;

	i = 0;
	if (ft_checker(ac, av, &rules))
		return (0);
	ft_run_philos(&rules);
	while (1)
	{
		pthread_mutex_lock(&rules.check);
		if (rules.count_ate == rules.count_phil)
		{
			pthread_mutex_unlock(&rules.check);
			break ;
		}
		if (i == rules.count_phil)
			i = 0;
		pthread_mutex_unlock(&rules.check);
		usleep(10);
		if (ft_check_time_died(&rules, i))
			break ;
		i++;
	}
	ft_detach_destroy(&rules);
	return (0);
}
