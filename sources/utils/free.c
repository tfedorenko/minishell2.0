/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:22:18 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/01 15:04:55 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	free_all_nodes(t_node *head)
{
	t_node	*tmp;
	t_node	*target_file;
	int		i;

	if (!head)
		return ;
	tmp = head;
	while (tmp)
	{
		if (target_file->fd[IN] != -1 && target_file->fd[IN] != 0)
			close(target_file->fd[IN]);
		if (target_file->fd[OUT] != -1 && target_file->fd[OUT] != 1)
			close(target_file->fd[OUT]);
		if (target_file->command)
		{
			i = -1;
			while (target_file->command[++i])
				free(target_file->command[i]);
			free(target_file->command);
		}
	tmp = tmp->next;
		free (target_file);
	}
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

// void	free_env_all(t_env *head)
// {
// 	t_env	*tmp;
// 	t_env	*target;

// 	if (!head)
// 		return ;
// 	tmp = head;
// 	while (tmp)
// 	{
// 		target = tmp;
// 		if (target->key)
// 			free(target->key);
// 		if (target->value)
// 			free(target->value);
// 		tmp = tmp->nxt;
// 		free(target);
// 	}
// }
