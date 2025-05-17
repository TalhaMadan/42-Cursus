/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:23:36 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/11 06:02:11 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../LIBFT/libft.h"
# include "chars.h"
# include "structs.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

int		g_signal;

void	rdln(t_prime *g_prime);
void	sgnl_init(void);
void	free_prime(t_prime *g_prime);

void	env_init(t_prime *g_prime, char **env);
t_env_l	*env_listnew(char *name, char *content);
void	env_lstadd_back(t_env_l **lst, t_env_l *new);
void	interrupt_document(int signal);

void	lexer(t_prime *g_prime);
int		quotes_check(char *line);
int		chrchr_quotes(char c);
int		strchr_quotes(char *str);
t_list	*wspace_split(char *line, int start, int end, int quotes);
int		chrchr_wspace(char c);
int		strchr_wspace(char *str);
t_list	*metachar_split(t_list *lex_slist);
int		chrchr_metachar(char c);
int		strchr_metachar(char *content);
void	create_nodes(t_prime *g_prime, t_list *lex_mlist);
void	lexer_add_node(t_lexer **lexer, char *str, int type);
int		syntax_check(t_prime *g_prime);
void	type_init(t_prime *g_prime);
void	free_lexer(t_lexer **lexer);
void	print_lexer(t_prime *g_prime);

void	expander(t_prime *g_prime);
char	*quotes_trim(char *content, int *end, char quotes);
char	*d_quotes_expand(t_prime *g_prime, char *content, int *end, int *env);
char	*straight_expand(t_prime *g_prime, char *content, int *end, int *env);
char	*dollar_control(char *content, int *end, t_prime *g_prime, int *env);
int		spcl_chars(char c);
int		ret_null(char c);
int		put_directly(char c, int *i);
int		put_syntxerror(char c);
int		spcl_chars(char c);
void	expander_add_node(t_expander **expan, char *str, t_lexer *lex, int env);
int		null_check_substr(char *substr, char *joinedstr);
void	free_expander(t_expander **expander);
void	print_expander(t_prime *g_prime);

void	parser(t_prime *g_prime);
int		pipe_count(t_prime *g_prime);
void	parser_addnode(t_parser **parser, int pipe_count);
void	heredoc_init(t_prime *g_prime);
void	renew_parser(t_prime *g_prime);
int		infile_init(t_expander *expander, t_parser *parser, t_prime *g_prime);
int		outfile_init(t_expander *expander, t_prime *g_prime, t_parser *parser);
void	files_add_node(t_files **files, char *name, int type, int fd);
void	free_parser(t_parser **parser);
void	print_parser(t_prime *g_prime);

void	executer(t_prime *g_prime, int i);
void	open_pipes(t_prime *g_prime);
void	fd_closer(t_prime *g_prime);
void	wait_all(t_prime *g_prime, int builtin);
int		check_builtin(t_prime *g_prime, t_parser *parser);
void	start_builtin(t_prime *g_prime, t_parser *parser, int cmd_type, int i);
void	dup_stdio(t_prime *g_prime, t_parser *parser, int i);
void	start_execve(t_prime *g_prime, t_parser *parser, int i, int builtin);
char	*put_command(t_prime *g_prime, t_parser *parser);
char	**put_env_copy(t_prime *g_prime);
void	start_echo(t_prime *g_prime, t_parser *parser);
void	start_env(t_prime *g_prime, t_parser *parser);
void	start_exit(t_prime *g_prime, t_parser *parser);
void	start_pwd(t_prime *g_prime, t_parser *parser);
void	start_export(t_prime *g_prime, t_parser *parser);
void	start_unset(t_prime *g_prime);
void	start_cd(t_prime *g_prime);
void	cd_one_arg(t_prime *g_prime);
void	cd_two_arg(t_prime *g_prime);
int		change_dir(t_prime *g_prime, char *parameters);
int		update_pwd_from_export(t_prime *g_prime, char *pwd_name,
			char *pwd_content);
void	remove_env(t_prime *g_prime, char *name);
int		put_env_name_count(char *env_arg);
char	*put_env_name(char *content);
void	single_export_arg(t_prime *g_prime, t_parser *parser);
void	double_export_arg(t_prime *g_prime, char *env_cmd);
int		change_env(t_prime *g_prime, char *envname, char *arg, int is_equal);
int		env_arg_control(t_prime *g_prime, char *env);
int		update_env(t_prime *g_prime, char *env_name, char *new_arg);
int		env_name_control(char *env);
void	add_newenv(t_prime *g_prime, char *env);
char	*put_oldpwd(t_env_l *env, char *path);
int		search_path(t_env_l *env_l, char *str);

int		synerr_print(t_prime *g_prime, char *str, int f);
void	file_error(char *str, char *filename, int *fd, t_prime *g_prime);
int		command_error(char *arg, char *cmd, char *str, t_prime *g_prime);
int		ourstrcmp(char *s1, char *s2);
void	double_str_free(char **str);
char	**dynamic_malloc(char **path, char *new_str);
int		parameters_count(char **str);
void	*free_null(void *str);
int		stat_check(t_prime *g_prime, char *cmd);
char	*put_line(int fd);

#endif