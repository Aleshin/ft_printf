CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIB = ar rc

NAME = libft.a
EXE = a.out
HEADER = libft.h

SRCS =	ft_atoi.c ft_strlen.c ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS_BONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstdel.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o:%.c 	$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

all: 		$(NAME)

$(NAME): 	$(OBJS)
			$(LIB) $(NAME) $(OBJS)

bonus:		$(OBJS) $(OBJS_BONUS)
			$(LIB) $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME) $(EXE)

re:			fclean all

.PHONY: all clean fclean re
