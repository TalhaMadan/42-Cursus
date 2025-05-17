/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:37:58 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 18:42:06 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

void	lexer(t_prime *g_prime)
{
	t_list	*lex_slist;
	t_list	*lex_mlist;

	if (quotes_check(g_prime->line) == -1)
	{
		write(2, "MiniShell: incorrect use of quotes!\n", 36);
		g_prime->exit_code = 258;
		return ;
	}
	lex_slist = wspace_split(g_prime->line, 0, 0, 0);
	lex_mlist = metachar_split(lex_slist);
	create_nodes(g_prime, lex_mlist);
	if (syntax_check(g_prime) == -1)
		free_lexer(&g_prime->lexer);
}
