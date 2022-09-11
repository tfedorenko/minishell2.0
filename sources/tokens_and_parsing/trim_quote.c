/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:35:27 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/10 22:54:23 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*trim_quote(t_token *token);
char	*inside_quote(char *value, int start, int *mid);
void	do_trim_quote(t_token *tmp);

t_token	*trim_quote(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		do_trim_quote(tmp);
		tmp = tmp->next;
	}
	return (token);
}

void	do_trim_quote(t_token *tmp)
{
	int	squote;
	int	dquote;
	int	i;
	int	start;

	i = 0;
	squote = 0;
	dquote = 0;
	start = -1;
	while (tmp->value && tmp->value[i] != '\0')
	{
		check_quote(tmp->value[i], &squote, &dquote);
		if ((tmp->value[i] == '\"' || tmp->value[i] == '\'') \
				&& squote + dquote > 0 && start == -1)
			start = i;
		else if ((tmp->value[i] == '\"' || tmp->value[i] == '\'') && \
				squote + dquote == 0 && start != -1)
		{
			tmp->value = inside_quote(tmp->value, start, &i);
			start = -1;
		}
		i++;
	}
}

char	*inside_quote(char *value, int start, int *mid)
{
	char	*inside;
	char	*head;
	char	*tail;
	char	*str;

	str = ft_substr(value, start + 1, *mid - start - 1);
	head = ft_substr(value, 0, start);
	tail = ft_substr(value, *mid + 1, ft_strlen(value));
	free(value);
	inside = ft_strjoin(head, str);
	*mid = ft_strlen(inside) - 1;
	inside = ft_strjoin_free_s1(inside, tail);
	free(str);
	free(head);
	free(tail);
	return (inside);
}
