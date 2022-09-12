/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:18:53 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/12 21:31:24 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	invalid_key(char *function, char *key)
{
	int	i;

	if (ft_strlen(key) == 1 && key[0] == '_')
		return (0);
	i = -1;
	while (key[++i])
	{
		if (!ft_isalpha(key[i]) && key[i] != '_')
		{
			if (i > 0 && ft_isdigit(key[i]))
				continue ;
			print_error(ft_strjoin(function, ": "),
				ft_strjoin(key, ": not a valid identifier\n"), 1);
			return (1);
		}
	}
	return (0);
}
