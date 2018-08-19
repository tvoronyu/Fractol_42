/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 13:39:30 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/08/19 13:56:23 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_color_mandelbrot(t_struct *ptr, int i, int color, int flag)
{
	if (flag)
	{
		ptr->mlx_addr[i] = 0;
		ptr->mlx_addr[i + 1] = 0;
		ptr->mlx_addr[i + 2] = 0x000000;
	}
	else
	{
		ptr->mlx_addr[i] = color >> 8;
		ptr->mlx_addr[i + 1] = color << 8;
		ptr->mlx_addr[i + 2] = color;
	}
}

void	ft_pixel_color_julia(t_struct *ptr, int x, int y, int color)
{
	int i;

	i = ft_count_pixel(ptr, x, y - 1);
	ptr->mlx_addr[i] = color * 2;
	ptr->mlx_addr[i + 1] = color % 10 * 3;
	ptr->mlx_addr[i + 2] = color - 7;
}

void	ft_pixel_color_fern(t_struct *ptr, int x, int y, int color)
{
	int i;

	if (x < W && y < H && x > 0 && y > 0)
	{
		i = ft_count_pixel(ptr, x, y - 1);
		ptr->mlx_addr[i] = 59;
		ptr->mlx_addr[i + 1] = color;
		ptr->mlx_addr[i + 2] = 2;
	}
}
