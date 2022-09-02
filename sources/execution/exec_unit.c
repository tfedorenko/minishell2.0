/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:15:17 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/02 10:30:18 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*new_node(int type, int size, t_env *envp)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->type = type;
	new->command = (char **)malloc(sizeof(t_node));
	new->command[size] = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->fd[IN] = 0;
	new->fd[OUT] = 1;
	new->env = envp;
	return (new);
}

// t_node	*add_coand_matrix(t_node *new, t_token *token, int counter)
// {
// 	int	i;
// 	int	j;
	
// 	i = 0;
// 	j = 0;
// 	while (i < counter)
// 	{
// 		if (token->val)
// 	}
// }

