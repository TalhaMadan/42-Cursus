/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:25:32 by tamadan           #+#    #+#             */
/*   Updated: 2023/12/13 18:16:14 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_write(int action, t_philo *ph, char *str, t_time time)
{
	pthread_mutex_lock(ph->data->death);
	if (ph->data->defunct == 0)
	{
		if (action == 1)
			printf("%llu %d %s\n", time, ph->id + 1, str);
		else
			printf("%llu %d is %s\n", time, ph->id + 1, str);
	}
	pthread_mutex_unlock(ph->data->death);
}

void	free_destroy(t_data *data)
{
	pthread_mutex_destroy(data->death);
	pthread_mutex_destroy(data->forks);
	free(data->philo);
	free(data);
}

void	ft_lastmeal(t_philo *philo)
{
	pthread_mutex_lock(philo->data->death);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(philo->data->death);
}

int	ft_exit(char *str)
{
	printf("%s", str);
	return (1);
}

int	mutexinit(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_nu);
	data->death = malloc(sizeof(pthread_mutex_t));
	if (data->forks == 0 || data->death == 0)
	{
		free(data);
		free(data->philo);
		return (ft_exit("Allocation failed\n"));
	}
	while (i < data->philo_nu)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(data->death, NULL);
	return (0);
}
