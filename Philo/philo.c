/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:25:32 by tamadan           #+#    #+#             */
/*   Updated: 2023/12/13 18:16:51 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_checknum(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+')
		i++;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (ft_exit("Check arguments\n"));
		}
		i++;
	}
	return (0);
}

int	philoinit(t_data *data)
{
	int	i;

	i = 0;
	data->defunct = 0;
	while (i < data->philo_nu)
	{
		data->philo[i].id = i;
		data->philo[i].data = data;
		data->philo[i].timer = ft_get_time();
		data->philo[i].last_meal = ft_get_time();
		if (data->ac == 6)
			data->round = ft_atoi(data->av[5]);
		if (data->ac == 6 && data->round <= 0)
		{
			free(data);
			free(data->philo);
			return (ft_exit("Check arguments\n"));
		}
		i++;
	}
	return (0);
}

int	round_check(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nu)
	{
		if (data->philo[i].c_eat != data->round)
			return (0);
		i++;
	}
	return (1);
}

int	control(t_data *data, t_time time)
{
	int	i;

	while (1)
	{
		i = 0;
		usleep(100);
		pthread_mutex_lock(data->death);
		time = ft_get_time() - data->philo->timer;
		i = ft_death_check(data->philo, time);
		if (i != -1)
			return (0);
		else if (data->ac == 6 && round_check(data))
			return (0);
		pthread_mutex_unlock(data->death);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_data	*data;

	if (ac == 5 || ac == 6)
	{
		data = malloc(sizeof(t_data));
		if (data == 0)
			return (ft_exit("Allocation failed\n"));
		if (structinit(data, ac, av))
			return (1);
		if (philoinit(data))
			return (1);
		if (mutexinit(data))
			return (1);
		if (start_operation(data))
			return (1);
		free_destroy(data);
		return (0);
	}
	else
		return (ft_exit("Check arguments\n"));
}
