/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:33:46 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/07 02:56:16 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_rules(t_rules *st, char **av, int ac)
{
    st->philosophers = ft_atoi(av[1]);
    st->time_die = ft_atoi(av[2]);
    st->time_eat = ft_atoi(av[3]);
    st->time_sleep = ft_atoi(av[4]);
    if (ac == 6)
        st->opt_arg = ft_atoi(av[5]);
    else
        st->opt_arg = -1;
    pthread_mutex_init(&st->m_print, NULL);
    st->must_die = 0;
    st->start_time = 0;
    st->flag_opt = 0;
}

void	init_philo(t_rules *rules)
{
	int i;

	i = -1;
	while (++i < rules->philosophers)
	{
		rules->philo[i].id = i;
        rules->philo[i].count_eat = 0;
		rules->philo[i].last_eat = 0;
		rules->philo[i].flag_eat_full = 0;
        rules->philo[i].right_fork = i;
        rules->philo[i].left_fork = (i + 1) % rules->philosophers;
		rules->philo[i].st_rul = rules;
	}
}