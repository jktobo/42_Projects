/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:15:29 by dkaratae          #+#    #+#             */
/*   Updated: 2022/04/08 21:52:31 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_count(int c)
{
	int	count;

	count = 0;
	while (c != 0)
	{
		c = c / 10;
		count++;
	}
	return (count);
}

char	*n_zero(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		minus;
	int		count;
	char	*str;

	minus = 1;
	count = num_count(n);
	if (n < 0)
		minus = -1;
	count = count + (n <= 0);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!(str))
		return (str);
	if (n == 0)
		n_zero(str);
	str[count] = '\0';
	while (n != 0)
	{
		str[--count] = (char)((n % 10) * minus + '0');
		n = n / 10;
	}
	count--;
	if (minus < 0)
		str[count] = '-';
	return (str);
}
