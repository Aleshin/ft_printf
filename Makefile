CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIB = ar rc

NAME = libftprintf.a
EXE = a.out
HEADER = ft_printf.h

SRCS =	ft_printf.c ft_itoa.c ft_uitoa.c ft_uitohex.c ft_strlen.c

OBJS = $(SRCS:.c=.o)

%.o:%.c 	$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

all: 		$(NAME)

$(NAME): 	$(OBJS)
			$(LIB) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME) $(EXE)

re:			fclean all

.PHONY: all clean fclean re
