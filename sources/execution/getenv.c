/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:11:36 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:02 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	env_compare(char *s1, char *s2)
{
	while (*s1 && *s1 != '=' && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 == '=' && !*s2);
}

char	test_getenv(char *name, t_env *env)
{
	int		i;
	char	*env_name;

	if (!env || !name)
		return (NULL);
	while (env)
	{
		i = 0;
		env_name = (char *)env->fullstr;
		if (!env_name)
			continue ;
		while (env_name[i] && env_name[i] != '=')
			i++;
		if (env_name[i] && env_compare(env_name, name))
			return (env_name + ++i);
		env = env->next;
	}
}

