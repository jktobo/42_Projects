/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 01:31:23 by dkaratae          #+#    #+#             */
/*   Updated: 2022/12/27 14:16:51 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

int	ft_atoi(const char *str, int *flag)
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
			*flag = 1;
		else if (res * minus < -2147483648)
			*flag = 1;
		str++;
	}
	return (minus * res);
}
