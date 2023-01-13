/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:26:42 by dkaratae          #+#    #+#             */
/*   Updated: 2022/12/12 15:21:08 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_node **head_a, t_node **head_b)
{
	t_node	*a;
	t_node	*b;

	a = *head_a;
	b = *head_b;
	*head_a = (*head_a)->next;
	*head_b = a;
	(*head_b)->next = b;
}

void	ft_pa(t_node **head_a, t_node **head_b)
{
	t_node	*a;
	t_node	*b;

	a = *head_a;
	b = *head_b;
	*head_b = (*head_b)->next;
	*head_a = b;
	(*head_a)->next = a;
}

void	ft_push_to_b_stack(t_node **head_a, t_node **head_b, int med)
{
	if ((*head_b) == NULL)
		ft_pb(&(*head_a), &(*head_b));
	else if ((*head_a)->data > med)
	{
		ft_pb(&(*head_a), &(*head_b));
		r_list(&(*head_b), 'p', "rb\n");
	}
	else
		ft_pb(&(*head_a), &(*head_b));
}
