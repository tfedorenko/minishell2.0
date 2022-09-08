/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:03:54 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/08 13:57:38 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*init_node(int type, int size, t_env *envp)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->type = type;
	new->command = (char **)malloc(sizeof(char *) * (size + 1));
	new->command[size] = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->fd[IN] = 0;
	new->fd[OUT] = 1;
	new->env = envp;
	return (new);
}

t_node	*add_command_node_arr(t_node *new_node, t_token *val, int iter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < iter)
	{
		if (val->value != NULL)
		{
			new_node->command[j] = ft_strdup(val->value);
			// printf("%s\n", val->value);
			j++;
		}
		val = val->next;
		i++;
	}
	new_node->command[j] = NULL;
	return (new_node);
}

t_node	*add_node_arr(t_node **head, t_token *target, int iter, t_env *envp)
{
	t_node	*new_node;
	t_node	*tmp;

	new_node = init_node(target->type, iter, envp);
	new_node = add_command_node_arr(new_node, target, iter);
	if (*head == NULL)
		*head = new_node;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prev = tmp;
	}
	return (*head);
}
