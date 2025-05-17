/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metachar_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:02:41 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 12:02:42 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

int	chrchr_metachar(char c)
{
	if (c == PIPE)
		return (SIGN_PIPE);
	else if (c == SOR)
		return (SIGN_SOR);
	else if (c == SIR)
		return (SIGN_SIR);
	else
		return (TEXT);
}

int	strchr_metachar(char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (chrchr_metachar(content[i]))
			return (1);
		i++;
	}
	return (0);
}
