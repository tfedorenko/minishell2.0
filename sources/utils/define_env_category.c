/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_env_category.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:25:48 by hako              #+#    #+#             */
/*   Updated: 2022/09/14 22:03:16 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_general_env_var(char *target, int squote)
{
	if (*target == '$' && (*(target + 1) == '?' || ft_isalpha(*(target + 1))
			|| ft_isdigit(*(target + 1))) && squote == 0)
		return (1);
	return (0);
}

int	is_home_env_var(char *target, int squote)
{
	if (target[0] == '~' && (ft_strlen(target) == 1 || target[1] == '/')
		&& squote == 0)
		return (1);
	return (0);
}
