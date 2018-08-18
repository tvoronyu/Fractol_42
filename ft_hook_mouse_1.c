#include "fractol.h"

void	ft_key_4_help_id_4(t_struct *ptr)
{
	if (ft_perevirka_trik_negative(ptr) == 1)
	{
		ptr->depth -= 100;
		ptr->trik.a_x += 100;
		ptr->trik.a_y -= 100;
		ptr->trik.b_y += 100;
		ptr->trik.c_x -= 100;
		ptr->trik.c_y -= 100;
	}
	else if (ptr->trik.a_x + 20 <= ptr->trik.c_x)
	{
		ptr->trik.a_x += 10;
		ptr->trik.a_y -= 10;
		ptr->trik.b_y += 10;
		ptr->trik.c_x -= 10;
		ptr->trik.c_y -= 10;
	}
	if (ptr->trik.a_x + 2 <= ptr->trik.c_x)
	{
		ptr->trik.a_x += 1;
		ptr->trik.a_y -= 1;
		ptr->trik.b_y += 1;
		ptr->trik.c_x -= 1;
		ptr->trik.c_y -= 1;
	}
}

void	ft_key_help(t_struct *ptr)
{
	if (ptr->id == 1 && ptr->block == 0)
	{
		if (ptr->depth > 10)
			ptr->depth--;
		ptr->zoom /= 1.05;
		ft_julia(ptr);
	}
	else if (ptr->id == 2)
	{
		if (ptr->depth > 0)
			ptr->depth--;
		if (ptr->radius - 0.01 > 0)
			ptr->radius -= 0.01;
		if (ptr->radius > 0.005 && ptr->radius < 0.007)
			ptr->radius = 0;
		else if (ptr->radius > 0.009 && ptr->radius < 0.02)
			ptr->radius = 0;
		ft_fern(ptr);
	}
}

void	ft_key_4(t_struct *ptr)
{
	if (ptr->id == 0)
	{
		if (ptr->depth > 10)
			ptr->depth--;
		ptr->zoom /= 1.05;
		ft_mandelbrot(ptr);
	}
	else if (ptr->id == 4)
	{
		ft_key_4_help_id_4(ptr);
		ft_trik(ptr);
	}
	else
		ft_key_help(ptr);
}