/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 23:06:48 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/15 12:28:15 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

static void	fd_descriptor(t_node *node)
{
	if (node->fd[IN] != 0 && node->fd[IN] != ERROR)
		my_close(node->fd[IN]);
	if (node->fd[OUT] != 1 && node->fd[OUT] != ERROR)
		my_close(node->fd[OUT]);
}

pid_t	command(t_node *node)
{
	pid_t	pid;

	signals_function_cat();
	pid = fork();
	if (pid == ERROR)
		exit_error("fork error", 1);
	else if (pid == 0)
	{
		g_status = 0;
		dup2(node->fd[IN], 0);
		dup2(node->fd[OUT], 1);
		close_pipes(node);
		if (is_builtin(node) == SUCCESS)
			builtin(MULTI_CMD, node);
		else
			launch_execve(node);
		exit(g_status);
	}
	else
		fd_descriptor(node);
	return (pid);
}

void	define_status(int child)
{
	g_status = WEXITSTATUS(child);
	if (WTERMSIG(child) == SIGINT)
		g_status = WTERMSIG(child) + 128;
	if (WTERMSIG(child) == SIGQUIT)
		g_status = WTERMSIG(child) + 128;
}

void	wait_child(int nb_child, int pid)
{
	int	i;
	int	result;
	int	child;

	i = 0;
	result = 0;
	while (i < nb_child)
	{
		if (wait(&child) == pid)
			result = child;
		i++;
	}
	if (nb_child > 0)
		define_status(result);
}

void	execute(t_node *process)
{
	int		child_counter;
	pid_t	pid;

	child_counter = 0;
	if (is_single_command(process) == SUCCESS && is_builtin(process) == SUCCESS)
	{
		if (ft_strcmp(process->command[0], "exit"))
			g_status = 0;
		builtin(SINGLE_CMD, process);
	}
	else
	{
		while (process)
		{
			if (process->type == CMD && ++child_counter)
			{
				pid = command(process);
			}
			process = process->next;
		}
		wait_child(child_counter, pid);
	}
}
