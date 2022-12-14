/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:10:33 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/14 21:50:57 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	args_init(t_node *node, t_exec *args)
{
	char	**path;

	path = path_to_env(node);
	if (!node->command && !node->command[0])
	{
		free_matrix(path);
		return (ERROR);
	}
	args->argv = node->command;
	args->file = set_command_path(args->argv[0], path);
	if (!ft_strchr(node->command[0], '/') && !args->file)
	{
		print_error(ft_strdup(node->command[0]), \
					ft_strdup(": command not found\n"), 127);
		free_matrix(path);
		return (ERROR);
	}
	args->env = env_init_arr(node->env);
	free_matrix(path);
	return (SUCCESS);
}
