/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:36:51 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/02 10:30:27 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

extern int	glob_status;

pid_t	command(t_node *node)
{
	pid_t	pid;

	pid = fork();
	if (pid == ERROR)
		exit_error("fork error", 1);
	else if (pid == 0)
	{
		glob_status = 0;
		dup2(node->fd[IN], 0);
		dup2(node->fd[OUT], 1);
		close_pipes(node);
		if (is_builtin(node))
			builtin(MULTI_CMD, node);
		else
			execve_action(node);
		exit(glob_status);
	}
	else
	{
		if (node->fd[IN] != 0)
			my_close(node->fd[IN]);
		if (node->fd[OUT] != 1)
			my_close(node->fd[OUT]);
	}
	return (pid);
}

void	define_status(int child)
{
	glob_status = WEXITSTATUS(child);
	if (WTERMSIG(child) == SIGINT)
		glob_status = WTERMSIG(child) + 128;
	if (WTERMSIG(child) == SIGQUIT)
		glob_status = WTERMSIG(child) + 128;
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

void	execute(t_node *node)
{
	int		nb_child;
	pid_t	pid;

	nb_child = 0;
	if (is_single_command(node) && is_builtin(node))
	{
		if (ft_strcmp(node->command[0], "exit"))
			glob_status = 0;
		builtin(SINGLE_CMD, node);
	}
	else
	{
		while (node)
		{
			if (node->type == CMD && ++nb_child)
				pid = command(node);
			node = node->next;
		}
		wait_child(nb_child, pid);
	}
}

