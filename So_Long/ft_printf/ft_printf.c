/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 04:03:46 by dkaratae          #+#    #+#             */
/*   Updated: 2022/05/10 13:36:23 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_option(unsigned long int num, char low_up)
{
	unsigned int	count;

	count = 0;
	if (low_up == 'p')
	{
		ft_putstr("0x");
		count = count + px_converter(num, 87) + 2;
	}
	else if (low_up == 'x')
		count = count + px_converter(num, 87);
	else if (low_up == 'X')
		count = count + px_converter(num, 55);
	return (count);
}

int	pr_flags(char text, va_list ap)
{
	unsigned int	count;

	count = 0;
	if (text == 'c')
		count = count + ft_putchar((char)va_arg(ap, int));
	if (text == 's')
		count = count + ft_putstr(va_arg(ap, char *));
	if (text == 'p')
		count = count + hex_option(va_arg(ap, unsigned long int), text);
	if (text == 'd' || text == 'i')
		count = count + ft_putnbr_d(va_arg(ap, int));
	if (text == 'u')
		count = count + ft_putnbr_u(va_arg(ap, unsigned int));
	if (text == 'x' || text == 'X')
		count = count + hex_option(va_arg(ap, unsigned int), text);
	if (text == '%')
		count = count + ft_putchar('%');
	return (count);
}

int	ft_printf(const char *text, ...)
{
	va_list			ap;
	unsigned int	count;

	count = 0;
	va_start(ap, text);
	while (*text)
	{
		if (*text == '%')
		{
			text++;
			count = count + pr_flags(*text, ap);
		}
		else
			count = count + ft_putchar(*text);
		text++;
	}
	va_end(ap);
	return (count);
}
