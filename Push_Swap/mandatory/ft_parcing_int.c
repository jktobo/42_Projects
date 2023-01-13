/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:47:33 by dkaratae          #+#    #+#             */
/*   Updated: 2022/12/27 14:17:57 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_send_atoi(char **av, int *nbr)
{
	long long int	i;
	int				p;

	i = 0;
	p = 0;
	while (av[i])
	{
		nbr[i] = ft_atoi(av[i], &p);
		i++;
	}
	if (p == 1)
		return (NULL);
	return (nbr);
}

void	ft_isduplicate(int *nbr, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (nbr[i] == nbr[j])
			{
				free(nbr);
				ft_error();
			}
			j++;
		}
		i++;
	}
}

void	ft_swap(int *min, int *i)
{
	int	temp;

	temp = *min;
	*min = *i;
	*i = temp;
}

int	ft_find_med(int *nbr, int size)
{
	int	i;
	int	j;
	int	min;
	int	med;

	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (nbr[j] < nbr[min])
				min = j;
			j++;
		}
		ft_swap(&nbr[min], &nbr[i]);
		i++;
	}
	return (med = nbr[size / 2]);
}

void	ft_find_min_max(int *array, int *min, int *max, int size)
{
	int	i;

	i = 0;
	(*min) = array[0];
	(*max) = array[0];
	while (i < size)
	{
		if ((*min) > array[i])
			(*min) = array[i];
		if ((*max) < array[i])
			(*max) = array[i];
		i++;
	}
}
