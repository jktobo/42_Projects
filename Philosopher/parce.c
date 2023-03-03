/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:32:55 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/03 14:53:58 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_error(void)
{
    printf("Parsing is error!\n");
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int ft_check_digit(char **av)
{
    int i;
    int j;

    i = 0;
    while (av[++i])
    {
        j = -1;
        while (av[i][++j])
        {
            if (!(ft_isdigit(av[i][j])))
                return (1);
        }
    }
    return (0);
}

void ft_checker(int ac, char **av)
{
    // int i;

    // i = -1;
    if (!(ac == 5 || ac == 6))
        ft_error();
    else if (ft_check_digit(av))
        ft_error();
}
