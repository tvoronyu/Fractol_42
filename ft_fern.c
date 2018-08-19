/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 12:46:52 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/08/19 12:52:57 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fern_asigned(t_struct *ptr)
{
	ptr->x_move = 0;
	ptr->y_move = 0;
	ptr->radius = 0.057;
	ptr->depth = 500000;
}

void	ft_fern_help(t_struct *ptr)
{
	if (ptr->fern.p <= 85 && ptr->fern.p > 1)
	{
		ptr->fern.x = 0.84 * ptr->fern.x - 0.045 * ptr->fern.y;
		ptr->fern.y = 0.045 * ptr->fern.t + 0.86 * ptr->fern.y + 2.6;
	}
	else if (ptr->fern.p <= 92 && ptr->fern.p > 85)
	{
		ptr->fern.x = 0.20 * ptr->fern.x - 0.26 * ptr->fern.y;
		ptr->fern.y = 0.23 * ptr->fern.t + 0.25 * ptr->fern.y + 2.6;
	}
	else if (ptr->fern.p <= 99 && ptr->fern.p > 92)
	{
		ptr->fern.x = -0.135 * ptr->fern.x + 0.28 * ptr->fern.y;
		ptr->fern.y = 0.26 * ptr->fern.t + 0.245 * ptr->fern.y + 1.44;
	}
	else
	{
		ptr->fern.x = 0.0;
		ptr->fern.y = 0.16 * ptr->fern.y;
	}
}

void	ft_fern_init(t_struct *ptr)
{
	int radius;

	ptr->fern.mid_x = W / 2;
	ptr->fern.mid_y = H - 100;
	radius = trunc(ptr->radius * ptr->fern.mid_y);
	ptr->fern.x = 1.0;
	ptr->fern.y = 1.0;
	ptr->fern.k = 1;
	while (ptr->fern.k++ < ptr->depth)
	{
		ptr->fern.p = random() % 100;
		ptr->fern.t = ptr->fern.x;
		ft_fern_help(ptr);
		ft_pixel_color_fern(ptr, ptr->fern.mid_x + round(radius
					* ptr->fern.x) + ptr->x_move, ptr->fern.mid_y -
				round(radius * ptr->fern.y) + 35 + ptr->y_move, 225);
	}
}

void	ft_fern(t_struct *ptr)
{
	ft_bzero(ptr->mlx_addr, W * H * 4);
	ft_fern_init(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->mlx_img, 0, 0);
}
