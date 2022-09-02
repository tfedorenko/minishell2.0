/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:55:42 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/02 10:29:45 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*set_command_pipe(t_node *prev, t_node *tmp, t_node *command)
{
	prev->fd[OUT] = tmp->fd[OUT];
	if (command && command->fd[OUT] == 1)
		command->fd[OUT] = tmp->fd[OUT];
	if (!command || command->type == FAIL)
		close(tmp->fd[OUT]);
	return (NULL);
}

void	set_command_output(t_node *tmp, t_node *command)
{
	if (tmp->next && tmp->next->type == PIPE)
		my_close(tmp->next->fd[OUT]);
	if (command)
		command->fd[OUT] = tmp->fd[OUT];
}

t_node	*init_command(t_node *prev, t_node *command)
{
	if (prev && prev->type > CMD)
		command->fd[IN] = prev->fd[IN];
	if (command->next == NULL)
		command->fd[OUT] = 1;
	return (command);
}

void	define_command_fd(t_node **command, t_node *prev, t_node *tmp)
{
	if (prev && prev->type == END)
		prev = NULL;
	if (tmp->type == CMD)
		*command = init_command(prev, tmp);
	if (*command && (tmp->type == INPUT || tmp->type == HEREDOC))
	{
		if (tmp->fd[IN] == -1)
			(*command)->type = FAIL;
		(*command)->fd[IN] = tmp->fd[IN];
	}
	if (tmp->type == TRUNC || tmp->type == APPEND)
		set_command_output(tmp, *command);
	if (prev && tmp->type == PIPE)
		(*command) = set_command_pipe(prev, tmp, *command);
}

t_node	*get_fd(t_node *node)
{
	if (!set_delimiter_fd(node))
		return (NULL);
	set_command_fd(node);
	return (node);
}

