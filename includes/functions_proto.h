/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_proto.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:46:21 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/23 19:34:37 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// checker.c

int		find_path_var(char **str);
char	**path_to_env( char **envp);
char	*set_command_path(char *command, char **env);
void	ft_free(char **str);

// redirects.c
int	redirect(t_exec *process);


//init_fd.c
int	init_fd(t_exec *process, int pipes[2]);
int	set_fd(t_exec *process, int pipes[2]);

//error.c
int	error(t_exec *process, int status);

//family.c
int	child_process(t_exec *process, int pipes[2]);
int	parent_process(t_exec *process);




//parsing
void	print_prompt(char *text);
char	*read_next_command(char *buf);
int number_of_quotes_counter(char *cmd, char *quote);
bool	errors_connected_with_qoutes_handler(char *cmd);
bool	check_for_number_of_single_quotes(char *cmd);
bool	check_for_number_of_double_quotes(char *cmd);