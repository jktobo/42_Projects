/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:36:29 by dkaratae          #+#    #+#             */
/*   Updated: 2022/12/12 15:44:08 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_fun(int *array, int size)
{
	t_node	*head_a;

	head_a = NULL;
	ft_create_stack(&head_a, array, size);
	if (size == 2)
		ft_sort_two_arg(&head_a);
	else if (size == 3)
		ft_sort_three_arg(&head_a);
	else if (size == 5)
		ft_sort_five_arg(&head_a, array);
	else
		ft_sort_big_arg(&head_a, array, size);
	ft_free_stack(&head_a);
}

void	ft_sort_two_arg(t_node **head_a)
{
	if ((*head_a)->data > (*head_a)->next->data)
		swap_list(&(*head_a), 'p', "sa\n");
}

void	ft_sort_three_arg(t_node **head)
{
	int	first;
	int	second;
	int	third;

	first = (*head)->data;
	second = (*head)->next->data;
	third = (*head)->next->next->data;
	if (first > second && first < third && second < third)
		swap_list(&(*head), 'p', "sa\n");
	else if (first > second && first > second && second < third)
		r_list(&(*head), 'p', "ra\n");
	else if (first < second && first > third && second > third)
		rr_list(&(*head), 'p', "rra\n");
	else if (first > second && first > third && second > third)
	{
		swap_list(&(*head), 'p', "sa\n");
		rr_list(&(*head), 'p', "rra\n");
	}
	else if (first < second && first < third && second > third)
	{
		swap_list(&(*head), 'p', "sa\n");
		r_list(&(*head), 'p', "ra\n");
	}
}

void	ft_sort_five_arg(t_node **head_a, int *array)
{
	int		min;
	int		max;
	int		size;
	t_node	*head_b;
	t_node	*temp;

	head_b = NULL;
	size = size_list(*head_a);
	ft_find_min_max(array, &min, &max, size);
	while (size > 0)
	{
		temp = *head_a;
		if (temp->data == min || temp->data == max)
			ft_pb(head_a, &head_b);
		else
			r_list(head_a, 'p', "ra\n");
		size--;
	}
	ft_sort_three_arg(head_a);
	ft_sort_five_push_to_a_from_b(head_a, &head_b);
}

void	ft_sort_five_push_to_a_from_b(t_node **head_a, t_node **head_b)
{
	int	size;

	size = size_list(*head_b);
	while (size > 0)
	{
		if ((*head_a)->data > (*head_b)->data)
			ft_pa(&(*head_a), &(*head_b));
		else
		{
			ft_pa(&(*head_a), &(*head_b));
			r_list(&(*head_a), 'p', "ra\n");
		}
		size--;
	}
}
