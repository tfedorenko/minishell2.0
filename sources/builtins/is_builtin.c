/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:29:00 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/06 17:29:11 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	builtin(int single_command, t_node *node)
{
	if (ft_strcmp(node->command[0], "echo") == 0)
		echo(node);
	else if (ft_strcmp(node->command[0], "cd") == 0)
		cd(node);
	else if (ft_strcmp(node->command[0], "pwd") == 0)
		pwd();
	else if (ft_strcmp(node->command[0], "export") == 0)
		export(node);
	else if (ft_strcmp(node->command[0], "unset") == 0)
		unset(node);
	else if (ft_strcmp(node->command[0], "env") == 0)
		env(node->env);
	else if (ft_strcmp(node->command[0], "exit") == 0)
		my_exit(single_command, node);
}

int	is_builtin(t_node *node)
{
	if (!ft_strcmp(node->command[0], "echo") \
		|| !ft_strcmp(node->command[0], "cd") \
		|| !ft_strcmp(node->command[0], "pwd") \
		|| !ft_strcmp(node->command[0], "export") \
		|| !ft_strcmp(node->command[0], "unset") \
		|| !ft_strcmp(node->command[0], "env") \
		|| !ft_strcmp(node->command[0], "exit"))
		return (1);
	return (0);
}