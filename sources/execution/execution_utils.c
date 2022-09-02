/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:45:17 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/31 14:55:47 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin(int single_command, t_node *node)
{
	if (ft_strcmp(node->command[0], "echo") == 0)
		echo(node);
	else if (ft_strcmp(node->command[0], "cd") == 0)
		cd(node);
	else if (ft_strcmp(node->command[0], "pwd") == 0)
		pwd();
	else if (ft_strcmp(node->command[0], "export") == 0)
		export(node);
	else if (ft_strcmp(node->command[0], "unset") == 0)
		unset(node);
	else if (ft_strcmp(node->command[0], "env") == 0)
		env(node->env);
	else if (ft_strcmp(node->command[0], "exit") == 0)
		my_exit(single_command, node);
}

int	is_builtin(t_node *node)
{
	if (!ft_strcmp(node->command[0], "echo") \
		|| !ft_strcmp(node->command[0], "cd") \
		|| !ft_strcmp(node->command[0], "pwd") \
		|| !ft_strcmp(node->command[0], "export") \
		|| !ft_strcmp(node->command[0], "unset") \
		|| !ft_strcmp(node->command[0], "env") \
		|| !ft_strcmp(node->command[0], "exit"))
		return (1);
	return (0);
}

int	is_single_command(t_node *node)
{
	if (!node->next)
		return (1);
	return (0);
}

void	close_pipes(t_node *node)
{
	t_node	*tmp;

	if (node->prev && node->prev->type == PIPE)
	{
		if (node->prev->fd[IN] > 2)
			my_close(node->prev->fd[IN]);
	}
	tmp = node->next;
	while (tmp)
	{
		if (tmp->type == PIPE)
		{
			if (tmp->prev && tmp->prev->type == CMD)
			{
				if (tmp->fd[OUT] > 2)
					my_close(tmp->fd[OUT]);
				if (tmp->fd[IN] > 2)
					my_close(tmp->fd[IN]);
			}
		}
	tmp = tmp->next;
	}
}

void	my_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == ERROR)
		exit_error("dup2 failed", 1);
}