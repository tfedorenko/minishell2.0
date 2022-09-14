/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:36:13 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/14 08:42:10 by rkultaev         ###   ########.fr       */
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
	return (ERROR);
}

int	error_handler_2(t_token **token, t_token **tmp)
{
	if (((*tmp)->next) && (*tmp)->next->type == INPUT)
		return (print_syntax_error(token, ERR_PRT_INPUT));
	else if (((*tmp)->next) && (*tmp)->next->type == TRUNC)
		return (print_syntax_error(token, ERR_PRT_TRC));
	else if (((*tmp)->next) && (*tmp)->next->type == HEREDOC)
		return (print_syntax_error(token, ERR_PRT_HRDC));
	else if (((*tmp)->next) && (*tmp)->next->type == APPEND)
		return (print_syntax_error(token, ERR_PRT_APP));
	else if (((*tmp)->next == NULL) && \
		((*tmp)->type == TRUNC || (*tmp)->type == APPEND || \
			(*tmp)->type == INPUT || (*tmp)->type == HEREDOC))
		return (print_syntax_error(token, ERR_PRT_NL));
	return (SUCCESS);
}

int	error_handler(t_token **token, t_token **tmp)
{
	if ((*tmp)->type == PIPE)
	{
		if ((!(*tmp)->prev || (*tmp)->prev->type != CMD) || \
			(!(*tmp)->next || (*tmp)->next->type == PIPE))
			return (print_syntax_error(token, ERR_PRT_PIPE));
	}
	else if ((*tmp)->type == BREAK)
	{
		if ((!(*tmp)->prev || (*tmp)->prev->type != CMD) || \
			((*tmp)->next && (*tmp)->next->type == BREAK))
			return (print_syntax_error(token, ERR_PRT_BREAK));
	}
	return (error_handler_2(token, tmp));
}
