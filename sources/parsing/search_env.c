/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:24:41 by hako              #+#    #+#             */
/*   Updated: 2022/09/03 15:19:08 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
