# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 19:08:52 by rkultaev          #+#    #+#              #
#    Updated: 2022/08/21 19:28:17 by rkultaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FILES

SRCS			=			$(wildcard src/*.c)
OBJS			=			$(SRCS:src/%.c=bin/%.o)

#	COMMANDS AND FLAGS

EXEC			=			get_next_line.a
CC				=			gcc
RM				=			rm -rf
CFLAGS			=			-Wall -Wextra -Werror

#	DIRECTORIES

LIB				=			ft_printf/libftprintf.a
BIN				=			bin/

all : $(LIB) $(BIN) $(EXEC)

$(LIB) : 
		@make -C ../ft_printf

$(EXEC) : $(OBJS)
		@echo $(YELLOW) "Copying and archiving object files... $(EXEC)" $(END)
		@cp ../$(LIB) ./$(EXEC)
		@ar rc $(EXEC) $(OBJS)
		@ranlib $(EXEC)
		@echo $(GREEN) "$(EXEC) created successfully!\n" $(END)

$(BIN) :
		@mkdir bin

$(BIN)%.o: src/%.c
		@echo $(YELLOW) "Compiling..." $< $(END)
		@$(CC) $(CFLAGS) -c $< -o $@

clean :
		@echo $(YELLOW) "Removing object files...$(EXEC)" $(END)
		@$(RM) $(OBJS)
		@$(RM) $(BIN)
		@echo $(RED) "All files were deleted successfully!\n" $(END)

fclean : clean
		@echo $(YELLOW) "Removing $(EXEC)..." $(END)
		@$(RM) $(BIN)
		@$(RM) $(EXEC)
		@echo $(RED) "$(EXEC) was deleted successfully!\n" $(END)

re : fclean all

.PHONY : all clean fclean re


# COLORS

BLACK			=	"\033[0;30m"
RED				=	"\033[0;31m"
GREEN			=	"\033[0;32m"
YELLOW			=	"\033[0;33m"
CYAN			=	"\033[0;35m"
BLUE			=	"\033[0;36m"
WHITE			=	"\033[0;37m"
END				=	"\033[0;0m"