#include "fractol.h"

void	ft_julia_asigned(t_struct *ptr)
{
	ptr->depth = 200;
	ptr->Re = -0.8169;
    ptr->Im = -0.1189;
    ptr->zoom = 1,0000;
    ptr->x_move = 0;
    ptr->y_move = 0;
    ptr->mouseRe = 0;
    ptr->mouseIm = 0;
    ptr->stop_julia = 1;
    ptr->color = 23;
}


void ft_julia_init(t_struct *ptr, int x, int y, int y_max) 
{
	t_julia sv;

    int y1 = y;
    while (x++ < W)
    {
    	y = y1 + 500;
        while (y++ < y_max + 500)
        {
            sv.Re = 1.5 * (x - W / 2) / (0.5 * ptr->zoom * W) + ptr->x_move + ptr->mouseRe;
            sv.Im = (y - H / 2) / (0.5 * ptr->zoom * H) + ptr->y_move + ptr->mouseIm;
            int i = 0;;
            while (i++ < ptr->depth)
            {
                sv.Re_old = sv.Re;
                sv.Im_old = sv.Im;
                sv.Re = sv.Re_old * sv.Re_old - sv.Im_old * sv.Im_old + ptr->Re;
                sv.Im = 2 * sv.Re_old * sv.Im_old + ptr->Im;
                if ((sv.Re * sv.Re + sv.Im * sv.Im) > 10E16) break;
            }
            ft_pixel_color_julia(ptr, x, y, i * 245 * ptr->color, 0);
        }
    }
}

void	ft_julia(t_struct *ptr)
{
	
	if (ft_strcmp("STOP ZOOM!", ft_text(ptr->zoom, 7)) != 0)
	{
		ft_bzero(ptr->mlx_addr, W * H * 4);
		ft_threads(ptr);
		ptr->block = 0;
	}
	else
		ptr->block = 1;
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->mlx_img, 0, 0);
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 20, 20, 0xffff00, ft_strjoin("Re value    -", ft_text(-ptr->Re, 7)));
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 20, 40, 0xffff00, ft_strjoin("Im value    -", ft_text(-ptr->Im, 7)));
}