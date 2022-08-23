/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:15:34 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/22 10:33:24 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	rdrct_read(char *file_name)
{
	int	fd;

	fd = open (file_name, O_RDONLY);
	if (fd < 0 || dup2(fd, 0) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	rdrct_write(char *file_name)
{
	int	fd;

	fd = open (file_name, O_WRONLY | O_CREAT | O_TRUNC);
	if (fd < 0 || dup2(fd, 1) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	rdrct_overwrite(char *file_name)
{
	int	fd;

	fd = open (file_name, O_CREAT | O_WRONLY | O_APPEND, 0664);
	if (fd < 0 || dup2(fd, 1) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	redirect(t_exec *process)
{
	if (process->redirect->read)
		rdrct_read(process->redirect->read);
	if (process->redirect->write)
		rdrct_write(process->redirect->write);
	if (process->redirect->overwrite)
		rdrct_overwrite(process->redirect->overwrite);
	return (SUCCESS);
}
