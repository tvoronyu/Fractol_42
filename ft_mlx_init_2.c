#include "fractol.h"

int  	ft_count_pixel(t_struct *ptr, int x, int y)
{
	if (y > 0)
		return (y * ptr->size_line + x * 4);
	else if (y == 0)
		return (ptr->size_line + x * 4);
	else if (y < 0)
		return (0);
	return (0);
}

void	ft_enter_fractol(t_struct *ptr)
{
	if (ptr->id == 0)
	{
		ft_mandelbrot_asigned(ptr);
		ft_mandelbrot(ptr);
	}
	else if (ptr->id == 1)
	{
		ft_julia_asigned(ptr);
		ft_julia(ptr);
	}
	else if (ptr->id == 2)
	{
		ft_fern_asigned(ptr);
		ft_fern(ptr);
	}
	else if (ptr->id == 4)
	{
		ft_trik_asigned(ptr);
		ft_trik(ptr);
	}
}

void	ft_mlx_init(t_struct *ptr)
{
	ptr->mlx_ptr = mlx_init();
	ptr->mlx_win = mlx_new_window(ptr->mlx_ptr, W, H, "Fractol");
	ptr->mlx_img = mlx_new_image(ptr->mlx_ptr, W, H);
	ptr->mlx_addr = mlx_get_data_addr(ptr->mlx_img, &ptr->bits_per_pixel, &ptr->size_line, &ptr->endian);
	


	ft_enter_fractol(ptr);
	



	mlx_hook(ptr->mlx_win, 17, 1L << 17, exit_x, ptr);
	mlx_hook(ptr->mlx_win, 2, 5, deal_key, ptr);
	mlx_hook(ptr->mlx_win, 6, 1L, deal_key_mouse_1, ptr);
	mlx_mouse_hook(ptr->mlx_win, deal_key_mouse, ptr);
	mlx_loop(ptr->mlx_ptr);
}