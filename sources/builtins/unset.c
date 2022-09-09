/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:59:20 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/09 12:18:09 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*unset_env(t_env *env, char *key)
{
	t_env	*tmp;
	t_env	*prev;

	tmp = env;
	prev = NULL;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
		{
			if (prev)
				prev->next = tmp->next;
			else
				env = tmp->next;
			freedom(tmp->key);
			freedom(tmp->value);
			freedom(env);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (env);
}

void	unset(t_node *node)
{
	int	i;

	i = 0;
	while (node && node->command && node->command[++i])
	{
		if (invalid_key("unset", node->command[i]))
			continue ;
		node->env = unset_env(node->env, node->command[i]);
	}
}

