/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:00:21 by dkaratae          #+#    #+#             */
/*   Updated: 2022/12/10 17:25:30 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_calculate_score(t_node *stack)
{
	int		i;
	int		size;
	t_node	*s;

	i = 0;
	s = stack;
	size = size_list(stack);
	while (i < size)
	{
		stack->rcount = i;
		stack->rrcount = size - i;
		i++;
		stack = stack->next;
	}
	return (s);
}

int	ft_calc_rank_stack(t_node *stack)
{
	if (stack->rcount > stack->rrcount)
		return (stack->rrcount);
	else
		return (stack->rcount);
}

void	ft_calculate_rank(t_node *head_a, t_node *head_b)
{
	int		size_a;
	int		prev;
	t_node	*temp;

	while (head_b != NULL)
	{
		size_a = size_list(head_a);
		temp = head_a;
		prev = ft_last_node(temp);
		while (size_a > 0)
		{
			if (prev < head_b->data && temp->data > head_b->data)
			{
				head_b->rank = ft_calc_rank_stack(temp) + \
								ft_calc_rank_stack(head_b);
				break ;
			}
			prev = temp->data;
			temp = temp->next;
			size_a--;
		}
		head_b = head_b->next;
	}
}
