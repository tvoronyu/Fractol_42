/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 14:01:51 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/08/19 14:02:16 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_x(t_struct *ptr)
{
	mlx_destroy_window(ptr->mlx_ptr, ptr->mlx_win);
	ptr = NULL;
	exit(0);
	return (0);
}

void	usage_help(void)
{
	ft_putstr("__________________________________\n\n");
	ft_putstr("\n  usage: ./fractol fractol_name\n");
	ft_putstr("__________________________________\n");
	ft_putstr("  1: mandelbrot\n");
	ft_putstr("  2: julia\n");
	ft_putstr("  3: fern\n");
	ft_putstr("  4: triangle\n");
}

int		main(int argc, char *argv[])
{
	if (argc < 2)
		usage_help();
	else if (argc > 2)
	{
		ft_putstr("\n  too many argument\n");
		usage_help();
	}
	else if (argc == 2)
		ft_fractol(argv[1]);
	return (0);
}
