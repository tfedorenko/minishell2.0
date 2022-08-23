/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:20:33 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/17 17:22:16 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "Libft/libft.h"
#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h> 

void	print_prompt(char *text)
{
	ft_printf(text);
}

// void init(t_double_quotes *double_quotes_info)
// {
// 	double_quotes_info->start_index = 0;
// 	double_quotes_info->end_index = 0;
// 	double_quotes_info->number_of_double_qoutes = 0;
// }

char	*read_next_command(char *buf)
{
	char	*tmp;

	buf = readline("minishell$ ");
	return (buf);
}

// bool	check_for_double_quotes(char *cmd)
// {
// 	int i;
// 	int j;
// 	char *temp;
// 	char *quote;
// 	t_double_quotes quotes_info;

// 	quote = "\"";
// 	i = 0;
// 	while (cmd[i])
// 	{
// 		if (cmd[i] == '\"' && check_for_number_of_double_quotes(cmd) == 1);
// 		{
// 			quotes_info.start_index = i;
// 		}
// 		else if(cmd[i] == '\"' && check_for_number_of_double_quotes(cmd) == 1)
// 		{
// 		}
// 	}
// 	j = 0;
// 	while (cmd[i])
// 	{
// 		if (cmd[i] == '\"' )
// 		{
// 			write(1, &cmd[i+1], 1);
// 		}	
// 	}
// }

// static char	*filter(char *command)
// {
// 	char	*white_sapces;
// 	char	*filtered_command;
// 	int		filtered_command_lenght;

// 	if (is_inside_quote(command))
// 		return (command);
// 	white_sapces = " \t\r\n\v\f";
// 	filtered_command_lenght = ft_strlen(command) - 1;
// 	while (ft_strchr(white_sapces, command[filtered_command_lenght]))
// 		filtered_command_lenght--;
// 	if (command[filtered_command_lenght] == '\\')
// 	{
// 		filtered_command_lenght--;
// 		filtered_command = ft_calloc(filtered_command_lenght + 1, sizeof(char));
// 		if (!filtered_command)
// 			log_in(ERROR, "read|read", "Cannot allocate memory.");
// 		ft_strlcpy(filtered_command, command, filtered_command_lenght);
// 		free(command);
// 		return (filtered_command);
// 	}
// 	return (command);
// }

// static int	is_command_ended(char *command)
// {
// 	char	*white_sapces;
// 	char	*trimed_command;
// 	int		itr;

// 	if (is_inside_quote(command))
// 		return (0);
// 	white_sapces = " \t\r\n\v\f";
// 	itr = ft_strlen(command) - 1;
// 	while (ft_strchr(white_sapces, command[itr]))
// 		itr--;
// 	return (command[itr] != '\\');
// }

static int	is_inside_quote(char *command)
{
	static char	*quote_chars = "\"\'";
	int			itr;
	char		last_quote;

	itr = -1;
	last_quote = '\0';
	while (command[++itr])
	{
		if (ft_strchr(quote_chars, command[itr]))
		{
			if (!last_quote)
				last_quote = command[itr];
			else if (last_quote == command[itr])
				last_quote = '\0';
		}
	}
	return (last_quote);
}

