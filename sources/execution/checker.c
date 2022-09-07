/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:24:03 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/07 13:02:54 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**path_to_env(t_node *node)
{
	char	**path;
	t_env	*envp;

	path = NULL;
	envp = node->env;
	while (envp)
	{
		if (ft_strncmp(envp->key, "PATH", 4) == 0)
		{
			path = ft_split((envp->value), ':');
			return (path);
		}
		envp = envp->next;
	}
	free_matrix(path);
	return (NULL);
}

char	*set_command_path(char *command, char **paths)
{
	char	*tmp_cmd;
	char	*command_path_with_slash;
	int		i;
	int		fd;

	i = -1;
	// if (ft_strchr(command, '/'))
	// 	return (command);
	while (paths && paths[++i])
	{
		tmp_cmd = ft_strjoin("/", command);
		command_path_with_slash = ft_strjoin(paths[i], tmp_cmd);
		fd = open(command_path_with_slash, O_EXCL);
		if (fd > 0)
		{
			close(fd);
			free(tmp_cmd);
			return (command_path_with_slash);
		}
		close(fd);
		free(tmp_cmd);
		free(command_path_with_slash);
	}
	return (NULL);
}
