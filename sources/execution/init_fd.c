/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:26:42 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:08 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	init_fd(t_exec *process, int pipes[2])
{
	int	outcome;

	(void)pipes;
	outcome = redirect(process);
	if (outcome)
		return (outcome);
	if (process->prev && !process->redirect->read && \
		dup2(process->prev->stdfd->std_in, 0) == ERROR)
		return (ERROR);
	if (process->next && !process->redirect->write && \
		dup2(process->stdfd->std_out, 1) == ERROR)
		return (ERROR);
	return (outcome);
}

int	set_fd(t_exec *process, int pipes[2])
{
	process->stdfd->std_in = -1;
	process->stdfd->std_out = -1;
	if (process->next)
	{
		process->stdfd->std_in = pipes[0];
	}
	process->stdfd->std_in = pipes[0];
	process->stdfd->std_out = pipes[1];
}
