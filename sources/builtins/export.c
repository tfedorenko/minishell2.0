/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:59:51 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/11 17:58:59 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*set_builtin_env(t_env *env, char *key, char *value)
{
	env = update_env(env, key, value);
	freedom(key);
	freedom(value);
	return (env);
}

char	*set_value(char *str, int delim)
{
	char	*value;

	if (!ft_strchr(str, '='))
		return (NULL);
	value = ft_substr(str, delim + 1, ft_strlen(str));
	return (value);
}

int	find_delim(char *str, int delim)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == delim)
			return (i);
		++i;
	}
	return (i);
}

void	update_envp(t_node *node)
{
	int		i;
	int		delim;
	char	*key;
	char	*value;

	i = 0;
	delim = 1;
	while (node->command[++i])
	{
		delim = find_delim(node->command[i], '=');
		if (delim == 0)
		{
			print_error(ft_strdup("export : "),
				ft_strjoin(node->command[i], ": not a valid identifier\n"), 1);
			continue ;
		}
		key = ft_substr(node->command[i], 0, delim);
		if (invalid_key("export", key))
		{
			freedom(key);
			continue ;
		}
		value = set_value(node->command[i], delim);
		node->env = set_builtin_env(node->env, key, value);
	}
}

void	export(t_node *node)
{
	if (node->command[1] == NULL)
	{
		prompt_sorted_env(node->env);
	}
	else
		update_envp(node);
}
