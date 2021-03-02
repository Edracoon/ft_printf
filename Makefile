NAME = libftprintf.a

OBJ = $(SRCS:.c=.o)

CFLAGS += -Wall -Wextra -Werror

SRCS =	ft_printf.c \
		sources/fill_struct.c \
		sources/finders_utils.c \
		sources/type_id.c \
		sources/type_c.c \
		sources/type_s.c \
		sources/type_x.c \
		sources/type_upper_x.c \
		sources/type_p.c \
		sources/type_u.c \
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
