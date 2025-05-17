SRC =	./SOURCE/MAIN/main.c \
		./SOURCE/MAIN/env_init.c \
		./SOURCE/MAIN/free_prime.c \
		./SOURCE/MAIN/signal_init.c \
		./SOURCE/LEXER/MAIN_LEXER/main_lexer.c \
		./SOURCE/LEXER/MAIN_LEXER/syntax_check.c \
		./SOURCE/LEXER/MAIN_LEXER/quotes_check.c \
		./SOURCE/LEXER/MAIN_LEXER/wspace_split.c \
		./SOURCE/LEXER/MAIN_LEXER/metachar_split.c \
		./SOURCE/LEXER/LEXER_UTILS/quotes_utils.c \
		./SOURCE/LEXER/LEXER_UTILS/wspace_utils.c \
		./SOURCE/LEXER/LEXER_UTILS/metachar_utils.c \
		./SOURCE/LEXER/LEXER_LIST_INIT/create_nodes.c \
		./SOURCE/LEXER/LEXER_LIST_INIT/lexer_init_utils.c \
		./SOURCE/LEXER/LEXER_LIST_INIT/type_init.c \
		./SOURCE/EXPANDER/MAIN_EXPANDER/main_expander.c \
		./SOURCE/EXPANDER/EXPANDER_LST_INIT/expand_content.c \
		./SOURCE/EXPANDER/EXPANDER_LST_INIT/dollar_control.c \
		./SOURCE/EXPANDER/EXPANDER_LST_INIT/dollar_utils.c \
		./SOURCE/EXPANDER/EXPANDER_LST_INIT/expander_init_utils.c \
		./SOURCE/PARSER/MAIN_PARSER/main_parser.c \
		./SOURCE/PARSER/MAIN_PARSER/heredoc_init.c \
		./SOURCE/PARSER/MAIN_PARSER/renew_parser.c \
		./SOURCE/PARSER/PARSER_LIST_INIT/parser_init_utils.c \
		./SOURCE/PARSER/PARSER_LIST_INIT/t_file_init_utils.c \
		./SOURCE/PARSER/PARSER_LIST_INIT/infile_init.c \
		./SOURCE/PARSER/PARSER_LIST_INIT/outfile_init.c \
		./SOURCE/EXEC/EXECMAIN/main_exec.c \
		./SOURCE/EXEC/EXECMAIN/m_process.c \
		./SOURCE/EXEC/EXECMAIN/dup_stdio.c \
		./SOURCE/EXEC/EXECMAIN/run_cmmnd.c \
		./SOURCE/EXEC/BUILTIN/check_builtin.c \
		./SOURCE/EXEC/BUILTIN/run_cd.c \
		./SOURCE/EXEC/BUILTIN/run_echo.c \
		./SOURCE/EXEC/BUILTIN/run_env.c \
		./SOURCE/EXEC/BUILTIN/run_pwd.c \
		./SOURCE/EXEC/BUILTIN/run_exit.c \
		./SOURCE/EXEC/BUILTIN/run_export.c \
		./SOURCE/EXEC/BUILTIN/run_unset.c \
		./SOURCE/EXEC/UTILS/env_utils.c \
		./SOURCE/EXEC/UTILS/exec_utils.c \
		./SOURCE/EXEC/UTILS/run_execve_utils.c \
		./SOURCE/EXEC/UTILS/env_arg_control.c \
		./SOURCE/UTILS/print_errors.c \
		./SOURCE/UTILS/utils.c \
		./SOURCE/UTILS/put_line.c \

NAME = minishell
cc = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT = libft/libft.a
READLINE = readline

OBJ = $(SRC:.c=.o)

all : $(READLINE) $(LIBFT) $(NAME)

$(READLINE):
	curl -O https://ftp.gnu.org/gnu/readline/readline-8.2.tar.gz
	tar -xvf readline-8.2.tar.gz
	cd readline-8.2 && ./configure --prefix=${PWD}/readline
	cd readline-8.2 && make install

$(LIBFT):
	@make -C libft
	@make bonus -C libft
	@make clean -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${PWD}/readline/include/

$(NAME): $(SRC) $(LIBFT)
	@$(CC) $(CFLAGS) $(LIBFT) $(SRC) -L${PWD}/readline/lib  -I${PWD}/readline/include/ -lreadline -o $(NAME)
	@ make clean

clean:
	@$(RM) $(OBJ)


fclean: clean
	@$(RM) $(NAME)
	@make -C libft fclean
	@rm -rf readline-8.2 readline-8.2.tar.gz

re: fclean all

.PHONY: all clean fclean re