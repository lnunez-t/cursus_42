# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laura <laura@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 10:14:23 by laura             #+#    #+#              #
#    Updated: 2024/07/24 12:01:48 by laura            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Intern

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

OBJDIR = .objFiles

FILES = main Bureaucrat AForm PresidentialPardonForm RobotomyRequestForm ShrubberyCreationForm Intern

SRC = $(FILES:=.cpp)
OBJ = $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR) $(OBJ) ShrubberyCreationForm_shrubbery

fclean: clean
	@rm -rf $(NAME)

re: fclean all