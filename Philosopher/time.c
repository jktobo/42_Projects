/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:40:04 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/03 08:13:42 by dkaratae         ###   ########.fr       */
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
    return (get_time() - philo->test2->start_time);
}

void ft_my_sleep(long ms)
{
    struct timeval  now;
    long  start;

    start = get_time();
    gettimeofday(&now, NULL);
    while (get_time() - start < ms)
    {
        usleep(50);
        gettimeofday(&now, NULL);
    }
}

// int main(void)
// {
//     long start_time;
		
//     start_time = get_time();

//     while (1)
//     {
//         printf("%ld\n", get_time() - start_time);
//         // usleep(200000);
//         ft_my_sleep(200);
//     }
// }