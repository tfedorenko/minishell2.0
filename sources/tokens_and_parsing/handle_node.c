/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:18:00 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/13 18:55:56 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*exec_handle_node(t_token **token, t_env *envp);
t_node	*add_command_arr(t_node *new, t_token *target, int iter);

t_node	*add_node_by_type(t_node *head, t_token **token, \
								t_token **tmp, t_env *envp );

t_node	*get_exec_unit(t_node *head, t_token **token, t_token **tmp, \
															t_env *envp);

t_node	*exec_handle_node(t_token **token, t_env *envp)
{
	t_node	*head;
	t_token	*tmp;

	head = NULL;
	tmp = *token;
	while (tmp)
	{
		head = get_exec_unit(head, token, &tmp, envp);
		if (!head)
		{
			free_all_token(*token);
			*token = NULL;
			return (NULL);
		}
	}
	free_all_token (*token);
	*token = NULL;
	head = launch_fd(head);
	return (head);
}

t_node	*get_exec_unit(t_node *head, t_token **token, t_token **tmp, \
															t_env *envp)
{
	int		i;
	t_token	*start;

	i = 0;
	start = *tmp;
	if ((*tmp)->type == CMD)
	{
		while ((*tmp) && (*tmp)->type == CMD)
		{
			(*tmp) = (*tmp)->next;
			i++;
		}
		head = add_node_arr(head, start, i, envp);
	}
	else
	{
		head = add_node_by_type(head, token, tmp, envp);
		if (!head)
			return (NULL);
	}
	return (head);
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

t_node	*add_node_by_type(t_node *head, t_token **token, \
								t_token **tmp, t_env *envp )
{
	t_token	*start;
	int		is_error;

	start = *tmp;
	if (*token)
	{
		is_error = error_handler(token, tmp);
		if (is_error == ERROR)
		{
			free_all_nodes(head);
			return (NULL);
		}
	}
	if ((*tmp)->type == PIPE)
		head = add_node_arr(head, start, 1, envp);
	else if ((*tmp)->type == BREAK)
		head = add_node_arr(head, start, 1, envp);
	else if ((*tmp)->type == TRUNC || (*tmp)->type == APPEND || \
					(*tmp)->type == INPUT || (*tmp)->type == HEREDOC)
	{
		head = add_node_arr(head, start, 2, envp);
		(*tmp) = (*tmp)->next;
	}
	(*tmp) = (*tmp)->next;
	return (head);
}
