#include "fractol.h"

void	ft_trik_asigned(t_struct *ptr)
{
	ptr->depth = 500;
	ptr->trik.a_x = 0;
	ptr->trik.a_y = 1000;
	ptr->trik.b_x = 500;
	ptr->trik.b_y = 0;
	ptr->trik.c_x = 1000;
	ptr->trik.c_y = 1000;
}

int 	ft_perevirka_trik_plus(t_struct *ptr)
{
	if (ptr->trik.c_x + 1000 > 10E8)
		return (0);
	return (1);
}

int 	ft_perevirka_trik_negative(t_struct *ptr)
{
	if (ptr->trik.c_x - ptr->trik.a_x < 250)
		return (0);
	return (1);
}

void	ft_trik_init(t_struct *ptr, int it, int tmp)
{
	ptr->trik.x = (ptr->trik.a_x + ptr->trik.b_x) / 2;
	ptr->trik.y = (ptr->trik.a_y + ptr->trik.b_y) / 2;
	while (it++ < ptr->depth)
	{
		tmp = random_me(10, 1);
		if (tmp > 0 && tmp < 4)
		{
			ptr->trik.x = (ptr->trik.x + ptr->trik.a_x) / 2;
			ptr->trik.y = (ptr->trik.y + ptr->trik.a_y) / 2;
			ft_pixel_color_fern(ptr, ptr->trik.x, ptr->trik.y, 225, 0);
		}
		else if (tmp > 3 && tmp < 7)
		{
			ptr->trik.x = (ptr->trik.x + ptr->trik.b_x) / 2;
			ptr->trik.y = (ptr->trik.y + ptr->trik.b_y) / 2;
			ft_pixel_color_fern(ptr, ptr->trik.x, ptr->trik.y, 225, 0);
		}
		else if (tmp > 6 && tmp < 10)
		{
			ptr->trik.x = (ptr->trik.x + ptr->trik.c_x) / 2;
			ptr->trik.y = (ptr->trik.y + ptr->trik.c_y) / 2;
			ft_pixel_color_fern(ptr, ptr->trik.x, ptr->trik.y, 225, 0);
		}
	}
}


void	ft_trik(t_struct *ptr)
{
	ft_bzero(ptr->mlx_addr, W * H * 4);
	ft_trik_init(ptr, 0, 0);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->mlx_img, 0, 0);
}