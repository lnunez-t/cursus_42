NAME = Array

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

OBJDIR = .objFiles

FILES = main

SRC = $(FILES:=.cpp)
OBJ = $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER = Array.hpp

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