/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:00:06 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/02 10:30:33 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_counter(t_env *envp)
{
	int	i;

	i = 0;
	while (envp)
	{
		++i;
		envp = envp->next;
	}
	return (i);
}

char	**env_init(t_env *envp)
{
	int		i;
	char	**envp_ptr;

	i = -1;
	envp_ptr = (char **)malloc (sizeof(char *) * (env_counter(envp) + 1));
	if (!envp_ptr)
		return (NULL);
	while (envp)
	{
		envp_ptr[++i] = ft_strjoin(envp->key, "=");
		envp_ptr[i] = ft_strjoin(envp_ptr[i], envp->value);
		envp = envp->next;
	}
	envp_ptr[++i] = NULL;
	return (envp_ptr);
}

int	args_init(t_node *node, t_exec *arg)
{
	char	**path;

	path = path_to_env(node);
	if (!node->command && !node->command[0])
		return (0);
	arg->argv = node->command;
	arg->file = set_command_path(arg->argv[0], path);
	if (!ft_strchr(node->command[0], '/') && ! arg->file)
	{
		print_error(ft_strdup(node->command[0]), \
					ft_strdup(": command not found\n"), 127);
		return (0);
	}
	arg->env = env_init(node->env);
	free_matrix(path);
	return (1);
}

void	my_execve(char *file, char **argv, char **envp)
{
	if (!argv || !*argv[0] || !file)
		print_error2(ft_strjoin(argv[0], ": command not found\n"), 127);
	else if (execve(file, argv, envp) == ERROR)
		print_error2(ft_strjoin(argvc[0], \
				": No such  file or directory\n"), 127);
}

void	execve_action(t_node *node)
{
	t_exec	arg;

	if (!node->command || ! node->command[0])
		return ;
	if (!args_init(node, &arg))
		return ;
	my_execve(arg.file, arg.argv, arg.envp);
	free_matrix(arg.env);
}

