/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_and_enums.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:07:59 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/13 22:17:48 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_AND_ENUMS_H
# define MACROS_AND_ENUMS_H

//exit status
# define ERR_SYNTAX			258
# define ERR_CMDNOTFOUND	127
# define ERR_PERM			126
# define ERR_ETC			1

# define GET	0
# define ADD	1
# define DEL	2

# define IN		0
# define OUT	1

# define SINGLE_CMD 1
# define MULTI_CMD	0

# define CMD		1
# define PIPE		2
# define TRUNC		3
# define APPEND		4
# define INPUT		5
# define HEREDOC	6
# define BREAK		7
# define FAIL		8

# define ERR_PRT_BREAK	"syntax error near unexpected token `;'\n"
# define ERR_PRT_PIPE	"syntax error near unexpected token `|'\n"
# define ERR_PRT_INPUT	"syntax error near unexpected token `<'\n"
# define ERR_PRT_HRDC	"syntax error near unexpected token `<<'\n"
# define ERR_PRT_TRC		"syntax error near unexpected token `>'\n"
# define ERR_PRT_APP		"syntax error near unexpected token `>>'\n"
# define ERR_PRT_NL		"syntax error near unexpected token `newline'\n"

typedef enum e_return
{
	ERROR = -1,
	SUCCESS = 0,
}	t_return;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

typedef enum e_rdrctn
{
	WITHOUT = 0,
	READ = 1,
	WRITE = 2,
	DELIMETER = 3,
	OVERWRITE = 4,
}	t_rdrctn;

#endif