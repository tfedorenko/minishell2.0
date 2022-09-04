/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handle_tmp_files.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:08:17 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/31 19:36:26 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int glob_status;

t_list	*add_files(t_list *head, char *file_name)
{
	t_list	*new_file;
	t_list	*tmp;

	new_file = (t_list *)malloc(sizeof(t_list));
	new_file->value = file_name;
	new_file->next = NULL;
	if (head == NULL)
		head = new_file;
	else
	{
		tmp = head;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new_file;
	}
	return (head);
}

void	remove_files(t_list *head)
{
	t_list	*file;
	t_list	*tmp;

	tmp = head;
	while (tmp)
	{
		file = tmp;
		unlink(file->value);
		free(file->value);
		tmp = tmp->next;
		free(file);
	}
}

t_list	*get_files(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_list	*temp_files(char *file_name, int command)
{
	static t_list	*head;

	if (command == GET)
		return (get_files(head));
	else if (command == ADD)
		head = add_files(head, file_name);
	else if (command == DEL)
	{
		remove_files(head);
		head = NULL;
		return (head);
	}
	return (head);
}
