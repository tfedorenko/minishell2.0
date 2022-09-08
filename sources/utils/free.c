/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:22:18 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/08 14:49:43 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free(void *str)
{
	free(str);
	str = NULL;
}

void	free_env(t_env *env)
{
	while (env)
	{
		ft_free(env->key);
		ft_free(env->value);
		ft_free(env);
		env = env->next;
	}
	ft_free(env);
}

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

void	free_all_env(t_env *head)
{
	t_env	*tmp;
	t_env	*pointer;

	if (!head)
		return ;
	tmp = head;
	while (tmp)
	{
		pointer = tmp;
		if (pointer->key)
			free(pointer->key);
		if (pointer->value)
			free(pointer-> value);
		tmp = tmp->next;
		free(pointer);
	}
}
