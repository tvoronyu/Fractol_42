/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 12:53:45 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/08/19 12:55:44 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		random_me(int n, int it)
{
	int p;

	if (n < 11)
	{
		p = random() % 10;
		if (p < n && p > 0)
			return (p);
	}
	else if (n > 10)
	{
		p = random() % 100;
		if (p < n && p > 0)
			return (p);
	}
	random_me(n, it);
	return (2);
}

int			ft_name_check(char *name)
{
	if (ft_strcmp("mandelbrot", name) == 0 || ft_strcmp("1", name) == 0)
		return (0);
	else if (ft_strcmp("julia", name) == 0 || ft_strcmp("2", name) == 0)
		return (1);
	else if (ft_strcmp("fern", name) == 0 || ft_strcmp("3", name) == 0)
		return (2);
	else if (ft_strcmp("triangle", name) == 0 || ft_strcmp("4", name) == 0)
		return (4);
	usage_help();
	exit(1);
}

void		ft_fractol(char *name)
{
	t_struct ptr[1];

	ft_usage();
	ptr->id = ft_name_check(name);
	ft_mlx_init(ptr);
}
