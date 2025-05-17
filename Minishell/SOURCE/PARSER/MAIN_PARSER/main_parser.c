/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:06:44 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 12:06:45 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

void	parser(t_prime *g_prime)
{
	if (!g_prime->expander)
		return ;
	parser_addnode(&g_prime->parser, pipe_count(g_prime));
	heredoc_init(g_prime);
	if (!g_prime->parser)
		return ;
	renew_parser(g_prime);
}
