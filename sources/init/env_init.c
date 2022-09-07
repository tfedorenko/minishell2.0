/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:23:33 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/07 13:05:21 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*set_init_env(char **env, int i)
{
	int		j;
	t_env	*new;

	i = 0;
	j = 0;
	while (env[i][j] != '=')
		j++;
	new = (t_env *)malloc(sizeof(t_env));
	new->key = ft_substr(env[i], 0, j);
	new->value = ft_substr(env[i], j + 1, ft_strlen(env[i]));
	new->next = NULL;
	return (new);
}

t_env	*env_init(char **env)
{
	int		i;
	t_env	*head;
	t_env	*new_list;
	t_env	*tmp;

	head = NULL;
	tmp = head;
	i = 0;
	while (env[i])
	{
		new_list = set_init_env(env, i);
		if (!head)
		{
			head = new_list;
			tmp = head;
			i++;
			continue ;
		}
		else
			tmp->next = new_list;
		tmp = tmp->next;
		i++;
	}
	return (head);
}
