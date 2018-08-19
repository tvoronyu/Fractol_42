/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 13:03:30 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/08/19 13:20:59 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_julia_asigned(t_struct *ptr)
{
	ptr->depth = 200;
	ptr->re = -0.8169;
	ptr->im = -0.1189;
	ptr->zoom = 1.0000;
	ptr->x_move = 0;
	ptr->y_move = 0;
	ptr->mousere = 0;
	ptr->mouseim = 0;
	ptr->stop_julia = 1;
	ptr->color = 23;
}

void		ft_julia_help(t_struct *ptr, int x, int y, int y_max)
{
	t_julia	sv;
	int		y1;
	int		i;

	y1 = y;
	y = y1 + 500;
	while (y++ < y_max + 500)
	{
		sv.re = 1.5 * (x - W / 2) / (0.5 * ptr->zoom * W)
			+ ptr->x_move + ptr->mousere;
		sv.im = (y - H / 2) / (0.5 * ptr->zoom * H)
			+ ptr->y_move + ptr->mouseim;
		i = 0;
		while (i++ < ptr->depth)
		{
			sv.re_old = sv.re;
			sv.im_old = sv.im;
			sv.re = sv.re_old * sv.re_old - sv.im_old * sv.im_old + ptr->re;
			sv.im = 2 * sv.re_old * sv.im_old + ptr->im;
			if ((sv.re * sv.re + sv.im * sv.im) > 10E16)
				break ;
		}
		ft_pixel_color_julia(ptr, x, y, i * 245 * ptr->color);
	}
}

void		ft_julia_init(t_struct *ptr, int x, int y, int y_max)
{
	while (x++ < W)
		ft_julia_help(ptr, x, y, y_max);
}

void		ft_julia(t_struct *ptr)
{
	if (ft_strcmp("STOP ZOOM!", ft_text(ptr->zoom, 7)) != 0)
	{
		ft_bzero(ptr->mlx_addr, W * H * 4);
		ft_threads(ptr);
		ptr->block = 0;
	}
	else
		ptr->block = 1;
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->mlx_img, 0, 0);
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 20, 20,
			0xffff00, ft_strjoin("Re value    -", ft_text(-ptr->re, 7)));
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 20, 40,
			0xffff00, ft_strjoin("Im value    -", ft_text(-ptr->im, 7)));
}
