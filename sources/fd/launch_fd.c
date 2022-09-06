/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:55:42 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/06 16:53:36 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*launch_fd(t_node *node)
{
	if (!set_delimiter_fd(node))
		return (NULL);
	set_command_fd(node);
	return (node);
}
