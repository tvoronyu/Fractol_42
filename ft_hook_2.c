/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 12:59:19 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/08/19 13:00:15 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_key_126(t_struct *ptr)
{
	if (ptr->id == 0)
	{
		ptr->y_move += 0.05;
		ft_mandelbrot(ptr);
	}
	else if (ptr->id == 1)
	{
		ptr->y_move += 0.01;
		ft_julia(ptr);
	}
	else if (ptr->id == 2)
	{
		ptr->y_move -= 5.0;
		ft_fern(ptr);
	}
	else if (ptr->id == 4)
	{
		ptr->trik.a_y -= 10;
		ptr->trik.b_y -= 10;
		ptr->trik.c_y -= 10;
		ft_trik(ptr);
	}
}

void	ft_key_125(t_struct *ptr)
{
	if (ptr->id == 0)
	{
		ptr->y_move -= 0.05;
		ft_mandelbrot(ptr);
	}
	else if (ptr->id == 1)
	{
		ptr->y_move -= 0.01;
		ft_julia(ptr);
	}
	else if (ptr->id == 2)
	{
		ptr->y_move += 5.0;
		ft_fern(ptr);
	}
	else if (ptr->id == 4)
	{
		ptr->trik.a_y += 10;
		ptr->trik.b_y += 10;
		ptr->trik.c_y += 10;
		ft_trik(ptr);
	}
}

void	ft_key_123(t_struct *ptr)
{
	if (ptr->id == 0)
	{
		ptr->x_move += 0.05;
		ft_mandelbrot(ptr);
	}
	else if (ptr->id == 1)
	{
		ptr->x_move += 0.01;
		ft_julia(ptr);
	}
	else if (ptr->id == 2)
	{
		ptr->x_move -= 5.0;
		ft_fern(ptr);
	}
	else if (ptr->id == 4)
	{
		ptr->trik.a_x -= 10;
		ptr->trik.b_x -= 10;
		ptr->trik.c_x -= 10;
		ft_trik(ptr);
	}
}

void	ft_key_124(t_struct *ptr)
{
	if (ptr->id == 0)
	{
		ptr->x_move -= 0.05;
		ft_mandelbrot(ptr);
	}
	else if (ptr->id == 1)
	{
		ptr->x_move -= 0.01;
		ft_julia(ptr);
	}
	else if (ptr->id == 2)
	{
		ptr->x_move += 5.0;
		ft_fern(ptr);
	}
	else if (ptr->id == 4)
	{
		ptr->trik.a_x += 10;
		ptr->trik.b_x += 10;
		ptr->trik.c_x += 10;
		ft_trik(ptr);
	}
}
