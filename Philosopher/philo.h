/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:17:05 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/07 14:24:55 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>

struct s_rules;
#define NUM_PHILOSOPHERS 10
#define NUM_FORKS 10

typedef	struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				count_eat;
	int				flag_eat_full;
	size_t			last_eat;
	struct s_rules	*st_rul;
} t_philo;

typedef	struct s_rules
{
	int				philosophers;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				opt_arg;
	int				flag_opt;
	int				must_die;
	size_t			start_time;
	pthread_t		ph[250];
	pthread_mutex_t m_forks[250];
	pthread_mutex_t m_print;
	pthread_mutex_t m_count;
	t_philo			philo[250];
} t_rules;


/* philo.c */
void	t_printf(char *str, t_rules *rules, t_philo *philo);
int		ft_print_fork(t_rules *rules);
int		ft_print_eat(t_rules *rules, t_philo *philo);
int		ft_print_sleep(t_rules *rules, t_philo *philo);
int		ft_print_think(t_rules *rules, t_philo *philo);
int		ft_print_died(t_rules *rules, t_philo *philo);

void    *philo(void *args);
int		is_died(t_rules *rules);

/* init.c */
void    init_rules(t_rules *st, char **av, int ac);
void	init_philo(t_rules *rules);

/* philo_utils.c */
int		ft_atoi(const char *str);
void	*ft_memset(void *s, int c, size_t n);

/* time.c */
long    get_time(void);
long    print_get_time(t_philo *philo);
int		ft_my_sleep(t_philo *philo, long ms);

/* parce.c */
void    ft_error(void);
int		ft_isdigit(int c);
int		ft_checker(int ac, char **av);

/* check.c */
int		check_died(t_philo *philo);
int		is_died(t_rules *rules);