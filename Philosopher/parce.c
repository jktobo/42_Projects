/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:32:55 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/20 16:55:28 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(void)
{
	printf("Parsing is error!\n");
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_check_digit(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!(ft_isdigit(av[i][j])))
				return (1);
		}
	}
	return (0);
}

int	ft_check_max_min(t_rules *rules)
{
	long	max;

	max = 2147483647;
	if (rules->time_t_die < 60 || rules->time_t_eat < 60 || \
		rules->time_t_sleep < 60)
		return (ft_error());
	if (rules->time_t_die > max || \
		rules->time_t_eat > max || rules->time_t_sleep > max)
		return (ft_error());
	if (rules->count_phil > 200)
		return (ft_error());
	return (0);
}

int	ft_checker(int ac, char **av, t_rules *rules)
{
	if (!(ac == 5 || ac == 6))
	{
		ft_error();
		return (1);
	}
	else if (ft_check_digit(av))
	{
		ft_error();
		return (1);
	}
	ft_init_rules(rules, ac, av);
	if (ft_check_max_min(rules))
	{
		return (1);
	}
	ft_init_mutex(rules);
	ft_init_philo(rules);
	return (0);
}
