/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:18:51 by dkaratae          #+#    #+#             */
/*   Updated: 2022/08/19 18:11:19 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_convert_print(char *str)
{
	int		i;
	int		total;
	int		dec;
	char	s;

	total = 0;
	dec = 1;
	i = 0;
	while (i < 8)
	{
		if (str[i] == '1')
			total += dec;
		dec *= 2;
		i++;
	}
	s = total;
	write(1, &s, 1);
}

void	sig_handle(int sig)
{
	static char	str[8];
	static int	i;

	if (i == 7)
	{
		str[i] = ((sig - 30) + '0');
		ft_convert_print(str);
		i = 0;
		return ;
	}
	str[i] = ((sig - 30) + '0');
	i++;
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, sig_handle);
	signal(SIGUSR2, sig_handle);
	while (1)
		sleep(0);
	return (0);
}
