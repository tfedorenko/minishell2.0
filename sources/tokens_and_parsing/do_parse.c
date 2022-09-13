/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 03:47:35 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/13 20:33:08 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*do_parse(char *str, t_env *env)
{
	t_token	*token;

	token = NULL;
	token = trim_space(str);
	free(str);
	token = split_by_sep(token);
	token = add_type(token);
	token = expand(token, env);
	token = trim_quote(token);
	while (!proper_order(token))
		token = reorder_token(token);
	return (token);
}
