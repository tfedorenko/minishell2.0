/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 09:42:53 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/25 13:05:53 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	child_process(t_exec *process, int pipes[2])
{
	int	error;

	error = init_fd(process, pipes);
	if (error)
		return (error);
	if (process->path && execve(process->path, \
		process->commands, process->envp) == ERROR)
	{
		close(pipes[0]);
		close(pipes[1]);
		return (ERR_EXECUTION);
	}
	exit(SUCCESS);
}

int	parent_process(t_exec *process)
{
	close(process->stdfd->std_out);
	if (process->prev)
		close(process->prev->stdfd->std_in);
	return (SUCCESS);
}
