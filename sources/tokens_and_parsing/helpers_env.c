/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:24:09 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/11 13:52:59 by tfedoren         ###   ########.fr       */
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
		if (ft_strncmp(env->key, target, ft_strlen(target)) == 0)
		{
			real_val = ft_substr(env->value, 0, ft_strlen(env->value));
			break ;
		}
		env = env->next;
	}
	return (real_val);
}

// int	is_general_env_var(char *target, int squote)
// {
// 	if (*target == '$' && (*(target + 1) == '?' || ft_isalpha(*(target + 1)) \
// 						|| ft_isdigit(*(target + 1))) && squote == 0)
// 		return (1);
// 	return (0);
// }

// int	is_home_env_var(char *target, int squote)
// {
// 	if (target[0] == '~' && (ft_strlen(target) == 1 || target[1] == '/') \
// 					&& squote == 0)
// 		return (1);
// 	return (0);
// }
