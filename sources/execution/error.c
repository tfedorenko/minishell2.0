/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:40:28 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/13 17:09:29 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	glob_status;

void	print_error2(char *message, int status)
{
	write (2, "minishell: ", 11);
	write (2, message, ft_strlen(message));
	glob_status = status;
	freedom(message);
}

void	print_error(char *function, char *msg, int status)
{
	write(2, "minishell: ", 11);
	write (2, function, ft_strlen(function));
	write(2, msg, ft_strlen(msg));
	glob_status = status;
	freedom(function);
	freedom(msg);
}

void	exit_error(char *message, int status)
{
	perror(message);
	glob_status = status;
	exit(glob_status);
}
