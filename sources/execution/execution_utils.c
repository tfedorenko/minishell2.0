/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:45:17 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/12 20:27:20 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_single_command(t_node *head)
{
	if (!head->next)
		return (SUCCESS);
	return (ERROR);
}

void	my_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == ERROR)
		exit_error("dup2 failed", 1);
}
