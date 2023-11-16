/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:10:29 by tamadan           #+#    #+#             */
/*   Updated: 2023/08/28 19:58:52 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	int	ft_atoi(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = j * 10;
		j += str[i] - '0';
		i++;
	}
	return (j);
}

void	ft_kill(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("enter two arguments\n");
		return (0);
	}
	ft_kill(ft_atoi(argv[1]), argv[2]);
	ft_kill(ft_atoi(argv[1]), "\n");
}
