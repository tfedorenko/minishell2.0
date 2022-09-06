# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 14:27:16 by rkultaev          #+#    #+#              #
#    Updated: 2022/09/05 12:11:09 by rkultaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	FILES

# SRCS			=			$(wildcard src/*.c)
# SRC_DIR			=			src/
SRC				=			src/ft_bzero.c src/ft_isalnum.c	src/ft_isalpha.c src/ft_isascii.c src/ft_isdigit.c src/ft_isprint.c src/ft_memcpy.c	\
							src/ft_memmove.c	src/ft_memset.c \
							src/ft_strchr.c src/ft_strlcat.c src/ft_strlcpy.c src/ft_strlen.c src/ft_strrchr.c src/ft_tolower.c src/ft_toupper.c \
							src/ft_strncmp.c src/ft_memchr.c src/ft_memcmp.c src/ft_strnstr.c src/ft_atoi.c src/ft_calloc.c \
							src/ft_strdup.c src/ft_substr.c src/ft_strjoin.c src/ft_strtrim.c src/ft_split.c src/ft_putchar_fd.c \
							src/ft_putstr_fd.c src/ft_itoa.c src/ft_strmapi.c src/ft_striteri.c src/ft_putendl_fd.c \
							src/ft_putnbr_fd.c src/ft_strcmp.c

SRCS			=			$(addprefix $(SRC_DIR), $(SRC))

OBJS			=			$(SRC:src/%.c=bin/%.o)

#	COMMANDS AND FLAGS

EXEC			=			libft.a
CC				=			gcc
RM				=			rm -rf
CFLAGS			=			-Wall -Werror -Wextra
# LIB				=			gnl/get_next_line.a

#	DIRECTORIES

BIN				=			bin/
INCLUDES		=			./libft.h

#	RULES

all : $(BIN) $(EXEC)

$(EXEC) : $(OBJS)
		@echo $(YELLOW) "Copying and archiving object files...$(EXEC)" $(END)
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




