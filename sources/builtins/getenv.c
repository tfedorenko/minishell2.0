/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:11:36 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/09 11:12:42 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env(t_env *env, char *target)
{
	char	*value;

	value = NULL;
	while (env)
	{
		if (ft_strcmp(env->key, target) == SUCCESS)
		{
			value = ft_substr(env->value, 0, ft_strlen(env->value));
			break ;
		}
		env = env->next;
	}
	return (value);
}

t_env	*make_env(char *key, char *value)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->key = ft_strdup(key);
	if (!value)
		env->value = NULL;
	else
		env->value = ft_strdup(value);
	env->next = NULL;
	return (env);
}

t_env	*add_env(t_env *envp, t_env *env)
{
	t_env	*tmp;

	if (!envp)
		return (env);
	tmp = envp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = env;
	return (envp);
}

t_env	*update_env(t_env *env, char *key, char *value)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == SUCCESS)
		{
			if (!value)
				break ;
			if (tmp->value)
				free(tmp->value);
			tmp->value = ft_strdup(value);
			break ;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		env = add_env(env, make_env(key, value));
	return (env);
}
