/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:29:49 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/19 19:22:05 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = get_time();
	if (philo->id % 2 == 0)
		usleep(100);
	while (philo->st_rul->is_run)
	{
		if (ft_check_count_eat(philo))
			break ;
		take_forks(philo->st_rul, philo);
		ft_eats(philo->st_rul, philo);
		ft_sleep(philo->st_rul, philo);
		ft_think(philo->st_rul, philo);
	}
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
		pthread_detach(rules->ph[i]);
	i = -1;
	while (++i < rules->count_phil)
		pthread_mutex_destroy(&rules->forks[i]);
	pthread_mutex_destroy(&rules->print);
}

int	main(int ac, char **av)
{
	int		i;
	t_rules	rules;

	i = 0;
	if (ft_checker(ac, av) == 1)
		return (0);
	ft_init_rules(&rules, ac, av);
	ft_init_mutex(&rules);
	ft_init_philo(&rules);
	ft_run_philos(&rules);
	while (1)
	{
		if (rules.count_ate == rules.count_phil)
			break ;
		if (i == rules.count_phil)
			i = 0;
		usleep(1000);
		if (ft_check_time_died(&rules, i))
			break ;
		i++;
	}
	ft_detach_destroy(&rules);
	return (0);
}
