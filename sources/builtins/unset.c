/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:59:20 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/02 10:29:37 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			ft_free(tmp->key);
			ft_free(tmp->value);
			ft_free(env);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (env);
}

int	invalid_key(char *function, char *key)
{
	int	i;

	if (ft_strlen(key) == 1 && key[0] == '_')
		return (0);
	i = -1;
	while (key[++i])
	{
		if (!ft_isalpha(key[i]) && key[i] != '_')
		{
			if (i > 0 && ft_isdigit(key[i]))
				continue ;
			print_error(ft_strjoin(function, ": "),
				ft_strjoin(key, ": not a valid identifier\n"), 1);
			return (1);
		}
	}
	return (0);
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

