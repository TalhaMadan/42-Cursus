
SRCSB = bonus/main_bonus.c bonus/complex_bonus.c bonus/fract_calculating_bonus.c bonus/mlx_bonus.c bonus/coor_operations_bonus.c \
	 bonus/mouse_hooks_bonus.c bonus/libft_utils_bonus.c bonus/libft_utils2_bonus.c bonus/key_hooks_bonus.c bonus/check_args_bonus.c bonus/fractol_bonus.c \
	 bonus/complex2_bonus.c

SRCS = main.c complex.c fract_calculating.c mlx.c coor_operations.c \
	 mouse_hooks.c libft_utils.c libft_utils2.c key_hooks.c check_args.c fractol.c \
	 complex2.c


RM				= rm -f
GCC			= gcc -Wall -Wextra -Werror
NAME			= fract_ol
NAMEB			= fract_ol_bonus
all:			$(SRCS) $(SRCSB) $(NAME)


$(NAME): $(SRCS)
	$(GCC) -I../mlx -framework OpenGL -framework AppKit $(SRCS) -L../mlx -lmlx -o $(NAME)

clean:
	$(RM) $(NAME) $(NAMEB)

bonus: $(SRCSB)
	$(GCC) -I../mlx -framework OpenGL -framework AppKit $(SRCSB) -L../mlx -lmlx -o $(NAMEB)

fclean:			clean;

re:				fclean $(NAME) $(NAMEB) 

.PHONY:			all bonus clean fclean re