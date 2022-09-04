# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 16:27:01 by rkultaev          #+#    #+#              #
#    Updated: 2022/09/04 12:51:44 by rkultaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=			minishell

CC				=			gcc
CFLAGS			=			-Werror -Wextra -Wall
RM				=			rm -f
# UTILS			=			sources/utils
# BUILTIN			=			sources/builtins
# EXECUTION		=			sources/execution
# SIGNALS			=			sources/signals
# FD				=			sources/fd
# TOKEN			=			sources/token
# PARSING			=			sources/parsing

SRCS_DIR			=			./sources
OBJS_DIR			=			./objs
INCLUDES			=			./includes
LIBFT				=			./libft_minishell
# LIBFT_HEADERS		=			./libft_minishell/
# LIBFT_FLAGS			=			lft -L$(LIBFT_DIR) $(LIBFT_HEADERS)

SRC_BUILTINS_DIR	=			builtins/
SRC_BUILTINS		=			cd.c echo.c env.c exit.c export.c export_utils.c getenv.c \
								pwd.c unset.c

SRC_EXECUTION_DIR	=			execution/
SRC_EXECUTION		=			checker.c eof_exit.c error.c exec_unit.c  execution_utils. \
								execve.c initenv.c open_close_fds.c

SRC_FD_DIR			=			fd/
SRC_FD				=			fd.c heredoc_fd.c heredoc_handle_tmp_files.c init_fd.c 

SRC_PARSING_DIR		=			parsing/
SRC_PARSING			=			parse_check.c parse_error.c search_env.c

SRC_SIGNALS_DIR		=			signals/
SRC_SIGNALS			=			signals.c

SRC_TOKEN_DIR		=			token/
SRC_TOKEN			=			exec_unit.c expand.c reorder_token.c

SRC_UTILS_DIR		=			utils/
SRC_UTILS			=			define_env_category.c free.c 

SRC					=			$(SRCS_DIR)main.c \
								$(addprefix $(SRC_BUILTINS_DIR), $(SRC_BUILTINS)) \
								$(addprefix $(SRC_EXECUTION_DIR), $(SRC_EXECUTION)) \
								$(addprefix $(SRC_PARSING_DIR), $(SRC_PARSING)) \
								$(addprefix $(SRC_SIGNALS_DIR), $(SRC_SIGNALS)) \
								$(addprefix $(SRC_TOKEN_DIR), $(SRC_TOKEN)) \
								$(addprefix $(SRC_UTILS_DIR), $(SRC_UTILS)) \

# SRCS				=			$(addprefix $(SRCS_DIR), $(SRC))
OBJS				=			$(SRCS:.c=.o)

.PHONY	:	all
all		:	$(NAME)

$(NAME)	:	$(OBJS)
		make -C $(LIBFT)
		$(CC) -I $(INCLUDES) $(OBJS) $(LIBFT)/libft.a  -o $@

$(OBJS_DIR)/%.o	:	$(SRCS_DIR)/%.c
		mkdir -p $(OBJS_DIR)/$(*D)
		$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

.PHONY	:	clean
clean	:
		$(MAKE) clean -C $(LIBFT)
		$(RM) $(OBJS)

.PHONY	:	fclean
fclean	:	clean
		$(MAKE) fclean -C $(LIBFT)
		$(RM) $(NAME)

.PHONY	:	re
re		:	fclean all
		
