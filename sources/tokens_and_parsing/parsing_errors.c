/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:36:13 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/13 21:26:30 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	glob_status;

t_token	*open_quote_err(t_token *head);
int		print_syntax_error(t_token **token, const char *msg);
int		error_handler(t_token **token, t_token **tmp);

t_token	*open_quote_err(t_token *head)
{
	printf("minishell: error, unclosed quotes\n");
	glob_status = ERR_SYNTAX;
	free_all_token(head);
	return (NULL);
}

int	print_syntax_error(t_token **token, const char *msg)
{
	printf("minishell: %s", msg);
	glob_status = ERR_SYNTAX;
	free_all_token(*token);
	*token = NULL;
	return (-1);
}

static int delimit_type(t_token **token, t_token **tmp)
{
	// if ((*tmp)->type == INPUT && ((*tmp)->next->type == INPUT))
	// 	return (print_syntax_error(token, \
	// 				"syntax error near unexpected token `<'\n"));
	// else if ((*tmp)->type == TRUNC && ((*tmp)->next->type == TRUNC))
	// 	return (print_syntax_error(token, \
	// 				"syntax error near unexpected token `>'\n"));
	// else if ((*tmp)->type == HEREDOC && ((*tmp)->next->type == HEREDOC))
	// 	return (print_syntax_error(token, \
	// 				"syntax error near unexpected token `<<'\n"));
	// else if ((*tmp)->type == APPEND && ((*tmp)->next->type == APPEND))
	// 	return (print_syntax_error(token, \
	// 				"syntax error near unexpected token `>>'\n"));
		if ((*tmp)->next->type == INPUT)
		return (print_syntax_error(token, \
					"syntax error near unexpected token `<'\n"));
	else if ((*tmp)->next->type == TRUNC)
		return (print_syntax_error(token, \
					"syntax error near unexpected token `>'\n"));
	else if ((*tmp)->next->type == HEREDOC)
		return (print_syntax_error(token, \
					"syntax error near unexpected token `<<'\n"));
	else if ((*tmp)->next->type == APPEND)
		return (print_syntax_error(token, \
					"syntax error near unexpected token `>>'\n"));
		return (1);
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
	// else if (delimit_type(token, tmp))
	else if ((*tmp)->type == TRUNC || (*tmp)->type == APPEND || \
					(*tmp)->type == INPUT || (*tmp)->type == HEREDOC)
	{
		if (delimit_type(token, tmp) == 9 && ((!(*tmp)->next) || (*tmp)->next->type > 1))
			
		// else i.f ((!(*tmp)->next) || (*tmp)->next->type > 1)
			return (print_syntax_error(token, \
					"syntax error near unexpected token `newline'\n"));
	}

	return (1);
}
