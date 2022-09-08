/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:25:57 by hako              #+#    #+#             */
/*   Updated: 2022/09/08 12:58:02 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	connect_cmd(t_token **head, t_token *cmd,
		t_token *arg_start, t_token *redir)
{
	if (cmd)
	{
		cmd->next = arg_start;
		arg_start->prev = cmd;
	}
	else
	{
		if (!redir->prev)
			*head = arg_start;
		else
			redir->prev->next = arg_start;
	}
}

static t_token	*do_reorder_token(t_token **head, t_token *file,
		t_token *redir, t_token *cmd)
{
	t_token	*arg_start;
	t_token	*arg_end;
	t_token	*tmp;

	arg_start = file->next;
	tmp = arg_start;
	while (tmp && tmp->type == CMD)
	{
		arg_end = tmp;
		tmp = tmp->next;
	}
	file->next = tmp;
	if (tmp)
		tmp->prev = file;
	connect_cmd(head, cmd, arg_start, redir);
	arg_end->next = redir;
	redir->prev = arg_end;
	return (arg_end);
}

t_token	*reorder_token(t_token *token)
{
	t_token	*tmp;
	t_token	*cmd;
	t_token	*file;

	tmp = token;
	cmd = NULL;
	while (tmp)
	{
		if (tmp->type == CMD)
			cmd = tmp;
		else if (tmp->type == PIPE || tmp->type == BREAK)
			cmd = NULL;
		else
		{
			file = tmp->next;
			if (!file)
				print_syntax_error(&token,
					"syntax error near unexpected token `newline'\n");
			if (file && file->next && file->next->type == CMD)
				tmp = do_reorder_token(&token, file, tmp, cmd);
		}
		tmp = tmp->next;
	}
	return (token);
}
