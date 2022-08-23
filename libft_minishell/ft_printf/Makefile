# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 18:54:08 by rkultaev          #+#    #+#              #
#    Updated: 2022/08/21 19:25:27 by rkultaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	FILES

SRCS			=			$(wildcard src/*.c)
OBJS			=			$(SRCS:src/%.c=bin/%.o)

#	COMMANDS AND FLAGS

EXEC			=			libftprintf.a
CC				=			gcc
RM				=			rm -rf
CFLAGS			=			-Wall -Werror -Wextra

#	DIRECTORIES

BIN				=			bin/

all	:	$(BIN) $(NAME)

$(EXEC) : $(OBJS)
		@echo $(YELLOW) "Archiving object files... $(EXEC)" $(END)
		@ar rc $(EXEC) $(OBJS)
		@ranlib $(NAME)
		@echo $(GREEN) "$(EXEC) was created successfully!\n" $(END)

$(BIN) :
		@mkdir $(BIN)
		
$(BIN)%.o: src/%.c
		@echo $(YELLOW) "Compiling..." $< $(END)
		@$(CC) $(CFLAGS) -c $< -o $@

clean :
		@echo $(YELLOW) "Removing object files... $(EXEC)" $(END)
		@$(RM) $(OBJS)
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