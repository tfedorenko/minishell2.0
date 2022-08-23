# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 14:27:16 by rkultaev          #+#    #+#              #
#    Updated: 2022/08/21 21:02:47 by rkultaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	FILES

SRCS			=			$(wildcard src/*.c)
OBJS			=			$(SRCS:src/%.c=bin/%.o)

#	COMMANDS AND FLAGS

EXEC			=			libft.a
CC				=			gcc
RM				=			rm -rf
GCC				=			-Wall -Werror -Wextra
LIB				=			gnl/get_next_line.a

#	DIRECTORIES

BIN				=			bin/
INCLUDES		=			./libft.h


#	RULES

all : $(LIB) $(BIN) $(EXEC)

$(LIB) :
		@make -C ./gnl

$(EXEC) : $(OBJS)
		@echo $(YELLOW) "Copying and archiving object files...$(EXEC)" $(END)
		@cp $(LIB) ./$(EXEC)
		@ar rc $(EXEC) $(OBJS)
		@ranlib $(EXEC)
		@echo $(GREEN) "$(EXEC) was created successfully!\n" $(END)

$(BIN) :
		@mkdir $(BIN)

$(BIN)%.o: src/%.c
		@echo $(YELLOW) "Compiling..." $< $(END)
		@$(CC) $(CFLAGS) -c $< -o $@

clean : 
		@echo $(YELLOW) "Removing object files...$(EXEC)" $(END)
		@$(RM) $(OBJS)
		@echo $(RED) "All files were deleted successfully!\n" $(END)

fclean : clean
		@make fclean -C ./gnl
		@make fclean -C ./ft_printf
		@echo $(YELLOW) "Removing $(EXEC)..." $(END)
		@$(RM) $(EXEC)
		@$(RM) $(BIN)
		@echo $(RED) "$(EXEC) was deleted successfully!\n" $(END)
		
re : fclean all

.PHONY : all clean fclean re
		



# clean :
# 	@echo $(YELLOW) "Removing object files...$(NAME)" $(END)
# 	@$(RM) $(OBJS)
# 	@echo $(RED) "All files deleted successfully!\n" $(END)

# fclean : clean
# 	@make fclean -C ./GNL
# 	@make fclean -C ./ft_printf
# 	@echo $(YELLOW) "Removing $(NAME)..." $(END)
# 	@$(RM) $(NAME)
# 	@$(RM) $(BIN)
# 	@echo $(RED) "$(NAME) deleted successfully!\n" $(END)

# norm :
# 	@make norm -C ft_printf/
# 	@make norm -C GNL/
# 	@norminette sources/*.[ch]

# re : fclean all






# COLORS

BLACK			=	"\033[0;30m"
RED				=	"\033[0;31m"
GREEN			=	"\033[0;32m"
YELLOW			=	"\033[0;33m"
CYAN			=	"\033[0;35m"
BLUE			=	"\033[0;36m"
WHITE			=	"\033[0;37m"
END				=	"\033[0;0m"



# NAME = libft.a

# SRCS = ft_bzero.c ft_isalnum.c	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c	\
# ft_memmove.c	ft_memset.c \
# ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strrchr.c ft_tolower.c ft_toupper.c \
# ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
# ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_putchar_fd.c \
# ft_putstr_fd.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putendl_fd.c \
# ft_putnbr_fd.c get_next_line.c get_next_line_utils.c

# BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
# ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# HEADER = libft.h

# OBJ	= $(SRCS:%.c=%.o)

# bonus_objects = $(BONUS:%.c=%.o)

# CC = gcc


# CFLAGS = -Wall -Wextra -Werror -I $(HEADER)



# $(NAME) : $(OBJ) $(HEADER)
# 	ar rcs $(NAME) $(OBJ)

# bonus : $(OBJ) $(bonus_objects) $(HEADER)
# 	ar rcs $(NAME) $(OBJ) $(bonus_objects)

# all : $(NAME) 

# clean :
# 	rm -f $(OBJ) $(bonus_objects)

# fclean : clean
# 	rm -f $(NAME)

# re:	fclean all

# .PHONY	:	all clean fclean re bonus




