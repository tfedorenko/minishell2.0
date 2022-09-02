/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_proto.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:46:21 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/01 16:47:05 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// checker.c
char **path_to_env(t_node *node);
char	*set_command_path(char *command, char **env);

//execution_utils.c
void	my_dup2(int fd1, int fd2);
void	close_pipes(t_node *node);
void	builtin(int single_command, t_node *node);
int	is_builtin(t_node *node);
int	is_single_command(t_node *node);

//execve.c
void	my_execve(char *file, char **argv, char **envp);
void	execve_action(t_node *node);

// redirects.c
int	redirect(t_exec *process);

//heredoc_handle_tmpfiles.c
t_list	*add_files(t_list *head, char *file_name);
void	remove_files(t_list *head);
t_list	*get_files(t_list *head);
t_list	*temp_files(char *file_name, int command);

//heredoc_fd.c
int	open_temp_file(void);
char	*fetch_heredoc_str(char *heredoc_str, char *read_line);
int	fetch_heredoc_read_end(int temp_fd, char *heredoc_str);
int	fetch_heredoc_fd(t_node *node);

//fd.c
t_node	*set_command_pipe(t_node *prev, t_node *tmp, t_node *command);
void	set_command_output(t_node *tmp, t_node *command);
t_node	*init_command(t_node *prev, t_node *command);
void	define_command_fd(t_node **command, t_node *prev, t_node *tmp);
t_node	*get_fd(t_node *node);


//init_fd.c
int	init_fd(t_exec *process, int pipes[2]);
int	set_fd(t_exec *process, int pipes[2]);
int	set_fd_input(t_node *head, t_node *file);
int	set_fd_output(t_node *head, t_node *file);
int	set_delimiter_fd(t_node *node);
int	set_command_fd(t_node *node);

//error.c
int	error(t_exec *process, int status);
int	prompt_error(char *cmd, char *argv, char *error);
void print_error(char *function, char *msg, int status);
void print_error2(char *message, int status);
void	exit_error(char *message, int status);

//family.c
int	child_process(t_exec *process, int pipes[2]);
int	parent_process(t_exec *process);

//cd
void	cd(t_node *node);

//echo
void	echo(t_node *node);

//export
void	swap_env(t_env *left, t_env *right);
t_env	*sort_env(t_env *env);
t_env	*dupl_env(t_env *env);
t_env	*dupl_envp(t_env *envp);
void	prompt_sorted_env(t_env *envp);
t_env	*set_env(t_env *env, char *key, char *value);
char	*set_value(char *str, int delim);
int	find_delim(char *str, int delim);
void	update_envp(t_node *node);
void	export(t_node *node);

//env
char	*get_env(t_env *env, char *target);
t_env	*update_env(t_env *env, char *key, char *value);
void	give_all_env(t_env *env, int prefix);
void	env(t_env *env);

//
t_env	*set_env(char **env, int i);
t_env	*init_env(char **env);

//exit
void	is_exit(char *num);
void	my_exit(int single_command, t_node *node);

//pwd
void	pwd(void);

//unset
int	invalid_key(char *function, char *key);
int	invalid_key(char *function, char *key);
void	unset(t_node *node);

//parsing
void	print_prompt(char *text);
char	*read_next_command(char *buf);
int number_of_quotes_counter(char *cmd, char *quote);
bool	errors_connected_with_qoutes_handler(char *cmd);
bool	check_for_number_of_single_quotes(char *cmd);
bool	check_for_number_of_double_quotes(char *cmd);

//open_close_fds
void	my_close(int fd);

//utils/free.c
void	ft_free(void *str);
void	free_matrix(char **str);
void	free_env(t_env *env);
void	free_all_nodes(t_node *head);
void	free_all_env(t_env *head);

//exit.c
void	eof_exit(t_env *envp);