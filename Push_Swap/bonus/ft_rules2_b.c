/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules2_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:30:34 by dkaratae          #+#    #+#             */
/*   Updated: 2022/12/12 18:19:15 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss_list(t_node **head_a, t_node **head_b, char *flag)
{
	swap_list(head_a, 'n', flag);
	swap_list(head_b, 'n', flag);
}

void	rrab_list(t_node **head_a, t_node **head_b, char *flag)
{
	rr_list(head_a, 'n', flag);
	rr_list(head_b, 'n', flag);
}

void	rrr_list(t_node **head_a, t_node **head_b, char *flag)
{
	rr_list(head_a, 'n', flag);
	rr_list(head_b, 'n', flag);
}
