/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:20:51 by dkaratae          #+#    #+#             */
/*   Updated: 2022/12/27 14:48:19 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_node(t_node **head_ref, int set_data)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	new_node->data = set_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void	ft_create_stack(t_node **head, int *array, int size)
{
	int		i;

	i = size - 1;
	while (i >= 0)
	{
		create_node(head, array[i]);
		i--;
	}
}

int	ft_last_node(t_node *stack)
{
	t_node	*node;

	while (stack != NULL)
	{
		node = stack;
		stack = stack->next;
	}
	return (node->data);
}

void	ft_free_staks_array(t_node **head_a, t_node **head_b)
{
	ft_free_stack(head_a);
	ft_free_stack(head_b);
}
