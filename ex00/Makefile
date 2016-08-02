SRCS =	srcs/eval_expr.c srcs/ft_atoi.c srcs/ft_putchar.c srcs/ft_putstr.c\
	srcs/ft_strdup.c srcs/ft_strncpy.c srcs/ft_strnew_int.c\
	srcs/ft_itoa.c srcs/ft_putnbr.c srcs/ft_strcpy.c\
	srcs/ft_strlen.c srcs/ft_strnew.c

OBJS = *.o

NAME = eval_expr

FLAGS = -Werror -Wextra -Wall

$(NAME) :
	gcc -o $(NAME) $(FLAGS) $(SRCS) -I srcs/eval_expr.h

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm $(NAME)

re : fclean all