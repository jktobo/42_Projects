/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:33:41 by dkaratae          #+#    #+#             */
/*   Updated: 2022/12/12 18:15:44 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_list(t_node **head, char ch, char *flag)
{
	t_node	*new;
	t_node	*new_next;

	new = *head;
	new_next = (*head)->next;
	*head = new_next->next;
	new->next = *head;
	new_next->next = new;
	*head = new_next;
	if (ch == 'p')
		ft_putstr_fd(flag, 1);
}

void	r_list(t_node **head, char ch, char *flag)
{
	t_node	*first;
	t_node	*last;

	first = *head;
	*head = (*head)->next;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	first->next = NULL;
	last->next = first;
	if (ch == 'p')
		ft_putstr_fd(flag, 1);
}

void	rr_list(t_node **head, char ch, char *flag)
{
	t_node	*new;
	t_node	*temp;
	int		position;
	int		i;

	i = 1;
	temp = *head;
	position = size_list(temp);
	while (i < (position - 1))
	{
		temp = temp->next;
		i++;
	}
	new = temp->next;
	temp->next = NULL;
	new->next = *head;
	*head = new;
	if (ch == 'p')
		ft_putstr_fd(flag, 1);
}

int	size_list(t_node *head)
{
	int		count;
	t_node	*temp;

	temp = head;
	count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

void	ft_ra_rra(t_node **stack, t_node *pos_a, char *flag_r, char *flag_rr)
{
	int	i;

	i = 0;
	if (pos_a && pos_a->rcount < pos_a->rrcount)
	{
		i = pos_a->rcount;
		while (i > 0)
		{
			r_list(stack, 'p', flag_r);
			i--;
		}
	}
	else
	{
		i = pos_a->rrcount;
		while (i > 0)
		{
			rr_list(stack, 'p', flag_rr);
			i--;
		}
	}
}
