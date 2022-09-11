/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:36:13 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/11 19:12:17 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_stat;

t_token	*open_quote_err(t_token *head);
int		print_syntax_error(t_token **token, const char *msg);
int		error_handler(t_token **token, t_token **tmp);

t_token	*open_quote_err(t_token *head)
{
	printf("minishell: error, unclosed quotes\n");
	g_stat = ERR_SYNTAX;
	free_all_token(head);
	return (NULL);
}

int	print_syntax_error(t_token **token, const char *msg)
{
	printf("minishell: %s", msg);
	g_stat = ERR_SYNTAX;
	free_all_token(*token);
	*token = NULL;
	return (-1);
}

int	error_handler(t_token **token, t_token **tmp)
{
	if ((*tmp)->type == PIPE)
	{
		if ((!(*tmp)->prev || (*tmp)->prev->type != CMD) || \
				(!(*tmp)->next || (*tmp)->next->type == PIPE))
			return (print_syntax_error(token, \
					"syntax error near unexpected token `|'\n"));
	}
	else if ((*tmp)->type == BREAK)
	{
		if ((!(*tmp)->prev || (*tmp)->prev->type != CMD) || \
					((*tmp)->next && (*tmp)->next->type == BREAK))
			return (print_syntax_error(token, \
					"syntax error near unexpected token `;'\n"));
	}
	else if ((*tmp)->type == TRUNC || (*tmp)->type == APPEND || \
					(*tmp)->type == INPUT || (*tmp)->type == HEREDOC)
	{
		if ((!(*tmp)->next) || (*tmp)->next->type > 1)
			return (print_syntax_error(token, \
					"syntax error near unexpected token `newline'\n"));
	}
	return (1);
}
