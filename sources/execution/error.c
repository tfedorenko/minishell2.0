/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:40:28 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/15 12:27:57 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

void	print_error2(char *message, int status)
{
	write (2, "minishell: ", 11);
	write (2, message, ft_strlen(message));
	g_status = status;
	freedom(message);
}

void	print_error(char *function, char *msg, int status)
{
	write(2, "minishell: ", 11);
	write (2, function, ft_strlen(function));
	write(2, msg, ft_strlen(msg));
	g_status = status;
	freedom(function);
	freedom(msg);
}

void	exit_error(char *message, int status)
{
	perror(message);
	g_status = status;
	exit(g_status);
}
