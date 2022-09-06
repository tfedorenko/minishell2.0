/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:21:46 by hako              #+#    #+#             */
/*   Updated: 2022/09/06 18:31:26 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int g_stat;

t_token *open_quote_err(t_token *head)
{
	printf("minishell: open quotation syntax error\n");
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
		if ((!(*tmp)->prev || (*tmp)->prev->type != CMD) || (!(*tmp)->next || (*tmp)->next->type == PIPE))
			return (print_syntax_error(token,
				"syntax error near unexpected token `|'\n"));
	}
	else if ((*tmp)->type == END)
	{
		if ((!(*tmp)->prev || (*tmp)->prev->type != CMD) || ((*tmp)->next && (*tmp)->next->type == END))
			return (print_syntax_error(token,
				"syntax error near unexpected token `;'\n"));
	}
	else if ((*tmp)->type == TRUNC || (*tmp)->type == APPEND || (*tmp)->type == INPUT || (*tmp)->type == HEREDOC)
	{
		if ((!(*tmp)->next) || ((*tmp)->next->type > 1))
			return (print_syntax_error(token,
				"syntax error near unexpected token `newline'\n"));
	}
	return (1);
}
