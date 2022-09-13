/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:11:23 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/13 20:33:59 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*join_list_back(t_token *pos, int sep_size, int *index, int size);
t_token	*join_list_center(t_token *pos, int sep_size, int *index, int size);
void	free_all_token(t_token *head);
t_token	*add_token(t_token *head, char *value);
char	*ft_strjoin_free_s1(char *s1, char *s2);

t_token	*add_token(t_token *head, char *value)
{
	t_token	*new;
	t_token	*tmp;	

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	if (head == NULL)
	{
		head = new;
		head->prev = NULL;
		tmp = head;
	}
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	return (head);
}

t_token	*join_list_center(t_token *pos, int sep_size, int *index, int size)
{
	t_token	*separated;
	char	*tmp;

	separated = malloc(sizeof(t_token) * sep_size);
	if (!separated)
		return (NULL);
	separated->value = ft_substr(pos->value, *index, sep_size);
	separated->next = pos->next;
	pos->next->prev = separated;
	pos->next = separated;
	separated->prev = pos;
	pos = pos->next;
	separated = malloc(sizeof(t_token));
	if (!separated)
		return (NULL);
	separated->value = ft_substr(pos->prev->value, *index + sep_size, size);
	separated->next = pos->next;
	pos->next->prev = separated;

	pos->next = separated;
	
	separated->prev = pos;
	tmp = pos->prev->value;
	pos->prev->value = ft_substr(tmp, 0, *index);
	free(tmp);
	if (sep_size == 2)
		(*index)++;
	return (pos);
}

t_token	*join_list_back(t_token *pos, int sep_size, int *index, int size)
{
	t_token	*separated;
	char	*tmp;

	separated = malloc(sizeof(t_token));
	if (!separated)
		return (NULL);
	separated->value = ft_substr(pos->value, *index, sep_size);
	pos->next = separated;
	separated->prev = pos;
	separated->next = NULL;
	pos = pos->next;
	separated = malloc(sizeof(t_token));
	separated->value = ft_substr(pos->prev->value, *index + sep_size, size);
	pos->next = separated;
	separated->prev = pos;
	separated->next = NULL;
	tmp = pos->prev->value;
	pos->prev->value = ft_substr(tmp, 0, *index);
	free(tmp);
	if (sep_size == 2)
		(*index)++;
	return (pos);
}

char	*ft_strjoin_free_s1(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	s1 = ft_strjoin(s1, s2);
	free(tmp);
	tmp = NULL;
	return (s1);
}
