/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red_files_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:48:29 by yonamog2          #+#    #+#             */
/*   Updated: 2023/02/20 15:46:15 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * red_output: a function that redirects output
 * @av: the structure containing the cmds and redirections
 * @x: the index of the redirection
*/
int	red_output(t_pipe *av, int x, t_data *proc)
{
	int	file1;

	file1 = open(av[proc->index]. red[x]->red_name,
			O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (file1 == -1)
		terminate(av[proc->index].red[x]->red_name, proc, av);
	if (proc->dont == 0)
		dup2(file1, STDOUT_FILENO);
	close(file1);
	return (1);
}

/**
 * red_infile: a function that redirects input
 * @av: the structure containing the cmds and redirections
 * @x: the index of the redirection
*/
int	red_infile(t_pipe *av, int x, t_data *proc)
{
	int	file1;

	file1 = open(av[proc->index].red[x]->red_name, O_RDONLY);
	if (file1 == -1)
		terminate(av[proc->index].red[x]->red_name, proc, av);
	if (proc->dont == 0)
		dup2(file1, STDIN_FILENO);
	close(file1);
	return (1);
}

/**
 * red_append_mode: a function that redirects output in appaned mode
 * @av: the structure containing the cmds and redirections
 * @x: the index of the redirection
*/
int	red_append_mode(t_pipe *av, int x, t_data *proc)
{
	int	file1;

	file1 = open(av[proc->index].red[x]->red_name, O_RDWR | \
	O_CREAT | O_APPEND, 0777);
	if (file1 == -1)
		terminate(av[proc->index].red[x]->red_name, proc, av);
	if (proc->dont == 0)
		dup2(file1, STDOUT_FILENO);
	close(file1);
	return (1);
}
