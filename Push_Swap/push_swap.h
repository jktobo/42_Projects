/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:09:16 by dkaratae          #+#    #+#             */
/*   Updated: 2022/12/27 14:48:16 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct t_list{
	int				data;
	int				rcount;
	int				rrcount;
	int				rank;
	struct t_list	*next;
}t_node;

// push_swap & checker
int		main(int ac, char **av);
int		ft_check_sorted_or_not(int *nbr, int size);
int		ft_size_result_array(char **str);
char	**ft_send_split(char **argv);
int		ft_count_elem_arg(char **av);

// bonus part
void	ft_checker(int *nbr, int size);
int		ft_sort_list(t_node *head);
int		ft_get_rules(t_node **head_a, t_node **head_b);
int		ft_check_rules(t_node **head_a, t_node **head_b, char *str);

// ft_parcing_char
int		ft_check_dup_plus_minus(char **av);
int		ft_isspace(char ch);
int		ft_check_sign(char **str);
int		ft_isnumber(char **av);
void	ft_check_empty_argv(char *str);

// ft_parcing_int
int		*ft_send_atoi(char **av, int *nbr);
void	ft_isduplicate(int *nbr, int count);
void	ft_swap(int *min, int *i);
int		ft_find_med(int *nbr, int size);
void	ft_find_min_max(int *array, int *min, int *max, int size);

// ft_rules
void	swap_list(t_node **head, char ch, char *flag);
void	r_list(t_node **head, char ch, char *flag);
void	rr_list(t_node **head, char ch, char *flag);
int		size_list(t_node *head);
void	ft_ra_rra(t_node **stack, t_node *pos_a, char *flag_r, char *flag_rr);

// bonus part
void	ss_list(t_node **head_a, t_node **head_b, char *flag);
void	rrab_list(t_node **head_a, t_node **head_b, char *flag);
void	rrr_list(t_node **head_a, t_node **head_b, char *flag);

// ft_list
void	create_node(t_node **head_ref, int set_data);
void	ft_create_stack(t_node **head, int *array, int size);
int		ft_last_node(t_node *stack);

void	ft_free_staks_array(t_node **head_a, t_node **head_b);

// ft_push
void	ft_pb(t_node **head_a, t_node **head_b);
void	ft_pa(t_node **head_a, t_node **head_b);
void	ft_push_to_b_stack(t_node **head_a, t_node **head_b, int med);

// ft_sort_three_elem
void	ft_sort_fun(int *array, int size);
void	ft_sort_two_arg(t_node **head_a);
void	ft_sort_three_arg(t_node **head);
void	ft_sort_five_arg(t_node **head_a, int *array);
void	ft_sort_five_push_to_a_from_b(t_node **head_a, t_node **head_b);

// ft_calculate
t_node	*ft_calculate_score(t_node *stack);
int		ft_calc_rank_stack(t_node *stack);
void	ft_calculate_rank(t_node *head_a, t_node *head_b);

// ft_sort_full_elem
t_node	*ft_find_min_rank_b(t_node *head_b);
t_node	*ft_find_min_a_for_min_b(t_node *head_a, t_node *min_rank_b);
void	ft_final_sort(t_node **head_a);
void	ft_b_to_a(t_node **head_a, t_node **head_b);
void	ft_sort_big_arg(t_node **head_a, int *array, int size);

// ft_free
void	ft_error(void);
int		*ft_check_big_arg(int *temp, int *nbr, char **result);
void	ft_free_char(char **str);
void	delete_node(t_node **head);
void	ft_free_stack(t_node **head);

#endif