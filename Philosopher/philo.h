/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:17:05 by dkaratae          #+#    #+#             */
/*   Updated: 2023/02/25 13:02:17 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
typedef	struct s_date
{
	pthread_mutex_t	mutex;
	int				philosophers;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				opt_arg;
} t_date;

void    ft_error(void);
int		ft_check_digit(char **av);
void	ft_checker(int ac, char **av);
void    ft_init_str(t_date *st, char **av, int ac);

int		ft_atoi(const char *str);