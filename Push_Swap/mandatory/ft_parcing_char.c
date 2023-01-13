/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:47:54 by dkaratae          #+#    #+#             */
/*   Updated: 2022/12/11 19:54:21 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_dup_plus_minus(char **av)
{
	int	i;
	int	j;
	int	h_arr[2];

	i = 1;
	h_arr[0] = 0;
	h_arr[1] = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+')
				h_arr[0] += 1;
			else if (av[i][j] == '-')
				h_arr[1] += 1;
			j++;
		}
		if (h_arr[0] >= 2 || h_arr[1] >= 2)
			return (1);
		h_arr[0] = 0;
		h_arr[1] = 0;
		i++;
	}
	return (0);
}

int	ft_isspace(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t' || \
		ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	return (0);
}

int	ft_check_sign(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]) == 1)
			if (str[i][0] == '+' || str[i][0] == '-')
				return (1);
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '+' || str[i][j] == '-')
				if (j > 0 && str[i][j - 1] != ' ')
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isnumber(char **av)
{
	int	i;
	int	j;

	i = 0;
	if ((ft_check_dup_plus_minus(av) == 0) && (ft_check_sign(av) == 0))
	{
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				while (ft_isspace(av[i][j]))
					j++;
				if (ft_isdigit(av[i][j]) || av[i][j] == '+' || av[i][j] == '-')
					j++;
				else
					return (1);
			}
			i++;
		}
	}
	else
		return (1);
	return (0);
}

void	ft_check_empty_argv(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (ft_strlen(str) == 0)
		ft_error();
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	if (count == ft_strlen(str))
		ft_error();
}
