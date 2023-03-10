/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_cmd_proccess.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:03:36 by yonamog2          #+#    #+#             */
/*   Updated: 2023/02/20 16:48:23 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * check_built_ins_and_exexute_one_cmd: check if the 
 * command is one of the built ins 
 * and execute that but now its for one command only
 * @proc: struct that have all the variables i use
 * @av: structure of the commands
 * @envp: 2d array conataining the environment variables 
*/
void	check_built_ins_and_exexute_one_cmd(t_data *proc, \
t_pipe *av, char **envp)
{
	(void)envp;
	if (proc->check == 1)
		ft_exit(av, proc);
	else if (proc->check == 2)
		ft_echo(av, proc, envp);
	else if (proc->check == 3)
		ft_cd(av, proc);
	else if (proc->check == 4)
		ft_pwd(proc, av, envp);
	else if (proc->check == 5)
		ft_env_print_linked(proc, av);
	else if (proc->check == 6)
		ft_export_print_linked(av, proc);
	else if (proc->check == 7)
		ft_unset(av, proc);
	exit(1);
}

void	check_and_execute(t_data *proc, t_pipe *av, char **envp, char *tmp)
{
	if (av->cmd && tmp && av->cmd[0])
	{
		execve(tmp, av->arg, envp);
		free_func_one_cmd(av, proc, envp);
	}
	else
		cmd_not_found(av, proc, 0);
}

/**
 * one_cmd_process: a function that execute one command
 * @proc: struct that have all the variables i use
 * @av: structure of the commands
 * @envp: 2d array conataining the environment variables 
*/
void	one_cmd_process(t_data *proc, t_pipe *av, char **envp)
{
	char	*tmp;

	proc->envp = envp;
	proc->id = fork();
	if (proc->id < 0)
		terminate("fork", proc, av);
	if (proc->id == 0)
	{
		if (av->red_len > 0)
			red_one_cmd(av, proc);
		if (av->cmd == NULL)
		{
			comb_free(av, proc);
			exit(0);
		}
		proc->check = ft_check_builtin(av->cmd);
		if (proc->check > 0)
			check_built_ins_and_exexute_one_cmd(proc, av, envp);
		tmp = parsing(proc, envp, av->cmd);
		check_and_execute(proc, av, envp, tmp);
	}
}

/**
 * set_signal_exe: set the singal and execute for one cmd
 * @proc: struct that have all the variables i use
 * @av: structure of the commands
 * @envp: 2d array conataining the environment variables 
*/
int	set_signal_exe(t_pipe *av, t_data *proc, char **envp)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, child_signal_handler);
	signal(SIGQUIT, child_signal_handler);
	one_cmd_process(proc, av, envp);
	waitpid(-1, &proc->err_no, 0);
	if (WIFEXITED(proc->err_no))
		return (WEXITSTATUS(proc->err_no));
	else if (WIFSIGNALED(proc->err_no))
		return (WTERMSIG(proc->err_no) + 128);
	return (0);
}

/**
 * pipex_one_cmd: execute and return err_code for one cmd
 * @av: a structure that contains the whole variables
 * @proc: a struture which contains the command and redirection
 * @envp: the environment variable
*/
int	pipex_one_cmd(t_pipe *av, t_data *proc, char **envp)
{
	proc->index = 0;
	proc->envp = envp;
	if (av[0].cmd && ft_strcmp(av[0].cmd, "cd") == 0)
		return (do_operation(proc, av), ft_cd(av, proc));
	else if (av[0].cmd && ft_strcmp(av[0].cmd, "exit") == 0)
	{
		do_operation(proc, av);
		ft_exit(av, proc);
		return (1);
	}
	else if (av[0].cmd && ft_strcmp(av[0].cmd, "unset") == 0)
		return (do_operation(proc, av), ft_unset(av, proc));
	else if (av[0].cmd && ft_strcmp(av[0].cmd, "export") == 0)
		return (do_operation(proc, av), ft_export_print_linked(av, proc));
	else
		return (set_signal_exe (av, proc, envp));
	return (0);
}
