/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:14:29 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/14 15:52:28 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	glob_status;

void	minishell(t_env *envp)
{
	char	*line;
	t_token	*token;
	t_node	*node;

	token = NULL;
	node = NULL;
	line = readline("minishell$ ");
	if (!line)
	{
		eof_exit(envp);
		exit(0);
	}
	else if (*line == '\0')
		free(line);
	else
	{
		add_history(line);
		token = do_parse(line, envp);
		node = exec_handle_node(&token, envp);
		if (node)
			execute(node);
		free_all_token(token);
		free_all_nodes(node);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_env	*envp;
	t_env	*head;
	int		i;

	i = 0;
	argc = 0;
	argv = 0;
	envp = env_init(&head, env);
	glob_status = 0;
	while (1)
	{
		signals_function();
		minishell(envp);
	}
	return (SUCCESS);
}
