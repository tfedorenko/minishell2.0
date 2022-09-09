/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:59:17 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/09 12:02:08 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	swap_env(t_env *left, t_env *right)
{
	t_env	tmp;

	tmp.key = left->key;
	tmp.value = left->value;
	left->key = right->key;
	left->value = right->value;
	right->key = tmp.key;
	right->value = tmp.value;
}

t_env	*sort_envp(t_env *env)
{
	t_env	*tmp;
	t_env	*left;
	t_env	*right;

	tmp = env;
	while (tmp)
	{
		left = tmp;
		right = tmp->next;
		while (right)
		{
			if (ft_strcmp(left->key, right->key) > 0)
				swap_env(left, right);
			right = right->next;
		// printf("%s\n", right->value);
		}
		tmp = tmp->next;
	}
	return (env);
}

t_env	*dupl_env(t_env *env)
{
	t_env	*dupl_env;

	dupl_env = (t_env *)malloc(sizeof(t_env));
	if (!dupl_env)
		return (NULL);
	if (!env)
	{
		dupl_env->key = NULL;
		dupl_env->value = NULL;
		dupl_env->next = NULL;
	}
	else
	{
		dupl_env->key = ft_strdup(env->key);
		dupl_env->value = ft_strdup(env->value);
		dupl_env->next = NULL;
	}
	return (dupl_env);
}

t_env	*dupl_envp(t_env *envp)
{
	t_env	*dupl_envp;
	t_env	*tmp;

	dupl_envp = dupl_env(envp);
	if (dupl_envp->key)
	{
		tmp = dupl_envp;
		while (envp->next)
		{
			envp = envp->next;
			tmp->next = (t_env *)malloc(sizeof(t_env));
			tmp->next->key = ft_strdup(envp->key);
			tmp->next->value = ft_strdup(envp->value);
			tmp->next->next = NULL;
			tmp = tmp->next;
		}
	}
	return (dupl_envp);
}

void	prompt_sorted_env(t_env *envp)
{
	t_env	*tmp;

	tmp = dupl_envp(envp);
	
	tmp = sort_envp(tmp);
	give_all_env(tmp, 1);
	free_dupl_env(tmp);
}
