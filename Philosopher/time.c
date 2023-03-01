/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:40:04 by dkaratae          #+#    #+#             */
/*   Updated: 2023/02/27 17:22:24 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long    get_time(void)
{
    struct timeval  tp;
    long            milliseconds;

    gettimeofday(&tp, NULL);
    milliseconds = tp.tv_sec * 1000;
    milliseconds += tp.tv_usec / 1000;
    return (milliseconds);
}

void ft_my_sleep(long ms)
{
    struct timeval  now;
    long  start;

    start = get_time();
    gettimeofday(&now, NULL);
    while (get_time() - start < ms)
    {
        usleep(10);
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