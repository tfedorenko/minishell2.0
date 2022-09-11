/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_sep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:59:18 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/11 12:38:21 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*split_by_sep(t_token *token);
t_token	*do_split_by_seps(t_token *pos, int sep_size, int *index, int size);
t_token	*split_target_token(t_token *token, t_token *tmp, int *squote, \
						int *dquote);

t_token	*split_by_sep(t_token *token)
{
	t_token	*tmp;
	int		squote;
	int		dquote;

	tmp = token;
	squote = 0;
	dquote = 0;
	while (tmp)
	{
		tmp = split_target_token(token, tmp, &squote, &dquote);
		if (!tmp)
			return (NULL);
		tmp = tmp->next;
	}
	token = ft_dellist(token, "");
	return (token);
}

t_token	*split_target_token(t_token *token, t_token *tmp, int *squote, \
						int *dquote)
{
	int		i;
	char	*sep;
	int		sep_size;
	int		size;

	i = 0;
	sep = ";|><";
	size = ft_strlen(tmp->value);
	while (tmp->value[i] != '\0')
	{
		check_quote(tmp->value[i], squote, dquote);
		if (ft_strchr(sep, tmp->value[i]) != 0 && *squote == 0 && *dquote == 0)
		{
			sep_size = check_duple_sep(tmp->value, i);
			if (sep_size == 0)
			{
				free_all_token(token);
				return (NULL);
			}
			tmp = do_split_by_seps(tmp, sep_size, &i, size);
		}
		i++;
	}
	return (tmp);
}

t_token	*do_split_by_seps(t_token *pos, int sep_size, int *index, int size)
{
	if (pos->next != NULL)
	{
		pos = join_list_center(pos, sep_size, index, size);
	}
	else
	{
		pos = join_list_back(pos, sep_size, index, size);
	}
	return (pos);
}
