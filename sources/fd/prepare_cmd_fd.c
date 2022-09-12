/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_cmd_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:26:42 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/12 19:18:39 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*set_command_pipe(t_node *prev, t_node *tmp, t_node *command)
{
	prev->fd[OUT] = tmp->fd[OUT];
	if (command && command->fd[OUT] == 1)
		command->fd[OUT] = tmp->fd[OUT];
	if ((!command || command->type == FAIL) && tmp->fd[OUT] == ERROR)
		close(tmp->fd[OUT]);
	return (NULL);
}

void	set_command_output(t_node *tmp, t_node *command)
{
	if (tmp->next && tmp->next->type == PIPE && tmp->next->fd[OUT] == ERROR)
		my_close(tmp->next->fd[OUT]);
	if (command)
		command->fd[OUT] = tmp->fd[OUT];
}

void	define_command_fd(t_node **command, t_node *prev, t_node *tmp)
{
	if (prev && prev->type == BREAK)
		prev = NULL;
	if (tmp->type == CMD)
		*command = init_command_fd(prev, tmp);
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

int	set_command_fd(t_node *head)
{
	t_node	*tmp;
	t_node	*prev;
	t_node	*command;

	tmp = head;
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
