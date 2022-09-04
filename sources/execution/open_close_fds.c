/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_fds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:48:35 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/02 19:57:29 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_close(int fd)
{
	if (close(fd) == ERROR)
		exit_error("close failed", 1);
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
