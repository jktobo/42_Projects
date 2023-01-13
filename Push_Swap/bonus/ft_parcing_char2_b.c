/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing_char2_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:29:05 by dkaratae          #+#    #+#             */
/*   Updated: 2022/12/12 18:18:49 by dkaratae         ###   ########.fr       */
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
