/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:51:00 by yonamog2          #+#    #+#             */
/*   Updated: 2023/02/20 16:47:14 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * handler_signal: a function to handle signal calls
 * @num: number of the signal status
*/
void	handler_signal(int num)
{
	if (num == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("  \n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_err_code = 1;
	}
}

void	child_signal_handler(int num)
{
	if (num == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		g_err_code = 130;
	}
	else if (num == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", 2);
		g_err_code = 130;
	}
}

void	do_operation(t_data *proc, t_pipe *av)
{
	proc->dont = 1;
	if (av->red_len > 0)
		red_one_cmd(av, proc);
}
