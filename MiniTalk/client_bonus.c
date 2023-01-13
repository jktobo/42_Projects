/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:00:47 by dkaratae          #+#    #+#             */
/*   Updated: 2022/08/19 18:14:41 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_str_to_bin(char str, int pid)
{
	int	i;
	int	bin;

	i = 0;
	while (i < 8)
	{
		bin = str & 1;
		if (bin == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		str = str >> 1;
		i++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;
	int		i;

	if (ac != 3)
	{
		ft_printf("YOU NEED TO ENTER THREE ARGUMENTS!!!\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		exit(EXIT_FAILURE);
	str = av[2];
	while (str[i] != '\0')
	{
		ft_str_to_bin(str[i], pid);
		i++;
		sleep(0);
	}
	return (0);
}
