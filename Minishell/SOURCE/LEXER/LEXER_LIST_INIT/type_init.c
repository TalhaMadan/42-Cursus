/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:36:18 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 11:36:19 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

static void	type_match(t_lexer *temp)
{
	if (temp->type == SIGN_SIR && ft_strlen(temp->content) == 2)
		temp->type = HEREDOC;
	else if (temp->type == SIGN_SOR && ft_strlen(temp->content) == 2)
		temp->type = SIGN_DOR;
	else if (temp->type == SIGN_SIR && ft_strlen(temp->content) > 2)
		temp->type = -3;
	else if (temp->type == SIGN_PIPE && ft_strlen(temp->content) > 1)
		temp->type = -1;
	else if (temp->type == SIGN_SOR && ft_strlen(temp->content) > 2)
		temp->type = -2;
}

void	type_init(t_prime *g_prime)
{
	t_lexer	*temp;

	temp = g_prime->lexer;
	while (temp)
	{
		if (temp->type != 0)
			type_match(temp);
		temp = temp->next;
	}
}
