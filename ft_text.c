/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 13:56:44 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/08/19 14:44:28 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_usage(void)
{
	ft_putendl("ZOOM   			scroll mouse");
	ft_putendl("Iterations  		'+' and '-' of NumPud");
	ft_putendl("Chanche colors  	'8' of NumPud");
	ft_putendl("Move  			'up' 'down' 'right' 'left'");
	ft_putendl("Reset fractol  		'space'");
	ft_putendl("Stop mooving julia  	'S'");
	ft_putendl("Exit   			'Esc'");
}

int		ft_bgzm(int size)
{
	int n;

	n = 10;
	while (size > 0)
	{
		n = n * 10;
		size--;
	}
	return (n);
}

char	*ft_big_zoom(double value, int size)
{
	int tmp;
	int tmp_2;

	tmp = value;
	tmp_2 = (value - tmp) * ft_bgzm(size);
	return (ft_strjoin(ft_strjoin(ft_itoa(tmp), ","), ft_itoa(tmp_2)));
}

char	*ft_text_help(double value, int size)
{
	int	tmp;

	if ((int)value > 0)
		return (ft_big_zoom(value, size));
	tmp = value * ft_bgzm(size);
	if (tmp == 0)
		return ("STOP ZOOM!");
	return (ft_strjoin("0,", ft_itoa(tmp)));
}

char	*ft_text(double value, int size)
{
	return (ft_text_help(value, size));
}
