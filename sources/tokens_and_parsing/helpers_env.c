/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:24:09 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/13 16:01:24 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*search_env(t_env *env, char *target);
int		is_general_env_var(char *target, int squote);
int		is_home_env_var(char *target, int squote);

char	*search_env(t_env *env, char *target)
{
	char	*real_val;

	real_val = NULL;
	while (env)
	{
		if (ft_strcmp(env->key, target) == 0)
		{
			real_val = ft_substr(env->value, 0, ft_strlen(env->value));
			break ;
		}
		env = env->next;
	}
	return (real_val);
}
