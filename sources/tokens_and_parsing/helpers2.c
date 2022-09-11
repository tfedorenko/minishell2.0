/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 23:14:31 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/11 13:51:52 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void	free_token_value(t_token *token);
// t_token	*do_ft_dellist(t_token **head, t_token *tmp);
// void	free_token_value(t_token *token);
// void	free_all_nodes(t_node *head);
// t_node	*init_node(int type, int size, t_env *envp);

// t_token	*ft_dellist(t_token *head, char *target)
// {
// 	t_token	*tmp;

// 	tmp = head;
// 	while (tmp)
// 	{
// 		if (ft_strncmp(tmp->value, target, ft_strlen(target)))
// 			tmp = do_ft_dellist(&head, tmp);
// 		tmp = tmp->next;
// 	}
// 	return (head);
// }

// t_token	*do_ft_dellist(t_token **head, t_token *tmp)
// {
// 	t_token	*del;

// 	if (tmp->prev == NULL)
// 	{
// 		*head = tmp->next;
// 		free_token_value(tmp);
// 		tmp = *head;
// 		tmp->prev = NULL;
// 	}
// 	else if (tmp->next == NULL)
// 	{
// 		tmp = tmp->prev;
// 		free_token_value(tmp->next);
// 		tmp->next = NULL;
// 	}
// 	else
// 	{
// 		del = tmp;
// 		tmp->prev->next = tmp->next;
// 		tmp->next->prev = tmp->prev;
// 		tmp = tmp->prev;
// 		free_token_value(del);
// 	}
// 	return (tmp);
// }

// void	free_token_value(t_token *token)
// {
// 	free(token->value);
// 	free(token);
// }

// void	free_all_nodes(t_node *head)
// {
// 	t_node	*tmp;
// 	t_node	*target_file;
// 	int		i;

// 	if (!head)
// 		return ;
// 	tmp = head;
// 	while (tmp)
// 	{
// 		target_file = tmp;
// 		if (target_file->fd[IN] != ERROR && target_file->fd[IN] != 0)
// 			close(target_file->fd[IN]);
// 		if (target_file->fd[OUT] != ERROR && target_file->fd[OUT] != 1)
// 			close(target_file->fd[OUT]);
// 		if (target_file->command)
// 		{
// 			i = -1;
// 			while (target_file->command[++i])
// 				free(target_file->command);
// 			free(target_file->command);
// 		}
// 	tmp = tmp->next;
// 		free (target_file);
// 	}
// }

// t_node	*init_node(int type, int size, t_env *envp)
// {
// 	t_node	*new;

// 	new = (t_node *)malloc(sizeof(t_node));
// 	new->type = type;
// 	new->command = (char **)malloc(sizeof(char *) * (size + 1));
// 	new->command[size] = NULL;
// 	new->next = NULL;
// 	new->prev = NULL;
// 	new->fd[IN] = 0;
// 	new->fd[OUT] = 1;
// 	new->env = envp;
// 	return (new);
// }
