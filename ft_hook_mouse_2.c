/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_mouse_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 13:00:54 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/08/19 13:02:48 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_key_5_help(t_struct *ptr)
{
	if (ptr->id == 2)
	{
		if (ptr->depth < 10E7)
			ptr->depth++;
		ptr->radius += 0.01;
		ft_fern(ptr);
	}
	else if (ptr->id == 4)
	{
		if (ft_perevirka_trik_plus(ptr) == 1)
		{
			ptr->depth += 100;
			ptr->trik.a_x -= 100;
			ptr->trik.a_y += 100;
			ptr->trik.b_y -= 100;
			ptr->trik.c_x += 100;
			ptr->trik.c_y += 100;
		}
		ft_trik(ptr);
	}
}

void	ft_key_5(t_struct *ptr)
{
	if (ptr->id == 0)
	{
		if (ptr->depth < 10E7 && ptr->zoom > 30)
			ptr->depth++;
		ptr->zoom *= 1.05;
		ft_mandelbrot(ptr);
	}
	else if (ptr->id == 1)
	{
		if (ptr->depth < 10E7)
			ptr->depth++;
		ptr->zoom *= 1.05;
		ft_julia(ptr);
	}
	else
		ft_key_5_help(ptr);
}
