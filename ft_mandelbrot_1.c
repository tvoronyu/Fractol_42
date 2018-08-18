#include "fractol.h"

void	ft_mandelbrot_asigned(t_struct *ptr)
{
	ptr->depth = 50;
	ptr->zoom = 200;
	ptr->x_move = 0;
	ptr->y_move = 0;
	ptr->color = 1;
}

void	ft_find_mandelbrot(t_struct *ptr, int x, int y, t_mandel *sv)
{
	while (x++ < W / 2)
	{
		sv->cr = (float)x / ptr->zoom + ptr->x_move -0.5;
		sv->zr = sv->cr;
		sv->zi = sv->ci;
        int flag = 1;
        int n = 0;
        while (n++ < ptr->depth)
        {
            sv->zr_2 = sv->zr * sv->zr;
            sv->zi_2 = sv->zi * sv->zi;
            if(sv->zr_2 + sv->zi_2 > 1.0E5)
            {
                flag = 0;
                break;
            }
            sv->zi = 2 * sv->zr * sv->zi + sv->ci;
            sv->zr = sv->zr_2 - sv->zi_2 + sv->cr;
        }
        if(flag)
        	ft_pixel_color_mandelbrot(ptr, x + W / 2, y + H / 2, n * 265, 1);
        else
        	ft_pixel_color_mandelbrot(ptr, x + W / 2, y + H / 2, n * 265  * ptr->color, 0);
	}
}



void	ft_mandelbrot_init(t_struct *ptr, int x, int y, int y_max)
{
	t_mandel sv;
	while (y < y_max)
	{
		
		sv.ci = y / ptr->zoom + ptr->y_move + 0.1;  
		x = (W / 2) * -1;
		ft_find_mandelbrot(ptr, x, y, &sv);
		y++;
	}
}

void	ft_mandelbrot(t_struct *ptr)
{
	ft_bzero(ptr->mlx_addr, W * H * 4);
	ft_threads(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->mlx_img, 0, 0);
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 20, 20, 0xffff00, ft_strjoin("Iterations   ",ft_itoa(ptr->depth)));
}