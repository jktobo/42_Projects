/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:44:08 by dkaratae          #+#    #+#             */
/*   Updated: 2022/05/10 10:43:42 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	px_print(unsigned long int num, int lucase)
{
	int				i;
	unsigned int	count;
	long long int	temp;
	char			hex_num[30];

	i = 0;
	count = 0;
	while (num != 0)
	{
		temp = (num % 16);
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + lucase;
		hex_num[i++] = temp;
		num = num / 16;
		count++;
	}
	i -= 1;
	while (i >= 0)
		ft_putchar(hex_num[i--]);
	return (count);
}

int	px_converter(unsigned long int num, int lucase)
{
	unsigned int	count;

	count = 0;
	if (num == 0)
		count = count + ft_putchar('0');
	else
		count = count + px_print(num, lucase);
	return (count);
}
