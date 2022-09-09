/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_in_out_fds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:43:30 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/09 08:27:39 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
			// glob_status = ERR_ETC;
			return (ERROR);
		}
	}
	else
		file->fd[IN] = fetch_heredoc_fd(file);
	if (file->type == HEREDOC && glob_status == ERR_ETC)
		free_all_nodes(head);
	return (SUCCESS);
}

int	set_fd_output(t_node *head, t_node *file)
{
	if (file->type == APPEND)
	{
		file->fd[OUT] = open(file->command[1], O_CREAT | O_WRONLY | O_APPEND);
		if (file->fd[OUT] == ERROR)
		{
			free_all_nodes(head);
			return (ERROR);
		}
	}
	else if (file->type == TRUNC)
	{
		file->fd[OUT] = open(file->command[1], O_CREAT | O_WRONLY | O_APPEND);
		if (file->fd[OUT] == ERROR)
		{
			free_all_nodes(head);
			return (ERROR);
		}
	}
	return (SUCCESS);
}
