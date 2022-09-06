/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_proto.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:46:21 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/06 18:02:02 by rkultaev         ###   ########.fr       */
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

//execution
pid_t	command(t_node *node);
void	define_status(int child);
void	wait_child(int nb_child, int pid);
void	execute(t_node *process);

//execve.c
void	my_execve(char *file, char **argv, char **envp);
void	launch_execve(t_node *node);
int	args_init(t_node *node, t_exec *args);
char	**env_init_arr(t_env *envp);
int	env_counter_arr(t_env *envp);

// redirects.c
int	redirect(t_exec *process);

//fd.c
t_node	*set_command_pipe(t_node *prev, t_node *tmp, t_node *command);
void	set_command_output(t_node *tmp, t_node *command);
t_node	*init_command(t_node *prev, t_node *command);
void	define_command_fd(t_node **command, t_node *prev, t_node *tmp);
t_node	*launch_fd(t_node *node);

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
t_env	*set_builtin_env(t_env *env, char *key, char *value);
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
t_env	*set_init_env(char **env, int i);
t_env	*env_init(char **env);

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
void	free_all_token(t_token *head);

//exit.c
void	eof_exit(t_env *envp);


//signal
//signal.c
void	sigquit(int signal);
void	child_sig_int(int signal);
void sig_int(int signal);
void	heredoc_sig_int(int signal);

//parse_utils
//parse_check.c
void	check_quote(char target, int *sq, int *dq);
int	check_duple_sep(char *token, int pos);
//parse_error.c
t_token *open_quote_err(t_token *head);
int print_syntax_error(t_token **token, const char *msg);
int error_handler(t_token **token, t_token **tmp);
//search_env.c
char	*search_env(t_env *env, char *target);

//token
//exec_unit.c
t_node	*init_node(int type, int size, t_env *envp);
t_node	*add_node_arr(t_node *head, t_token *target, int iter, t_env *envp);
t_node	*add_node_by_type(t_node *head,
		t_token **token, t_token **tmp, t_env *envp);
t_node	*get_exec_unit(t_node *head, t_token **token, 
		t_token **tmp, t_env *envp);
t_node	*exec_handle_node(t_token **token, t_env *envp);
//expand.c
char	*ft_strjoin_free_s1(char *s1, char *s2);
// static void	set_expanded_value(t_token *token,
// 		char *replaced, int start, int *index);
void	expand_home_var(t_token *tmp, t_env *env, int *index);
void	expand_env_var(t_token *tmp, t_env *env, int *index);
t_token	*expand(t_token *token, t_env *env);
//reorder_token.c
// static void	connect_cmd(t_token **head, t_token *cmd,
// 		t_token *arg_start, t_token *redir);
// static t_token	*do_reorder_token(t_token **head, t_token *file,
// 		t_token *redir, t_token *cmd);
t_token	*reorder_token(t_token *token);
//split_by_sep.c
// static t_token	*join_list_center(t_token *pos, int sep_size, int *index, int size);
// static t_token	*join_list_back(t_token *pos, int sep_size, int *index, int size);
// static t_token	*do_split_by_seps(t_token *pos, int sep_size, int *index, int size);
// static t_token	*split_target_token(t_token *token, t_token *tmp, int *squote, int *dquote);
t_token	*split_by_sep(t_token *token);
//token.c
t_token	*add_token(t_token *head, char *value);
void	add_redir_type(t_token *token);
t_token	*add_type(t_token *token);
t_node	*add_command_arr(t_node *new, t_token *target, int iter);
//trim.c
t_token	*do_trim_space(t_token *head,
		char *line, int *start, int i);
t_token	*trim_space(char *line);
char	*inside_quote(char *value, int start, int *mid);
void	do_trim_quote(t_token *tmp);
t_token	*trim_quote(t_token *token);

//utils.c
//define_env_category.c
int	is_general_env_var(char *target, int squote);
int	is_home_env_var(char *target, int squote);
//free_token.c
void	free_token_value(t_token *token);
t_token	*do_ft_dellist(t_token **head, t_token *tmp);
t_token	*ft_dellist(t_token *head, char *target);

//main.c
int	proper_order(t_token *token);
t_token	*do_parse(char *str, t_env *env);
void	minishell(t_env *envp);