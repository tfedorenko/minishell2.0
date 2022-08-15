/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:20:33 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/15 18:52:14 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "Libft/libft.h"
#include <stdlib.h> 
#include <stdio.h>

void	print_prompt(char *text)
{
	ft_printf(text);
}


char	*read_next_command(char *buf)
{
	// int		buflen;
	char	*tmp;

		// print_prompt("minishell$ ");
		// buf = get_next_line(0);
		buf = readline("minishell$ ");
	return (buf);
}

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

// static int	is_inside_quote(char *command)
// {
// 	static char	*quote_chars = "\"\'";
// 	int			itr;
// 	char		last_quote;

// 	itr = -1;
// 	last_quote = '\0';
// 	while (command[++itr])
// 	{
// 		if (ft_strchr(quote_chars, command[itr]))
// 		{
// 			if (!last_quote)
// 				last_quote = command[itr];
// 			else if (last_quote == command[itr])
// 				last_quote = '\0';
// 		}
// 	}
// 	return (last_quote);
// }


