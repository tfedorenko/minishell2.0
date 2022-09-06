/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:31:30 by hako              #+#    #+#             */
/*   Updated: 2022/09/05 11:22:14 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	g_stat;

void	handle_eof_exit(t_env *envp)
{
	write(1, "\033[1A", 4);
	write(1, "\033[11C", 5);
	write(1, "exit\n", 5);
	free_all_env(envp);
	exit(g_stat);
}
