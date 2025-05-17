NAME	=	phonebook

SRCS	=	PhoneBook.cpp Contact.cpp program.cpp

CC		=	c++ -std=c++98

FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "is being compiled..."
	@$(CC) $(FLAGS) $(SRCS) -o $(NAME)

fclean:	clean
		@$(RM) $(NAME)

clean:
	@echo "Cleaning..."
	@rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
