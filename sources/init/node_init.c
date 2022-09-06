/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:03:54 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/06 21:01:55 by rkultaev         ###   ########.fr       */
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

t_node	*add_node_arr(t_node *head, t_token *target, int iter, t_env *envp)
{
	t_node	*new;
	t_node	*tmp;

	new = init_node(target->type, iter, envp);
	new = add_command_arr(new, target, iter);
	if (head == NULL)
		head = new;
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
