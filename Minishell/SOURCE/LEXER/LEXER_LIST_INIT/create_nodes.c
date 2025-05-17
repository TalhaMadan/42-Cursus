/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:35:59 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 11:36:00 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

void	create_nodes(t_prime *g_prime, t_list *lex_mlist)
{
	t_list	*temp;

	temp = lex_mlist;
	while (temp)
	{
		if (!strchr_metachar(temp->content) || strchr_quotes(temp->content))
			lexer_add_node(&g_prime->lexer, temp->content, 0);
		else
			lexer_add_node(&g_prime->lexer, temp->content, \
				chrchr_metachar(*(char *)temp->content));
		lex_mlist = temp;
		temp = temp->next;
		free(lex_mlist->content);
		free(lex_mlist);
	}
}
