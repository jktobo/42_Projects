/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:08:04 by dkaratae          #+#    #+#             */
/*   Updated: 2022/05/10 12:05:07 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digit(int num)
{
	unsigned int	count;

	count = 0;
	if (num <= 0)
		count++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	num_negat(int num)
{
	unsigned int	nbr;

	if (num < 0)
		nbr = num * (-1);
	else
		nbr = num;
	if (num < 0)
		ft_putchar('-');
	return (nbr);
}

int	ft_putnbr(int n)
{
	int		count;
	int		temp;
	char	str[30];
	int		num;

	count = 0;
	num = num_negat(n);
	while (num > 0)
	{
		temp = num % 10;
		str[count] = temp + 48;
		num = num / 10;
		count++;
	}
	str[count] = '\0';
	count--;
	while (count >= 0)
		ft_putchar(str[count--]);
	return (count_digit(n));
}

int	ft_putnbr_d(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (count_digit(n));
	}
	if (n == 0)
		ft_putchar('0');
	else
		ft_putnbr(n);
	return (count_digit(n));
}
