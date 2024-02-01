LIB = ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putnbr_dec.c \
		ft_putptr.c ft_putstr.c ft_putnbr_un.c

SRC = ${LIB}

OBJS = ${SRC:.c=.o}

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

.c.o :
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
				ar -rsc ${NAME} ${OBJS}

all:	${NAME}

clean:
				rm -f ${OBJS}

fclean: clean;
				rm -f ${NAME}

re:		fclean all

.PHONY: all clean fclean re