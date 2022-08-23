/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:02:04 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/23 15:27:28 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_STRUCT_H
# define EXECUTION_STRUCT_H

# include <../libft_minishell/src/libft.h>

typedef struct s_redirect
{
	char	*read;
	char	*write;
	char	*overwrite;
	t_list	*delimiter;
}	t_redirect;

typedef struct s_stdfd
{
	int	std_in;
	int	std_out;
	int	std_err;
}	t_stdfd;

typedef struct s_exec
{
	pid_t			pid;
	char			*name;
	char			*path;
	char			**commands;
	// t_envp	*envp;
	t_stdfd			*stdfd;
	t_redirect		*redirect;
	struct s_exec	*next;
	struct s_exec	*prev;
	char			*envp;	//need to be changed by parser
}	t_exec;

typedef struct s_env
{
	char *key;
	char *value;
	char *fullstr;
	struct s_env *next;
}	t_env;

#endif