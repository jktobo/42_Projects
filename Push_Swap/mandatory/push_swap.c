/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:59:44 by dkaratae          #+#    #+#             */
/*   Updated: 2022/12/27 14:34:29 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_elem_arg(char **av)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (av[i])
	{
		j = 0;
		ft_check_empty_argv(av[i]);
		count++;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
			{
				count++;
				while (ft_isspace(av[i][j]))
					j++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

char	**ft_send_split(char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**ch;
	char	**ch1 ;

	i = 1;
	k = 0;
	ch1 = (char **)ft_calloc(sizeof(char *), (ft_count_elem_arg(argv) + 1));
	while (argv[i])
	{
		ch = ft_split(argv[i], ' ');
		j = 0;
		while (ch[j])
		{
			ch1[k] = ft_strjoin(ch1[k], ch[j]);
			free(ch[j]);
			j++;
			k++;
		}
		i++;
		free(ch);
	}
	ch1[k] = NULL;
	return (ch1);
}

int	ft_size_result_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_sorted_or_not(int *nbr, int size)
{
	int	i;
	int	count;

	i = 1;
	count = 1;
	while (i < size)
	{
		if (nbr[i] > nbr[i - 1])
			count++;
		i++;
	}
	if (count != size)
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	int		*nbr;
	int		*temp;
	int		size;
	char	**result;

	(void) ac;
	if (ac < 2)
		return (1);
	result = ft_send_split(av);
	size = ft_size_result_array(result);
	if (ft_isnumber(result))
	{
		ft_free_char(result);
		ft_error();
	}
	nbr = (int *)malloc(sizeof(int) * size);
	temp = ft_send_atoi(result, nbr);
	nbr = ft_check_big_arg(temp, nbr, result);
	ft_free_char(result);
	ft_isduplicate(nbr, size);
	if (ft_check_sorted_or_not(nbr, size))
		ft_sort_fun(nbr, size);
	free(nbr);
	return (0);
}
