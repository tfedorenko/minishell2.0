/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:08:37 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/11 12:37:47 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*add_type(t_token *token);
void	add_redir_type(t_token *token);

t_token	*add_type(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->value[0] == '>' || tmp->value[0] == '<')
			add_redir_type(tmp);
		else if (tmp->value[0] == '|')
			tmp->type = PIPE;
		else if (tmp->value[0] == ';')
			tmp->type = BREAK;
		else
			tmp->type = CMD;
		tmp = tmp->next;
	}
	return (token);
}

void	add_redir_type(t_token *token)
{
	if (token->value[0] == '>')
	{
		token->type = TRUNC;
		if (token->value[1] == '<')
			token->type = APPEND;
	}
	else if (token->value[0] == '<')
	{
		token->type = INPUT;
		if (token->value[1] == '<')
			token->type = HEREDOC;
	}
}
