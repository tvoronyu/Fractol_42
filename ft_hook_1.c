/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 12:57:15 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/08/19 12:59:00 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_key_69(t_struct *ptr)
{
	if (ptr->id == 0)
	{
		if (ptr->depth < 2147483647)
			ptr->depth++;
		ft_mandelbrot(ptr);
	}
	else if (ptr->id == 1)
	{
		if (ptr->depth < 2147483647)
			ptr->depth++;
		ft_julia(ptr);
	}
	else if (ptr->id == 2)
	{
		ptr->depth *= 1.5;
		ft_fern(ptr);
	}
	else if (ptr->id == 4)
	{
		if (ptr->depth * 2 < 21000000)
			ptr->depth *= 2;
		ft_trik(ptr);
	}
}

void	ft_key_78(t_struct *ptr)
{
	if (ptr->id == 0)
	{
		if (ptr->depth - 10 > 0)
			ptr->depth--;
		ft_mandelbrot(ptr);
	}
	else if (ptr->id == 1)
	{
		if (ptr->depth - 10 > 0)
			ptr->depth--;
		ft_julia(ptr);
	}
	else if (ptr->id == 2)
	{
		ptr->depth /= 1.5;
		ft_fern(ptr);
	}
	else if (ptr->id == 4)
	{
		if (ptr->depth / 2 < 21000000)
			ptr->depth /= 2;
		ft_trik(ptr);
	}
}

void	ft_stop_julia(t_struct *ptr)
{
	if (ptr->stop_julia == 1)
		ptr->stop_julia = 0;
	else
		ptr->stop_julia = 1;
	ft_julia(ptr);
}

void	ft_colors_keys(t_struct *ptr)
{
	if (ptr->id == 0)
	{
		ptr->color++;
		ft_mandelbrot(ptr);
	}
	else if (ptr->id == 1)
	{
		ptr->color++;
		ft_julia(ptr);
	}
}
