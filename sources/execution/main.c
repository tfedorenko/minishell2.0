/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:14:29 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/02 10:30:49 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	glob_status;



// int	g_stat;

// int	proper_order(t_token *token)
// {
// 	t_token	*tmp;

// 	tmp = token;
// 	while (tmp)
// 	{
// 		if ((tmp->type == TRUNC || tmp->type == APPEND))
// 		{
// 			if (tmp->nxt && tmp->nxt->nxt && tmp->nxt->nxt->type == CMD)
// 				return (0);
// 		}
// 		tmp = tmp->nxt;
// 	}
// 	return (1);
// }

// t_token	*do_parse(char *str, t_env *envp)
// {
// 	t_token	*token;

// 	token = NULL;
// 	token = trim_space(str);
// 	free(str);
// 	token = split_by_sep(token);
// 	token = add_type(token);
// 	token = expand(token, envp);
// 	token = trim_quote(token);
// 	while (!proper_order(token))
// 		token = reorder_token(token);
// 	return (token);
// }

void	minishell(t_env *envp)
{
	char	*line;
	// t_token	*token;
	t_node	*node;

	// token = NULL;
	
	node = NULL;
	line = readline("minishell$ ");
	if (!line)
		eof_exit(envp);
	else if (*line == '\0')
		free(line);
	else
	{
		add_history(line);
		
	}
}

int	main(int argc, char **argv, char **env)
{
	char	*str;
	t_env	*envp;

	argc += 0;
	argv += 0;
	envp = init_env(env);
	glob_status = 0;
	while (1)
	{
		//signal
		minishell(envp);
	}
	return (SUCCESS);
}

