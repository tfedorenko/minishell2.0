/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eof_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:58:35 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/02 13:08:20 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	glob_status;

void	eof_exit(t_env *envp)
{
	write(1, "exit\n", 5);
	free_all_env(envp);
	exit(glob_status);
}
