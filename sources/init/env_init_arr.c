/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:23:33 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/06 17:25:48 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env_counter_arr(t_env *envp)
{
	int	i;

	i = 0;
	while (envp)
	{
		++i;
		envp = envp->next;
	}
	return (i);
}

char	**env_init_arr(t_env *envp)
{
	int		i;
	char	**envp_ptr;

	i = -1;
	envp_ptr = (char **)malloc (sizeof(char *) * (env_counter_arr(envp) + 1));
	if (!envp_ptr)
		return (NULL);
	while (envp)
	{
		envp_ptr[++i] = ft_strjoin(envp->key, "=");
		envp_ptr[i] = ft_strjoin(envp_ptr[i], envp->value);
		envp = envp->next;
	}
	envp_ptr[++i] = NULL;
	return (envp_ptr);
}