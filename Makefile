CC		:=	gcc
FLAGS	:=	-Wall -Wextra -Werror -g
RM		:=	rm -f

NAME	= fdf
SRCS	= main.c
OBJS	= $(SRCS:%.c=%.o)

VALGR	= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes


all:	$(NAME)

$(NAME):$(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS) -lmlx -lXext -lX11

%.o:	%.c
		$(CC) $(FLAGS) -c -o $@ $<

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

val:	
		$(VALGR) ./$(NAME)

.PHONY: all clean fclean re val
