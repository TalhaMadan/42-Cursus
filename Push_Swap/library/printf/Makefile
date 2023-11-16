# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 20:36:30 by tamadan           #+#    #+#              #
#    Updated: 2023/10/24 20:36:32 by tamadan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:%.c=%.o)
FLAGS = -Wall -Wextra -Werror
$(NAME)	: $(OBJS)
		$(CC) $(FLAGS) -c $(SRCS) -I./
		ar rc $(NAME) $(OBJS)
all	:$(NAME)
clean:
	rm -f $(OBJS)
fclean:	clean
	rm -f $(NAME)
re:	fclean all
