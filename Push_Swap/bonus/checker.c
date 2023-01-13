/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:59:44 by dkaratae          #+#    #+#             */
/*   Updated: 2022/12/27 14:35:46 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_rules(t_node **head_a, t_node **head_b, char *str)
{
	if (str[0] == 's' && str[1] == 'a')
		swap_list(head_a, 'n', "sa");
	else if (str[0] == 's' && str[1] == 'b')
		swap_list(head_b, 'n', "sb");
	else if (str[0] == 's' && str[1] == 's')
		ss_list(head_a, head_b, "ss");
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		rr_list(head_a, 'n', "rra");
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		rr_list(head_b, 'n', "rrb");
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		rrr_list(head_a, head_b, "rrr");
	else if (str[0] == 'r' && str[1] == 'a')
		r_list(head_a, 'n', "ra");
	else if (str[0] == 'r' && str[1] == 'b')
		r_list(head_b, 'n', "rb");
	else if (str[0] == 'r' && str[1] == 'r')
		rrab_list(head_a, head_b, "rr");
	else if (str[0] == 'p' && str[1] == 'a')
		ft_pa(head_a, head_b);
	else if (str[0] == 'p' && str[1] == 'b')
		ft_pb(head_a, head_b);
	else
		return (1);
	return (0);
}

int	ft_get_rules(t_node **head_a, t_node **head_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (ft_check_rules(head_a, head_b, str) == 1)
		{
			free(str);
			return (1);
		}
		free(str);
		str = get_next_line(0);
	}
	return (0);
}

int	ft_sort_list(t_node *head)
{
	t_node	*temp;

	temp = head;
	while (temp && temp->next)
	{
		if (temp->data > temp->next->data)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	ft_checker(int *nbr, int size)
{
	t_node	*head_a;
	t_node	*head_b;

	head_a = NULL;
	head_b = NULL;
	ft_create_stack(&head_a, nbr, size);
	if (ft_get_rules(&head_a, &head_b) != 1)
	{
		if (ft_sort_list(head_a) == 1 || head_b)
		{
			ft_putstr_fd("KO\n", 1);
			ft_free_staks_array(&head_a, &head_b);
		}
		else
		{
			ft_putstr_fd("OK\n", 1);
			ft_free_staks_array(&head_a, &head_b);
		}
	}
	else
	{
		ft_free_staks_array(&head_a, &head_b);
		free(nbr);
		ft_error();
	}
}

int	main(int ac, char **av)
{
	int		*nbr;
	int		size;
	char	**result;
	int		*temp;

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
	ft_checker(nbr, size);
	free(nbr);
	return (0);
}
