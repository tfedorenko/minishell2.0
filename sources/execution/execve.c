/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:00:06 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/12 21:32:57 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	my_execve(char *path_file, char **argv, char **envp)
{
	if (!argv || !*argv[0] || !path_file)
		print_error2(ft_strjoin(argv[0], ": command not found\n"), 127);
	else if (execve(path_file, argv, envp) == ERROR)
		print_error2(ft_strjoin(argv[0], \
				": no such  file or directory\n"), 127);
}

void	launch_execve(t_node *node)
{
	t_exec	arg;

	if (!node->command || !node->command[0])
		return ;
	if (args_init(node, &arg) == ERROR)
		return ;
	my_execve(arg.file, arg.argv, arg.env);
	free_matrix(arg.env);
}
