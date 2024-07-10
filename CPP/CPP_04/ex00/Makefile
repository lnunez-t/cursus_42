# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laura <laura@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 15:58:45 by laura             #+#    #+#              #
#    Updated: 2024/07/10 12:54:00 by laura            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Polymorph

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

OBJDIR = .objFiles

FILES = main Animal Cat Dog WrongAnimal WrongCat

SRC = $(FILES:=.cpp)
OBJ = $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR) $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all