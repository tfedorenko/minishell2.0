/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:36:51 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/23 22:36:49 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	run_process(t_exec *process)
{
	int	pipes[2];

	pipes[0] = -1;
	pipes[1] = -1;
	if (access(process->path, F_OK))
	{
		if (!process->path)
			return (error(process, ERR_CMDNOTFOUND));
		return (error(process, ERR_NOFILE));
	}
	if (access(process->path, X_OK))
		return (error(process, ERR_PERMDENIED));
	if (process->next && pipe(pipes))
		return (error(process, ERR_BROKENPIPE));
	set_fd(process, pipes);
	// if (!process->next && !process->prev)
	// 	return ()
	process->pid = fork();
	if (process->pid == 0)
		child_process(process, pipes);
	else
		parent_process(process);
	return (SUCCESS);
}

int	launch_process(t_exec *process)
{
	int	execution;

	if (!process)
		return (ERR_NOSUCHPROC);
	while (process)
	{
		execution = run_process(process);
		if (execution)
			return (execution);
		process = process->next;
	}
	return (SUCCESS);
}

int	start(int test)
{
	int process = launch_process(test);
	char *command;
	command = chdir(command);
	if (command == ERROR)
}
