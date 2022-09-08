/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:36:21 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/08 19:36:26 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_all_nodes(t_node *head)
{
	t_node	*tmp;
	// t_node	*target_file
	// t_node	*target_file;
	int		i;

	if (!head)
		return ;
	// tmp = head;
	while (head)
	{
		// target_file = tmp;
		if (head->fd[IN] != ERROR && head->fd[IN] != 0)
			close(head->fd[IN]);
		if (head->fd[OUT] != ERROR && head->fd[OUT] != 1)
			close(head->fd[OUT]);
		if (head->command)
		{
			i = -1;
			while (head->command[++i])
				free(head->command[i]);
			tmp = head;
			free(head->command);
		}
		tmp = head->next;
		free (head);
		head = tmp;
	}
}
