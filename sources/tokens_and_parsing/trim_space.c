/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:04:47 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/10 22:54:27 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*do_trim_space(t_token *head, char *line, int *start, int i);

t_token	*trim_space(char *line)
{
	t_token	*head;
	int		squote;
	int		dquote;
	int		start;
	int		i;

	start = 0;
	i = 0;
	dquote = 0;
	squote = 0;
	head = NULL;
	while (line[i] != '\0')
	{
		check_quote(line[i], &squote, &dquote);
		if ((line[i] == ' ') && (squote == 0 && dquote == 0))
			head = do_trim_space(head, line, &start, i);
		i++;
		if ((line[i] == '\0') && (squote == 0 && dquote == 0))
			head = do_trim_space(head, line, &start, i);
	}
	if (squote == 1 || dquote == 1)
		return (open_quote_err(head));
	return (head);
}

t_token	*do_trim_space(t_token *head, char *line, int *start, int i)
{
	if (i - (*start) > 0)
		head = add_token(head, ft_substr(line, (*start), i - (*start)));
	(*start) = i + 1;
	return (head);
}
