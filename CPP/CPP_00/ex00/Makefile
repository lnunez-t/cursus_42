# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laura <laura@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 16:26:11 by laura             #+#    #+#              #
#    Updated: 2024/04/27 16:29:53 by laura            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all clean re

all: ${NAME}

${NAME}:
	${CC} ${FLAGS} megaphone.cpp -o ${NAME}

clean:
	rm ${NAME}

fclean:
	rm ${NAME}

re: clean all