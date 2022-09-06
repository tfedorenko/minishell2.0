/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eof_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:58:35 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/05 14:40:32 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	glob_status;

void	eof_exit(t_env *envp)
{
	write(1, "exit\n", 5);
	free_all_env(envp);
	exit(glob_status);
}
