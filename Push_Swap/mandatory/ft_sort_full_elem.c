/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_full_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:25:22 by dkaratae          #+#    #+#             */
/*   Updated: 2022/12/11 19:02:07 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_find_min_rank_b(t_node *head_b)
{
	t_node	*temp;
	t_node	*min_rank_b;

	temp = head_b;
	min_rank_b = temp;
	while (temp != NULL)
	{
		if (temp->rank < min_rank_b->rank)
			min_rank_b = temp;
		temp = temp->next;
	}
	return (min_rank_b);
}

t_node	*ft_find_min_a_for_min_b(t_node *head_a, t_node *min_rank_b)
{
	t_node	*temp;
	t_node	*min_a;
	int		prev;

	temp = head_a;
	min_a = head_a;
	prev = ft_last_node(head_a);
	while (temp != NULL)
	{
		if (prev < min_rank_b->data && temp->data > min_rank_b->data)
			min_a = temp;
		prev = temp->data;
		temp = temp->next;
	}
	return (min_a);
}

void	ft_final_sort(t_node **head_a)
{
	t_node	*temp;
	t_node	*min;

	temp = *head_a;
	min = temp;
	while (temp != NULL)
	{
		if (temp->data < min->data)
			min = temp;
		temp = temp->next;
	}
	ft_calculate_score(*head_a);
	ft_ra_rra(head_a, min, "ra\n", "rra\n");
}

void	ft_b_to_a(t_node **head_a, t_node **head_b)
{
	t_node	*min_rank_b;
	t_node	*pos_a;
	int		i;
	int		s;

	i = 0;
	s = size_list(*head_b);
	while (i < s)
	{
		*head_a = ft_calculate_score(*head_a);
		*head_b = ft_calculate_score(*head_b);
		ft_calculate_rank(*head_a, *head_b);
		min_rank_b = ft_find_min_rank_b(*head_b);
		pos_a = ft_find_min_a_for_min_b(*head_a, min_rank_b);
		ft_ra_rra(&(*head_a), pos_a, "ra\n", "rra\n");
		ft_ra_rra(&(*head_b), min_rank_b, "rb\n", "rrb\n");
		ft_pa(&(*head_a), &(*head_b));
		i++;
	}
	ft_final_sort(*(&head_a));
}

void	ft_sort_big_arg(t_node **head_a, int *array, int size)
{
	int		min;
	int		max;
	int		med;
	t_node	*head_b;

	head_b = NULL;
	ft_find_min_max(array, &min, &max, size);
	med = ft_find_med(array, size);
	while (size > 0)
	{
		if ((*head_a)->data == min || (*head_a)->data == max || \
			(*head_a)->data == med)
			r_list(&(*head_a), 'p', "ra\n");
		else
			ft_push_to_b_stack(&(*head_a), &head_b, med);
		size--;
	}
	ft_sort_three_arg(&(*head_a));
	ft_b_to_a(&(*head_a), &head_b);
}
