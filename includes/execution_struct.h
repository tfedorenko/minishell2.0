/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:02:04 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/06 15:39:11 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_STRUCT_H
# define EXECUTION_STRUCT_H

# include "libft.h"
# include "minishell.h"

// typedef struct s_redirect
// {
// 	char	*read;
// 	char	*write;
// 	char	*overwrite;
// 	t_list	*delimiter;
// }	t_redirect;

// typedef struct s_stdfd
// {
// 	int	std_in;
// 	int	std_out;
// 	int	std_err;
// }	t_stdfd;

typedef struct s_exec
{
	char	**argv;
	char	*file;
	char	**env;
}	t_exec;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_node
{
	char			**command;
	int				type;
	int				fd[2];
	t_env			*env;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	char			*value;
	struct s_list	*next;
}	t_list;

typedef struct s_token
{
	char			*value;
	int				type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

#endif