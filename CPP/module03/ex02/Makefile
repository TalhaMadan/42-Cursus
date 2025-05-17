CC = c++ -std=c++98
FLAG = -Wall -Wextra -Werror 
Name = FragTrap
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

all: $(Name)

$(Name): $(SRC)
	@echo "Is Being Compile..."
	@$(CC) $(FLAG) $(SRC) -o $(Name)

clean:
	@echo "Cleaning..."
	@rm -rf $(Name)

fclean: clean

re: fclean all

.PHONY: all clean fclean re