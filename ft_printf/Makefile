NAME = libftprintf.a

OBJ = $(SRCS:.c=.o)

CFLAGS += -Wall -Wextra -Werror

SRCS =	sources/ft_printf.c \
		sources/flag1.c \
		sources/flag2.c \
		sources/ft_itoa.c \
		sources/ft_atoi.c \
		sources/ft_putstr.c \
		sources/ft_upxtoa.c \
		sources/ft_tolower.c \
		sources/ft_strlen.c \
		sources/ft_isdigit.c \
		sources/ft_strdup.c \

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

all:		$(NAME)

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)

norme:
			norminette -R CheckForbiddenSourceHeader $(SRCS)

re:			fclean all

.PHONY :	all clean fclean re
