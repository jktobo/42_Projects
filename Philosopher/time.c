/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:40:04 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/07 19:11:46 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long    get_time(void)
{
    struct timeval  tm;
    long            milliseconds;

    gettimeofday(&tm, NULL);
    milliseconds = tm.tv_sec * 1000;
    milliseconds += tm.tv_usec / 1000;
    return (milliseconds);
}
long    print_get_time(t_philo *philo)
{
    return (get_time() - philo->st_rul->start_time);
}

int ft_my_sleep(t_philo *philo, long ms)
{
    long  start;

    start = get_time();
    while (get_time() - start < ms)
    {
        if (check_died(philo) == 1)
            return (1);
        usleep(50);
    }
    return (0);
}
