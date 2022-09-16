/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eof_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:58:35 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/15 12:27:32 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	g_status;

void	eof_exit(t_env *envp)
{
	write(1, "exit\n", 5);
	free_all_env(envp);
	exit(g_status);
}
