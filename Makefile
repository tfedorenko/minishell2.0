# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 17:26:48 by rkultaev          #+#    #+#              #
#    Updated: 2022/08/23 20:45:23 by rkultaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# 	FILES

SRCS			=			$(shell find sources -type f -name "*.c")
OBJS			=			$(SRCS:sources/%.c=sources/bin/%.o)
ROOT			=			$(shell echo $(HOME))
LOG				=			output.file

#	COMMANDS AND FLAGS

EXEC			=			minishell
CC				=			gcc
RM				=			rm -rf
CFLAGS			=			-Wall -Werror -Wextra #-I./lib/readline/include
# LDFLAGS			=			-L./lib/readline/lib -lreadline
LIBFT			=			./libft_minishell/libft.a

#	DIRECTORIES

INCLUDE_LIBFT	=			./libft_minishell/src
INCLUDE_GNL		=			./libft_minishell/gnl/src
INCLUDE_PRINTF	=			./libft_minishell/ft_printf/src
INCLUDES		=			./includes
BIN				=			./sources/bin/
# LIB				=			./lib/.minishell

#	RULES

all : $(LIBFT) $(EXEC) #$(LIB)

$(LIBFT) :
		@make -C ./libft_minishell

# $(LIB) :
# 		@make -C ./lib

$(BIN) :
		@mkdir $(BIN)

$(BIN)%.o: sources/%.c
		@mkdir -p $(shell dirname $@)
		@echo $(YELLOW) "Compiling..." $< $(END)
		@$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_PRINTF) -I$(INCLUDE_GNL) -I$(INCLUDE_LIBFT) -I$(INCLUDES)

$(EXEC) : $(BIN) $(OBJS)
		@echo $(YELLOW) "Building... $(EXEC)" $(END)
		@$(CC) $(OBJS) -o $(EXEC) $(LIBFT)
		@echo $(GREEN) "$(EXEC) was successfully created!\n" $(END)

clean :
		@echo $(YELLOW) "Removing object files...$(EXEC)" $(END)
		@$(RM) $(OBJS)
		@echo $(RED) "All files were deleted successfully!\n" $(END)
		
fclean : clean
		@echo $(YELLOW) "Removing $(EXEC)..." $(END)
		@$(RM) $(EXEC)
		@$(RM) $(BIN)
		@echo $(RED) "$(EXEC) was deleted successfully!\n" $(END)

ffclean : fclean
		@make fclean -C ./libft

# fffclean : ffclean
# 		@make fclean -C ./lib

re : ffclean all

run : $(EXEC)
		@./$(EXEC)

.PHONY : all clean fclean re run


# COLORS

BLACK			=	"\033[0;30m"
RED				=	"\033[0;31m"
GREEN			=	"\033[0;32m"
YELLOW			=	"\033[0;33m"
CYAN			=	"\033[0;35m"
BLUE			=	"\033[0;36m"
WHITE			=	"\033[0;37m"
END				=	"\033[0;0m"