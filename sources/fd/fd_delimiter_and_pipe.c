/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_delimiter_and_pipe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:42:13 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/12 19:09:45 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	glob_status;

int	set_delimiter_fd(t_node *head)
{
	t_node	*tmp;
	int		type;

	tmp = head;
	while (tmp)
	{
		if (tmp->type == INPUT || tmp->type == HEREDOC)
		{
			type = tmp->type;
			if (set_fd_input(head, tmp) == ERROR)
				return (ERROR);
		}
		else if (tmp->type == TRUNC || tmp->type == APPEND)
		{
			if (set_fd_output(head, tmp) == ERROR)
				return (ERROR);
		}
		else if (tmp->type == PIPE)
		{
			pipe(tmp->fd);
			tmp->next->fd[IN] = tmp->fd[IN];
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}