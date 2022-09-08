/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_and_enums.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:07:59 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/08 13:00:38 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_AND_ENUMS_H
# define MACROS_AND_ENUMS_H

//ERROR CODES

// # define ERR_NOTPERMTD		1
// # define ERR_NOSUCHPROC		3
// # define ERR_EXECUTION		126
// # define ERR_RUNPROC		-1
// # define ERR_CMDNOTFOUND	127
// # define ERR_STEXIT			128
// # define ERR_STDOUT			255
// # define ERR_NOFILE			2
// # define ERR_PERMDENIED		13
// # define ERR_BROKENPIPE		32
// # define ERR_ISDIR			21
// # define ERR_NODIR			20
// # define TIMEDOUT			110
// # define CNCTNREFUSED		111
// # define ERR_CTRLC			130

// # define E_NOTPERMTD		"Operation not permitted"
// # define E_NOSUCHPROC 		"No such process"
// # define E_EXECUTION		"Permission denied"
// # define E_CMDNOTFOUND		"Command not found"
// # define E_STEXIT			"Invalid argument to exit"
// # define E_STDOUT			"Numeric argument required"
// # define E_NOFILE			"No such file or directory"
// # define E_PERMDENIED		"Permission denied"
// # define E_BROKENPIPE		"Broken pipe"
// # define E_ISDIR			"Is a directory"
// # define E_NODIR			"Not a directory"
// # define E_RUNPROC			"Error occured while running process"

// # define BUILTIN_EXIT	"exit"
// # define BUILTIN_ECHO	"echo"
// # define BUILTIN_UNSET	"unset"
// # define BUILTIN_WHERE	"where"
// # define BUILTIN_EXPORT	"export"
// # define BUILTIN_PWD	"pwd"
// # define BUILTIN_ECHO	"echo"
// # define BUILTIN_CD		"cd"
// # define BUILTIN_ENV	"env"

// # define BLACK			"\033[0;30m"
// # define RED			"\033[0;31m"
// # define GREEN			"\033[0;32m"
// # define YELLOW			"\033[0;33m"
// # define CYAN			"\033[0;35m"
// # define BLUE			"\033[0;36m"
// # define WHITE			"\033[0;37m"
// # define BOLD_RED		"\033[1;31m"
// # define BOLD_GREEN		"\033[1;32m"
// # define BOLD_YELLOW	"\033[0;33m"
// # define BOLD_CYAN		"\033[1;35m"
// # define BOLD_BLUE		"\033[1;34m"
// # define BOLD_WHITE		"\033[1;37m"
// # define RESET			"\033[0;0m"

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