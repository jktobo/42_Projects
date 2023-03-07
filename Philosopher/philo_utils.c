/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:58:03 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/03 21:37:19 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int			minus;
	long int	res;

	res = 0;
	minus = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		minus *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10 + (*str - '0'));
		if (res * minus > 2147483647)
			ft_error();
		else if (res * minus < 0)
			ft_error();
		str++;
	}
	return (minus * res);
}

void *ft_memset(void *s, int c, size_t n)
{
    size_t i;
    unsigned char *p;
    unsigned char ch;

    i = -1;
    p = s;
    ch = c;
    while (++i < n)
        p[i] = ch;
    return (s);
}