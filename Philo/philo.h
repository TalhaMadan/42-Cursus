/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:25:32 by tamadan           #+#    #+#             */
/*   Updated: 2023/12/13 18:16:14 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef unsigned long long	t_time;

typedef struct s_philo
{
	int				id;
	int				c_eat;
	t_time			timer;
	t_time			last_meal;
	pthread_t		thread;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				death_timer;
	int				sleep_timer;
	int				philo_nu;
	int				defunct;
	int				round;
	int				meal_timer;
	int				ac;
	char			**av;
	t_philo			*philo;
	pthread_mutex_t	*death;
	pthread_mutex_t	*forks;
}	t_data;

int		ft_atoi(char *str);
int		structinit(t_data *data, int ac, char *av[]);
int		philoinit(t_data *data);
int		mutexinit(t_data *data);
int		start_operation(t_data *data);
int		ft_checknum(char *str);
int		ft_exit(char *str);
int		ft_death_check(t_philo *phi, t_time time);
int		round_check(t_data *data);
int		control(t_data *data, t_time time);

void	*operation(void *philo);
void	ft_lastmeal(t_philo *philo);
void	free_destroy(t_data *data);
void	ft_write(int action, t_philo *ph, char *str, t_time time);
void	ft_sleep_time(t_philo *phi, int ttime);
void	checker(t_philo *philo, int checker);
void	aristo(t_philo *phi);
t_time	ft_get_time(void);

#endif