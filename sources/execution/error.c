/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:40:28 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/22 12:02:15 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_error(t_exec *process, int status)
{
	char	*name;

	name = process->name;
	if (!name)
		name = "minishell";
	if (status == ERR_NOTPERMTD)
		printf("%s: %s\n", name, E_NOTPERMTD);
	else if (status == ERR_NOSUCHPROC)
		printf("%s: %s\n", name, E_NOSUCHPROC);
	else if (status == ERR_EXECUTION)
		printf("%s: %s\n", name, E_EXECUTION);
	else if (status == ERR_CMDNOTFOUND)
		printf("%s: %s\n", name, E_CMDNOTFOUND);
	else if (status == ERR_NOFILE)
		printf("%s: %s\n", E_NOFILE, process->path);
	else if (status == ERR_RUNPROC)
		printf("%s: %s\n", name, E_RUNPROC);
	else if (status == ERR_ISDIR)
		printf("%s: %s\n", name, E_ISDIR);
	else if (status == ERR_NODIR)
		printf("%s: %s\n", name, E_NODIR);
	else if (status == ERR_NOSUCHPROC)
		printf("%s: %s\n", name, E_NOSUCHPROC);
	else if (status == ERR_BROKENPIPE)
		printf ("%s: %s\n", name, E_BROKENPIPE);
}

int	error(t_exec *process, int status)
{
	if (!process)
		return (ERROR);
	print_error(process, status);
	return (status);
}
