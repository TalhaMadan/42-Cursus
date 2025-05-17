NAME	= animal

SRC =	Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		Brain.cpp \
		main.cpp

OBJ		= $(SRC:.cpp=.o)

RM		= rm -rf
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@echo "Is Being Compiled..."
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all	: $(NAME)

clean:
	@echo "Cleaning..."
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re