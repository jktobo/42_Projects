/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:17:05 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/03 21:27:51 by dkaratae         ###   ########.fr       */
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
	size_t			last_eat;
	struct s_rules	*test2;
} t_philo;

typedef	struct s_rules
{
	int				philosophers;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				opt_arg;
	int				must_die;
	size_t			start_time;
	pthread_t		*ph;
	pthread_mutex_t *forks;
	pthread_mutex_t print;
	t_philo			*philo;
} t_rules;

void    ft_error(void);
int		ft_check_digit(char **av); 
void	ft_checker(int ac, char **av);
void    ft_init_str(t_rules *st, char **av, int ac);

int		ft_atoi(const char *str);
void	*ft_memset(void *s, int c, size_t n);

long    get_time(void);
long    print_get_time(t_philo *philo);
void	ft_my_sleep(long ms);
int		print_message(t_philo *philo, char c);
