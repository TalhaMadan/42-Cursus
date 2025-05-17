CC = c++ -std=c++98
FLAG = -Wall -Wextra -Werror 
Name = Animal
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

all: $(Name)

$(Name): $(SRC)
	@echo "Is Being Compiled..."
	@$(CC) $(FLAG) $(SRC) -o $(Name)

clean:
	@echo "Cleaning..."
	@rm -rf $(Name)

fclean: clean

re: fclean all

.PHONY: all clean fclean re