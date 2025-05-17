/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:25:32 by tamadan           #+#    #+#             */
/*   Updated: 2023/12/13 12:09:34 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_operation(t_data *data)
{
	int		i;
	t_time	time;

	time = 0;
	i = 0;
	while (i < data->philo_nu)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &operation,
				&data->philo[i]))
		{
			free_destroy(data);
			return (ft_exit("Creating thread->failed.\n"));
		}
		i++;
		usleep(100);
	}
	i = 0;
	return (control(data, time));
}

void	aristo(t_philo *phi)
{
	if (phi->data->philo_nu == 1)
	{
		ft_sleep_time(phi, phi->data->death_timer);
		phi->data->defunct = 1;
	}
}

void	meal_time(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->forks[ph->id]);
	ft_write(1, ph, "has taken a fork", ft_get_time() - ph->timer);
	aristo(ph);
	pthread_mutex_lock(&ph->data->forks[(ph->id + 1) % (ph->data->philo_nu)]);
	ft_write(1, ph, "has taken a fork", ft_get_time() - ph->timer);
	checker(ph, 1);
	ft_write(2, ph, "eating", ft_get_time() - ph->timer);
	checker(ph, 2);
	if (ph->data->meal_timer <= ph->data->sleep_timer)
		ft_lastmeal(ph);
	ft_sleep_time(ph, ph->data->meal_timer);
	checker(ph, 2);
	if (ph->data->meal_timer > ph->data->sleep_timer)
		ft_lastmeal(ph);
	pthread_mutex_unlock(&ph->data->forks[ph->id]);
	pthread_mutex_unlock(&ph->data->forks[(ph->id + 1) % (ph->data->philo_nu)]);
	ft_write(2, ph, "sleeping", ft_get_time() - ph->timer);
	ft_sleep_time(ph, ph->data->sleep_timer);
	checker(ph, 2);
	ft_write(2, ph, "thinking", ft_get_time() - ph->timer);
}

void	*operation(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (1)
	{
		meal_time(ph);
	}
	return (0);
}

int	structinit(t_data *data, int ac, char *av[])
{
	int	i;

	i = 1;
	data->ac = ac;
	while (i < data->ac)
	{
		if (ft_checknum(av[i]))
			return (1);
		i++;
	}
	data->philo_nu = ft_atoi(av[1]);
	data->death_timer = ft_atoi(av[2]);
	data->meal_timer = ft_atoi(av[3]);
	data->sleep_timer = ft_atoi(av[4]);
	data->av = av;
	if (data->philo_nu <= 0 || data->death_timer <= 0 || data->sleep_timer <= 0
		|| data->sleep_timer <= 0 || data->meal_timer <= 0)
		return (ft_exit("Check arguments\n"));
	data->philo = malloc(sizeof(t_philo) * data->philo_nu);
	if (data->philo == 0)
	{
		free(data);
		return (ft_exit("Allocation failed\n"));
	}
	return (0);
}
