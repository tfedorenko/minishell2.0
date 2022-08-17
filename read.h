/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:23:43 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/17 17:10:13 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H
//# define EXIT_SUCCESS
#include <stdbool.h> 

// typedef struct s_double_quotes
// {
// 	int start_index;
// 	int end_index;
// 	int	number_of_double_qoutes;
// } t_double_quotes;

void	print_prompt(char *text);
char	*read_next_command(char *buf);
int number_of_quotes_counter(char *cmd, char *quote);
bool	errors_connected_with_qoutes_handler(char *cmd);
bool	check_for_number_of_single_quotes(char *cmd);
bool	check_for_number_of_double_quotes(char *cmd);



#endif