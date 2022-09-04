/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:26:42 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/02 19:22:37 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

extern int	glob_status;

int	set_fd_input(t_node *head, t_node *file)
{
	if (file->type == INPUT)
	{
		file->fd[IN] = open(file->command[1], O_RDONLY);
		if (file->fd[IN] == ERROR)
		{
			printf("minishell: %s: No such file or directory\n",
				file->command[1]);
			glob_status = ERR_ETC;
			return (1);
		}
	}
	else
		file->fd[IN] = fetch_heredoc_fd(file);
	if (file->type == HEREDOC && glob_status == ERR_ETC)
		free_all_nodes(head);
	return (1);
}

int	set_fd_output(t_node *head, t_node *file)
{
	if (file->type == APPEND)
	{
		file->fd[OUT] = open(file->command[1], O_CREAT | O_WRONLY | O_APPEND);
		if (file->fd[OUT] == ERROR)
		{
			free_all_nodes(head);
			return (0);
		}
	}
	return (1);
}

int	set_delimiter_fd(t_node *node)
{
	t_node	*tmp;
	int		type;

	tmp = node;
	while (tmp)
	{
		if (tmp->type == INPUT || tmp->type == HEREDOC)
		{
			type = tmp->type;
			if (set_fd_input(node, tmp) == 0 \
				|| (type == HEREDOC && glob_status == ERR_ETC))
				return (0);
		}
		else if ((tmp->type == TRUNC || tmp->type == APPEND) \
				&& set_fd_output(node, tmp) == 0)
			return (0);
		else if (tmp->type == PIPE)
		{
			pipe(tmp->fd);
			tmp->next->fd[IN] = tmp->fd[IN];
		}
		tmp = tmp->next;
	}
	return (1);
}

int	set_command_fd(t_node *node)
{
	t_node	*tmp;
	t_node	*prev;
	t_node	*command;

	tmp = node;
	prev = NULL;
	command = NULL;
	while (tmp)
	{
		define_command_fd(&command, prev, tmp);
		prev = tmp;
		tmp = tmp->next;
	}
	return (1);
}
