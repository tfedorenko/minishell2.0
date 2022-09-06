/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:28:58 by hako              #+#    #+#             */
/*   Updated: 2022/09/06 10:15:24 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*add_token(t_token *head, char *value)
{
	t_token	*new;
	t_token	*tmp;

	new = (t_token *)malloc(sizeof(t_token));
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	if (head == NULL)
	{
		head = new;
		head->prev = NULL;
		tmp = head;
	}
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	return (head);
}

void	add_redir_type(t_token *token)
{
	if (token->value[0] == '>')
	{
		token->type = TRUNC;
		if (token->value[1] == '>')
			token->type = APPEND;
	}
	else if (token->value[0] == '<')
	{
		token->type = INPUT;
		if (token->value[1] == '<')
			token->type = HEREDOC;
	}
}

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
			tmp->type = END;
		else
			tmp->type = CMD;
		tmp = tmp->next;
	}
	return (token);
}

t_node	*add_command_arr(t_node *new, t_token *target, int iter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < iter)
	{
		if (target->value != NULL)
		{
			new->command[j] = ft_strdup(target->value);
			j++;
		}
		target = target->next;
		i++;
	}
	new->command[j] = NULL;
	return (new);
}
