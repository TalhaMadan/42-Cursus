/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:25:32 by tamadan           #+#    #+#             */
/*   Updated: 2023/12/13 18:16:14 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	long	sign;
	long	result;
	long	idx;

	sign = 1;
	result = 0;
	idx = 0;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
	}
	while (str[idx] && str[idx] <= '9' && str[idx] >= '0')
	{
		result = (result * 10) + (str[idx] - 48) * sign;
		if (result > 2147483647)
			return (0);
		if (result < -2147483648)
			return (-1);
		idx++;
	}
	return (result);
}

t_time	ft_get_time(void)
{
	struct timeval	timevl;
	t_time			time;

	gettimeofday(&timevl, NULL);
	time = timevl.tv_sec * 1000 + timevl.tv_usec / 1000;
	return (time);
}

void	ft_sleep_time(t_philo *phi, int ttime)
{
	t_time	time;

	time = ft_get_time();
	if ((t_time)phi->data->death_timer < (time - phi->last_meal)
		+ (t_time)ttime)
	{
		ttime = phi->data->death_timer - (time - phi->last_meal);
		while (ft_get_time() - time <= (t_time)ttime)
			usleep(100);
	}
	else
	{
		while (ft_get_time() - time < (t_time)ttime)
			usleep(100);
	}
}

void	checker(t_philo *philo, int checker)
{
	pthread_mutex_lock(philo->data->death);
	if (checker == 1)
	{
		if (philo->data->ac == 6 && philo->c_eat < philo->data->round)
			philo->c_eat++;
	}
	else
	{
		if (philo->data->death_timer < (int)(ft_get_time() - philo->last_meal))
		{
			philo->data->defunct = 1;
		}
	}
	pthread_mutex_unlock(philo->data->death);
}

int	ft_death_check(t_philo *phi, t_time time)
{
	int	i;

	i = 0;
	while (i < phi->data->philo_nu)
	{
		if (phi->data->defunct == 1 && (int)time > phi->data->death_timer)
		{
			usleep(100);
			printf("%llu %d died\n", time, i + 1);
			return (i);
		}
		i++;
	}
	return (-1);
}
