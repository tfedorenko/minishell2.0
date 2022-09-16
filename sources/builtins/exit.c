/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:37:41 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/15 12:27:48 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

void	is_exit(char *num)
{
	int	i;

	i = -1;
	if (num[0] == '-' || num[0] == '+')
		++i;
	while (num && num[++i])
	{
		if (!ft_isdigit(num[i]))
		{
			print_error(ft_strjoin("exit: ", num), \
				ft_strdup(": numeric argument is required\n"), 255);
			exit(255);
		}
	}
}

void	my_exit(int single_command, t_node *node)
{
	long long	status_longlong;

	if (single_command)
		printf("exit\n");
	if (node->command[1] == NULL)
		exit(g_status);
	is_exit(node->command[1]);
	status_longlong = ft_atoi(node->command[1]);
	g_status = status_longlong % 256 + 256 * (status_longlong < 0);
	if (node->command[2] != NULL)
	{
		print_error2(ft_strdup("exit: too many arguments\n"), 1);
		g_status = 1;
	}
	else
		exit(g_status);
}
