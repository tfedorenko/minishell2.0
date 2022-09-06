/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:24:04 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/05 11:26:18 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	give_all_env(t_env *env, int prefix)
{
	while (env)
	{
		if (prefix && !ft_strcmp("_", env->key))
			env = env->next;
		else if (prefix && env->value && *env->value)
			printf("declare -x %s=\"%s\"\n", env->key, env->value);
		else if (prefix && env->value)
			printf ("declare -x %s=\"\"\n", env->key);
		else if (prefix)
			printf("declare -x %s\n", env->key);
		else if (env->value && env->value)
			printf ("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}

void	env(t_env *env)
{
	give_all_env(env, 0);
}
