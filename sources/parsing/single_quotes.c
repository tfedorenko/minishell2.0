/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:13:58 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/17 17:19:13 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_for_number_of_single_quotes(char *cmd)
{
	bool	flag;

	flag = true;
	if (number_of_quotes_counter(cmd, "\'") % 2 != 0)
		flag = false;
	return (flag);
}

