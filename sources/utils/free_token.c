/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:18:57 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/06 15:15:25 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_token_value(t_token *token)
{
	free(token->value);
	free(token);
}

t_token	*do_ft_dellist(t_token **head, t_token *tmp)
{
	t_token	*del;

	if (tmp->prev == NULL)
	{
		*head = tmp->next;
		free_token_value(tmp);
		tmp = *head;
		tmp->prev = NULL;
	}
	else if (tmp->next == NULL)
	{
		tmp = tmp->prev;
		free_token_value(tmp->next);
		tmp->next = NULL;
	}
	else
	{
		del = tmp;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		tmp = tmp->prev;
		free_token_value(del);
	}
	return (tmp);
}

t_token	*ft_dellist(t_token *head, char *target)
{
	t_token	*tmp;

	tmp = head;
	while (tmp)
	{
		if (ft_strcmp(tmp->value, target) == 0)
			tmp = do_ft_dellist(&head, tmp);
		tmp = tmp->next;
	}
	return (head);
}

void	free_all_token(t_token *head)
{
	t_token	*target;
	t_token	*tmp;

	if (!head)
		return ;
	tmp = head;
	while (tmp)
	{
		target = tmp;
		if (target->value)
			free(target->value);
		tmp = tmp->next;
		free(target);
	}
}