/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:28:40 by dkaratae          #+#    #+#             */
/*   Updated: 2022/12/27 14:45:16 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error", 2);
	exit(1);
}

int	*ft_check_big_arg(int *temp, int *nbr, char **result)
{
	if (temp == NULL)
	{
		free (nbr);
		ft_free_char(result);
		ft_error();
	}
	return (temp);
}

void	ft_free_char(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	delete_node(t_node **head)
{
	t_node	*temp;

	temp = *head;
	*head = (*head)->next;
	free(temp);
}

void	ft_free_stack(t_node **head)
{
	t_node	*temp;

	temp = *head;
	while (temp != NULL)
	{
		delete_node(head);
		temp = *head;
	}
}
