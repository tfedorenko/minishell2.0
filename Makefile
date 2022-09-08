# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 16:27:01 by rkultaev          #+#    #+#              #
#    Updated: 2022/09/08 14:37:35 by rkultaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=			minishell

CC				=			gcc
CFLAGS			=			-Werror -Wextra -Wall
RM				=			rm -f
INCLUDES		=			-I ./includes -I $(HOME)/goinfre/.brew/opt/readline/include/

# UTILS				=			sources/utils
# BUILTIN			=			sources/builtins
# EXECUTION			=			sources/execution
# SIGNALS			=			sources/signals
# FD				=			sources/fd
# TOKEN				=			sources/token
# PARSING			=			sources/parsing

SRCS_DIR			=			./sources/
OBJS_DIR			=			./objects/
LIBFT				=			./libft_minishell
# LIBFT_HEADERS		=			./libft_minishell/
# LIBFT_FLAGS		=			lft -L$(LIBFT_DIR) $(LIBFT_HEADERS)

SRC_BUILTINS_DIR	=			$(SRCS_DIR)builtins/
SRC_BUILTINS		=			cd.c echo.c env.c exit.c export.c export_utils.c getenv.c \
								pwd.c unset.c is_builtin.c

SRC_EXECUTION_DIR	=			$(SRCS_DIR)execution/
SRC_EXECUTION		=			checker.c eof_exit.c error.c  execution_utils.c \
								execve.c execution.c

SRC_FD_DIR			=			$(SRCS_DIR)fd/
SRC_FD				=			heredoc_fd.c heredoc_handle_tmp_files.c \
								fd_delimiter_and_pipe.c launch_fd.c prepare_cmd_fd.c \
								set_in_out_fds.c

SRC_INIT_DIR		=			$(SRCS_DIR)init/
SRC_INIT			=			args_init.c env_init_arr.c env_init.c node_init.c \
								fd_command_init.c

SRC_PARSING_DIR		=			$(SRCS_DIR)parsing/
SRC_PARSING			=			parse_check.c parse_error.c search_env.c

SRC_SIGNALS_DIR		=			$(SRCS_DIR)signals/
SRC_SIGNALS			=			signals.c

SRC_TOKEN_DIR		=			$(SRCS_DIR)token/
SRC_TOKEN			=			node_init_exec.c expand.c reorder_token.c split_by_sep.c \
								token_utils.c token.c trim.c

SRC_UTILS_DIR		=			$(SRCS_DIR)utils/
SRC_UTILS			=			define_env_category.c free.c free_token.c free_node.c open_close_fds.c



SRCS					=			$(SRCS_DIR)main.c \
								$(addprefix $(SRC_BUILTINS_DIR), $(SRC_BUILTINS)) \
								$(addprefix $(SRC_EXECUTION_DIR), $(SRC_EXECUTION)) \
								$(addprefix $(SRC_FD_DIR), $(SRC_FD)) \
								$(addprefix $(SRC_INIT_DIR), $(SRC_INIT)) \
								$(addprefix $(SRC_PARSING_DIR), $(SRC_PARSING)) \
								$(addprefix $(SRC_SIGNALS_DIR), $(SRC_SIGNALS)) \
								$(addprefix $(SRC_TOKEN_DIR), $(SRC_TOKEN)) \
								$(addprefix $(SRC_UTILS_DIR), $(SRC_UTILS)) \

# SRCS				=			$(addprefix $(SRCS_DIR), $(SRC))

OBJS				=			$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

LDFLAGS				=			-L $(HOME)/goinfre/.brew/opt/readline/lib/ -lreadline

.PHONY	:	all
all		:	$(NAME)

$(NAME)	:	$(OBJS)
#@echo $(YELLOW)Compiling [$(NAME)]...$(END)
		@make -C $(LIBFT)
		@$(CC) $(OBJS) $(LDFLAGS) $(INCLUDES) $(LIBFT)/libft.a -o $@
		@echo $(GREEN)COMPILATION: DONE! [$(NAME)]$(END)
# $(CC) $(INCLUDES) $(LIBFT)/libft.a $(addprefix $(OBJS_DIR)/,$(notdir $(OBJS))) $(LDFLAGS) -o $@

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.c
#@echo $(YELLOW)Compiling [$@]...$(END)
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 
#@echo $(GREEN)Finished! [$@]$(X)

.PHONY	:	clean
clean	:
		@make clean -C $(LIBFT)
		@if [ -d "$(OBJS_DIR)" ]; then \
			$(RM) -r $(OBJS_DIR); \
			echo $(RED)Cleaning" "[$(OBJS_DIR)]...$(END); \
		fi;

.PHONY	:	fclean
fclean	:	clean
		@make fclean -C $(LIBFT)
		@if [ -f "$(NAME)" ]; then \
			$(RM) $(NAME); \
			echo $(RED)Cleaning" "[$(NAME)]...$(END); \
		fi;
# @$(RM) -rf $(OBJS_DIR)
# @$(RM) $(NAME)

.PHONY	:	re
re		:	fclean all

# COLORS
YELLOW = "\033[33m"
RED = "\033[31m"
GREEN = "\033[32m"
BLUE = "\033[34m"
END = "\033[0m"
UP = "\033[A"
CUT = "\033[K"
