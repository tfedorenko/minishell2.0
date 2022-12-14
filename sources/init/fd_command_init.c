/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_command_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:59:17 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/08 21:00:52 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*init_command_fd(t_node *prev, t_node *command)
{
	if (prev && prev->type > CMD)
		command->fd[IN] = prev->fd[IN];
	if (command->next == NULL)
		command->fd[OUT] = 1;
	return (command);
}
