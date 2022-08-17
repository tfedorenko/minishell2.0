/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:19:19 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/17 17:38:25 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	number_of_quotes_counter(char *cmd, char *quote)
{
	int			i;
	int			quotes_counter;

	i = 0;
	quotes_counter = 0;
	while (cmd[i])
	{
		if (ft_strchr(quote, cmd[i]))
			quotes_counter++;
		i++;
	}
	return (quotes_counter);
}

bool	errors_connected_with_qoutes_handler(char *cmd)
{
	bool	error_flag;
	
	error_flag = false;
	if (check_for_number_of_double_quotes(cmd) == false || \
				check_for_number_of_single_quotes(cmd) == false)
	{
		ft_printf("Error: unclosed quotes");
		write(1, "\n", 1);
		error_flag = true;
	}
	return (error_flag);
}

bool	if_inside_quotes(char *cmd, char *quote)
{
	bool	flag;
	int		i;
	char	*last_quote;

	i = 0;
	flag = false;
	last_quote = '\0';
	while (cmd[i])
	{
		if(ft_strchr(quote, cmd[i]))
		{
			if(last_quote == '\0' && flag == false)
			{
				last_quote = cmd[i];
				flag = true;
			}
			else if (last_quote == cmd[i] && flag == true)
			{
				last_quote = '\0';
				flag = false;
			}
		}
		i++;
	}
	return(flag);	
}