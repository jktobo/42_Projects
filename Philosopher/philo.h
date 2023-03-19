/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:17:05 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/19 19:29:43 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

struct	s_rules;

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	int				count_eat;
	int				ate;
	long			last_eat;
	struct s_rules	*st_rul;
}	t_philo;

typedef struct s_rules
{
	int				count_phil;
	int				time_t_die;
	int				time_t_eat;
	int				time_t_sleep;
	int				opt_arg;
	int				count_ate;
	int				is_run;
	long			start_time;
	pthread_t		ph[250];
	pthread_mutex_t	forks[250];
	t_philo			philo[250];
	pthread_mutex_t	print;
}	t_rules;

/* check.c */
void	t_printf(char *str, t_rules *rules, t_philo *philo);
int		ft_check_count_eat(t_philo *philo);
int		ft_check_time_died(t_rules *rules, int i);

/* init.c */
void	ft_init_rules(t_rules *rules, int ac, char **av);
void	ft_init_mutex(t_rules *rules);
void	ft_init_philo(t_rules *rules);

/* parce.c */
void	ft_error(void);
int		ft_isdigit(int c);
int		ft_check_digit(char **av);
int		ft_checker(int ac, char **av);

/* philo_utils.c */
int		ft_atoi(const char *str);
void	take_forks(t_rules *rules, t_philo *philo);
void	ft_eats(t_rules *rules, t_philo *philo);
void	ft_sleep(t_rules *rules, t_philo *philo);
void	ft_think(t_rules *rules, t_philo *philo);

/* philo.c */
void	*philo(void *arg);
void	ft_run_philos(t_rules *rules);
void	ft_detach_destroy(t_rules *rules);

/* time.c */
long	get_time(void);
long	print_get_time(t_philo *philo);
int		ft_my_sleep(long ms);

#endif
