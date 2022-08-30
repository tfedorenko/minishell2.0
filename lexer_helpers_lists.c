/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_helpers_lists.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:46:58 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/30 18:51:27 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list_element	*new_node(int key, char *value)
{
	t_list_element	*new_node;

	new_node = (t_list_element *)malloc(sizeof(t_list_element));
	if (!new_node)
		return (NULL);
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

t_minishell	*new_minishell_list(void)
{
	t_minishell *list;
	
	list = (t_minishell *)malloc(sizeof(t_minishell));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->size_of_list = 0;
	return(list);
}

t_chunk_info *chunk_info_new(int s, int e)
{
	t_chunk_info *ci;
	
	ci = (t_chunk_info *)malloc(sizeof(t_chunk_info));
	if (ci == NULL)
		return (NULL);
	ci->e = e,
	ci->s = s;
	return (ci);
}

int push_to_list(t_minishell *list, void *key, void *value)
{
	t_list_element *ptr;
	
	if (!list)
		return (1);
	if (!list->head)
	{
		list->head = new_node(key, value);
		if (list->head)
			++(list->size_of_list);
		return (list->head == NULL);
	}
	ptr = list->head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new_node(key, value);
	if (ptr->next)
		++(list->size_of_list);
	// ft_printf("test4\n");
	return (ptr->next == NULL);
}

void *minishell_list_getval(t_minishell *list, int *key)
{
	t_list_element *ptr;
	
	if (!list || list->size_of_list == 0)
		return (NULL);
	ptr = list->head;
	while(ptr)
	{
		if(key == ptr->key)
			return (ptr->value);
		ptr = ptr->next;
	}
	return (NULL);
}

void minishell_list_free(t_minishell *list)
{
	t_list_element *elem;
	t_list_element *elem_next;

	if (!list)
		return ;
	elem = list->head;
	while (elem != NULL)
	{
		free(elem);
		elem = elem_next;
	}
	free(list);
}

void	print_list(t_minishell *list)
{
	
	if (!list)
		return ;
	// ft_printf("test4\n");	
	while (list->head->next != NULL)
	{
		// ft_printf("test1\n");
		ft_printf("Key =%i, Value =%s\n", list->head->key, list->head->value);
		list->head = (list->head->next);
	}
	if (list->head->key)
	{
		// ft_printf("test2\n");
		ft_printf("Key =%i, Value =%s\n", list->head->key, list->head->value);
	}
	ft_printf("\n");
}


void list_free_wrapper(void *list)
{
	minishell_list_free((t_minishell *)list);
}

t_group *group_new(int type)
{
	t_group	*g;

	g = (t_group *)malloc(sizeof(t_group));
	if (!g)
		return (NULL);
	g->type = type;
	g->cmds = new_minishell_list();
	g->files = new_minishell_list();
	if (NULL == g->cmds || NULL == g->files)
	{
		if (g->cmds)
			minishell_list_free(g->cmds);
		if (g->files)
			minishell_list_free(g->files);
		free(g);
		return (NULL);
	}
	return (g);
}

void group_free(void *group)
{
	t_list_element *ptr;
	
	ptr = ((t_group *)group)->files->head;
	while (ptr)
	{
		unlink(ptr->value);
		ptr = ptr->next;
	}
	minishell_list_free(((t_group *)group)->cmds);
	minishell_list_free(((t_group *)group)->files);
	free(group);
}
