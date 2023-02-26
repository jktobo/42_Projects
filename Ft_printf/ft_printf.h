/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:56:41 by dkaratae          #+#    #+#             */
/*   Updated: 2022/05/10 10:43:44 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

int		ft_printf(const char *text, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr_d(int n);
int		ft_putnbr_u(unsigned int n);
int		count_digit(int num);
int		count_digit_u(unsigned int num);
int		px_converter(unsigned long int num, int lucase);
int		count_digit_u(unsigned int num);
int		px_print(unsigned long int num, int lucase);
#endif
