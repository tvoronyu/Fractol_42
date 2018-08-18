#include "fractol.h"

void	ft_pixel_color_mandelbrot(t_struct *ptr, int x, int y, int color, int flag)
{
	int i = ft_count_pixel(ptr, x, y - 1);
	if (flag)
	{
		ptr->mlx_addr[i] = 0;
		ptr->mlx_addr[i + 1] = 0;
		ptr->mlx_addr[i + 2] = 0x000000;
	}
	else
	{
		ptr->mlx_addr[i] = color>>8;
		ptr->mlx_addr[i + 1] = color<<8;
		ptr->mlx_addr[i + 2] = color;
	}
}

void	ft_pixel_color_julia(t_struct *ptr, int x, int y, int color, int flag)
{
	int i = ft_count_pixel(ptr, x, y - 1);
	flag = 0;
	ptr->mlx_addr[i] = color * 2;
	ptr->mlx_addr[i + 1] = color % 10 * 3;
	ptr->mlx_addr[i + 2] = color - 7;
}

void	ft_pixel_color_fern(t_struct *ptr, int x, int y, int color, int flag)
{
	if (x < W && y < H && x > 0 && y > 0)
	{
		int i = ft_count_pixel(ptr, x, y - 1);
		if (flag)
		{
			ptr->mlx_addr[i] = 0;
			ptr->mlx_addr[i + 1] = 0;
			ptr->mlx_addr[i + 2] = 0x000000;
		}
		else
		{
			ptr->mlx_addr[i] = 59;
			ptr->mlx_addr[i + 1] = color;
			ptr->mlx_addr[i + 2] = 2;
		}
	}
}