/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:16:25 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 11:16:26 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

void	start_pwd(t_prime *g_prime, t_parser *parser)
{
	char	cwd[256];
	char	*pwd;

	pwd = getcwd(cwd, 256);
	write(parser->outfile, pwd, ft_strlen(pwd));
	write(parser->outfile, "\n", 1);
	g_prime->exit_code = 0;
}
