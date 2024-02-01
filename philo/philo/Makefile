NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
SRC = main.c init.c philo_utils.c routine.c
INCLUDES = messages.h philo.h
OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ} ${INCLUDES}
	${CC} ${CFLAGS} -o $@  ${SRC}

clean:
	rm -f ${OBJ}

fclean: clean;
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re