/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:05:27 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/30 22:38:05 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	flag_n(char *flag)
{
	int	i;

	if (ft_strlen(flag) < 2)
		return (0);
	i = 1;
	while (flag && flag[i])
	{
		if (flag[i] != 'n')
			return (0);
		else
			++i;
	}
	return (1);
}

void	echo(t_node *node)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (node->command[++i])
	{
		if (node->command[i][0] == '-' && flag_n(node->command[i]))
			++flag;
		else
			break ;
	}
	while (node->command[i])
	{
		printf("%s", node->command[i++]);
		if (node->command[i] != NULL)
			printf(" ");
	}
	if (!flag)
		printf("\n");
}
