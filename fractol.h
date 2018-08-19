/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 14:02:48 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/08/19 14:16:38 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <pthread.h>
# define W 1000
# define H 1000
# define N 50

typedef	struct	s_mandel
{
	double ci;
	double cr;
	double tmp;
	double zr;
	double zr_2;
	double zi;
	double zi_2;
}				t_mandel;

typedef struct	s_fern
{
	double	x;
	double	y;
	double	t;
	int		p;
	int		mid_x;
	int		mid_y;
	long	k;
}				t_fern;

typedef struct	s_trik
{
	int	x;
	int	y;
	int	a_x;
	int	a_y;
	int	b_x;
	int	b_y;
	int	c_x;
	int	c_y;
}				t_trik;

typedef struct	s_julia
{
	double re;
	double im;
	double re_old;
	double im_old;
}				t_julia;

typedef struct	s_struct
{
	t_mandel	mandel;
	t_trik		trik;
	t_julia		julia;
	t_fern		fern;

	int			depth;
	int			id;
	double		y_move;
	double		x_move;
	int			color;
	double		zoom;
	void		*mlx_ptr;
	void		*mlx_win;
	void		*mlx_img;
	char		*mlx_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	double		mousere;
	double		mouseim;
	double		re;
	double		im;
	double		radius;
	int			stop_julia;
	int			block;
}				t_struct;

typedef struct	s_threads
{
	t_struct	*ptr;
	pthread_t	threads;
	int			n;

}				t_threads;

void			ft_fractol(char *name);
void			ft_mlx_init(t_struct *ptr);
void			usage_help(void);
void			ft_enter_fractol(t_struct *ptr);
int				ft_count_pixel(t_struct *ptr, int x, int y);
char			*ft_text(double value, int size);

int				exit_x(t_struct *ptr);
int				deal_key(int key, t_struct *ptr);
int				deal_key_mouse(int key, int x, int y, t_struct *ptr);
int				deal_key_mouse_1(int x, int y, t_struct *ptr);
void			ft_key_69(t_struct *ptr);
void			ft_key_78(t_struct *ptr);
void			ft_key_126(t_struct *ptr);
void			ft_key_125(t_struct *ptr);
void			ft_key_124(t_struct *ptr);
void			ft_key_123(t_struct *ptr);
void			ft_key_4(t_struct *ptr);
void			ft_key_5(t_struct *ptr);

void			ft_threads(t_struct *ptr);
void			ft_mandelbrot(t_struct *ptr);
void			ft_mandelbrot_init(t_struct *ptr, int x, int y, int y_max);
void			ft_mandelbrot_asigned(t_struct *ptr);
void			ft_pixel_color_mandelbrot(t_struct *ptr,
		int i, int color, int flag);
void			ft_mandelbrot_init_help(t_struct *ptr, int x, int y, int y_max);

void			ft_julia(t_struct *ptr);
void			ft_julia_init(t_struct *ptr, int x, int y, int y_max);
void			ft_julia_asigned(t_struct *ptr);
void			ft_find_julia(t_struct *ptr, int x, int y, t_mandel *sv);
void			ft_pixel_color_julia(t_struct *ptr, int x, int y, int color);
void			ft_stop_julia(t_struct *ptr);
void			ft_colors_keys(t_struct *ptr);

void			ft_fern(t_struct *ptr);
void			ft_fern_asigned(t_struct *ptr);
void			ft_pixel_color_fern(t_struct *ptr, int x, int y, int color);

void			ft_tree(t_struct *ptr);
double			random_me(int n, int it);

void			ft_trik(t_struct *ptr);
void			ft_trik_asigned(t_struct *ptr);
int				ft_perevirka_trik_plus(t_struct *ptr);
int				ft_perevirka_trik_negative(t_struct *ptr);
#endif
