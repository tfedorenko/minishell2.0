/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:24:06 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/15 12:30:06 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

void	check_quote(char target, int *sq, int *dq);
int		chech_duple_sep(char *token, int pos);

void	check_quote(char target, int *sq, int *dq)
{
	if (target == '\'' && *sq == 0 && *dq == 0)
		*sq = 1;
	else if (target == '\"' && *sq == 0 && *dq == 0)
		*dq = 1;
	else if (target == '\'' && *sq == 1)
		*sq = 0;
	else if (target == '\"' && *dq == 1)
		*dq = 0;
}

int	check_duple_sep(char *token, int pos)
{
	int		size;
	char	*redir;

	size = 1;
	redir = "><";
	if (token[pos] == token[pos + 1])
	{
		if (ft_strchr(redir, token[pos]) != 0)
			size = 2;
		else
		{
			printf("minishell: syntax error unexpected token '%c%c'\n", \
							token[pos], token[pos]);
			g_status = ERR_SYNTAX;
			size = 0;
		}
	}
	return (size);
}
