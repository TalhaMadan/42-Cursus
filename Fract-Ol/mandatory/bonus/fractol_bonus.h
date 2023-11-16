/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:05:19 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/02 20:18:49 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "../mlx/mlx.h"
# include "my_complex_bonus.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_WIDTH 1024
# define WIN_HEIGHT 1024

# define ZOOM -8

# define MAX_ITER 50
# define MOVE_STEP 61

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define LEFT_CLICK 1

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

# define FRACT_NONE 0
# define FRACT_MANDEL 1
# define FRACT_JULIA 2

typedef short	t_calo;

typedef struct s_m
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_m;

typedef struct s_point
{
	double		posx;
	double		posy;
	double		coorx;
	double		coory;
}				t_point;

typedef struct s_data
{
	t_m			m;
	t_point		base;
	int			max_iter;
	double		zoom;
	double		zo_rate;
	int			color;
	t_complex	julia_constant;
	int			(*fract_func)(struct s_data *, int, int);
}				t_data;

t_complex		calculate_coor(int pos_x, int pos_y, t_point base,
					double zo_rate);
t_complex		calculate_new_position(t_complex current, t_complex start);
t_point			move_base(t_point base, int pos_x, int pos_y, double zo_rate);

int				get_palette(void);
int				get_iter_mandelbrot(t_data *d, int pos_x, int pos_y);
int				get_iter_julia(t_data *d, int pos_x, int pos_y);
int				design_fracts(t_data *data);

void			my_mlx_pixel_put(t_m *data, int x, int y, int color);
void			ft_putstr(char *str);
void			init_mlx(t_data *d);
void			init_data(t_data *data, t_calo fract_type, char **av);

int				mouse_hook(int keycode, int x, int y, t_data *data);

int				key_hook(int keycode, t_data *data);
int				close_win(t_m *mlx);

unsigned int	ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);

int				ft_isdigit(int c);
int				is_str_digit(const char *str);
double			ft_atof(const char *str);
int				ft_atoi(const char *nptr);

unsigned int	ft_count_c_in_str(const char *str, const char c);

t_calo			check_args(int ac, char **av);
void			init_data(t_data *data, t_calo fractal_type, char **av);
int				design_fracts(t_data *data);
void			show_parameters(void);
void			show_params_and_exit_fail(void);

#endif