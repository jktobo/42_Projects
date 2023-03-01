/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:17:05 by dkaratae          #+#    #+#             */
/*   Updated: 2023/02/27 18:17:46 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>

struct s_rules;
#define NUM_PHILOSOPHERS 5
#define NUM_FORKS 5

typedef	struct s_philo
{
	int				id;
	int				last_time_eat;
	int				left_fork;
	int				right_fork;
	pthread_mutex_t	r_mutfork;
	pthread_mutex_t	l_mutfork;
	struct s_rules	*test2;
} t_philo;

typedef	struct s_rules
{
	// pthread_mutex_t	mutex;
	int				philosophers;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				opt_arg;
	pthread_t		ph[250];
	pthread_mutex_t forks[250];
} t_rules;

// typedef	struct s_rules
// {
// 	// pthread_mutex_t	mutex;
// 	int				philosophers;
// 	int				time_die;
// 	int				time_eat;
// 	int				time_sleep;
// 	int				opt_arg;
// 	t_philo			philo[250];
// 	int				fork[250];
// 	pthread_mutex_t mutex[250];
// } t_rules;

void    ft_error(void);
int		ft_check_digit(char **av); 
void	ft_checker(int ac, char **av);
void    ft_init_str(t_rules *st, char **av, int ac);

int		ft_atoi(const char *str);

long    get_time(void);
void	ft_my_sleep(long ms);
