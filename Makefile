# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 20:41:52 by dchaves-          #+#    #+#              #
#    Updated: 2022/02/09 22:47:31 by dchaves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PATH VARIABLES
INC_PATH	:=	./inc/
LIB_PATH	:=	./lib/
OBJ_PATH	:=	./obj/
SRC_PATH	:=	./src/
LIBFT_PATH	:=	$(LIB_PATH)libft/bin/

# COMPILATION
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror
DEBUG		:=	-g

# BASH COMMANDS
RM 			:=	rm -f
VALGRIND	:=	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck

# FILES
NAME		:=	fdf
HEADER		:=	$(INC_PATH)fdf.h

SRC_FILES 	:=	main.c
SOURCES		:=	$(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ_FILES	:=	$(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS 	:=	$(addprefix $(OBJ_PATH), $(OBJ_FILES))

all:			libft $(NAME)

# -> creates executable
$(NAME):		$(OBJECTS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -lmlx -lXext -lX11 -L $(LIBFT_PATH) -lft

# -> creates object files inside ./obj/
$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@

libft:
				make -C $(LIB_PATH)libft

clean:
				$(RM) $(OBJECTS)

fclean:			clean
				$(RM) $(NAME)
				make fclean -C $(LIB_PATH)libft				

re:				fclean all

val:	
				$(VALGRIND) ./$(NAME)

.PHONY: 		all clean fclean re libft val