/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:20:51 by dkaratae          #+#    #+#             */
/*   Updated: 2022/12/11 19:57:49 by dkaratae         ###   ########.fr       */
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

// void ft_print_list(t_node *head)
// {
//     t_node *p = head;

//     while (p != NULL)
//     {
//         printf("%d\n", p->data);
//         // printf("--------\n");
//         // printf("%d\n", p->rank);
//         // printf("r %d\n", p->b_rcount);
//         // printf("rr%d\n", p->b_rrcount);
//         p = p->next;
//     }
// }