/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:14:29 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/08 13:17:31 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	glob_status;

int	proper_order(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp)
	{
		if ((temp->type == TRUNC) || (temp->type == APPEND))
		{
			 if (temp->next && temp->next->next && temp->next->next->type == CMD)
			 	return (0);
		}
		temp = temp->next;
	}
	return (1);
}

t_token	*do_parse(char *str, t_env *env)
{
	t_token	*token;

	token = NULL;
	token = trim_space(str);
	free(str);
	token = split_by_sep(token);
	token = add_type(token);
	token = expand(token, env);
	token = trim_quote(token);
	while (!proper_order(token))
		token = reorder_token(token);
	return (token);
}

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
		temp_files(NULL, DEL);
	}
}

int	main(int argc, char **argv, char **env)
{
	// char	*str;
	t_env	*envp;
	t_env	*head;

	argc = 0;
	argv = 0;
	envp = env_init(&head, env);
	glob_status = 0;
	while (1)
	{
		signal(SIGINT, sig_int);
		signal(SIGQUIT, SIG_IGN);
		minishell(envp);
	}
	return (SUCCESS);
}
