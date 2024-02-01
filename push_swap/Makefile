SRC = index.c sort.c sort3or5.c utils.c push_rules.c rev_rules.c \
		rot_rules.c swap_rules.c main.c utils2.c ft_lstsize.c ft_split.c utils3.c \

SRC_BONUS = checker_bonus.c get_next_line/get_next_line.c utils_bonus.c \
			get_next_line/get_next_line_utils.c ft_split.c utils_bonus2.c \
			push_rules.c rev_rules.c rot_rules.c swap_rules.c ft_lstsize.c utils_bonus3.c

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

RM = rm -rf

${NAME}:
				${CC} ${CFLAGS} ${SRC} -o ${NAME}

all:	${NAME}

bonus:
				${CC} ${CFLAGS} ${SRC_BONUS} -o checker

clean:
				${RM} ${NAME}

fclean: clean;
				${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re