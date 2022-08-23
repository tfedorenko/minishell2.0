/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:14:04 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/17 17:21:49 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_for_number_of_double_quotes(char *cmd)
{
	bool	flag;

	flag = true;
	if (number_of_quotes_counter(cmd, "\"") % 2 != 0)
		flag = false;
	return (flag);
}
