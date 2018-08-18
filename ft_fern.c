#include "fractol.h"

void	ft_fern_asigned(t_struct *ptr)
{
	ptr->x_move = 0;
	ptr->y_move = 0;
	ptr->radius = 0.057;
	ptr->depth = 500000;
}

// void	ft_fern_help(t_struct *ptr)
// {
	
// }

void	ft_fern_init(t_struct *ptr)
{
	double t, x, y;
	int p;
	long k;
	int mid_x, mid_y, radius;

	mid_x = W / 2 ;
	mid_y = H - 100;
	radius = trunc(ptr->radius * mid_y);
	x = 1.0;
	y = 1.0;
	k = 1;
	while (k++ < ptr->depth)
	{
		p = random() % 100;
		t = x;
		if (p <= 85 && p > 1)
		{
			x = 0.84  * x - 0.045 * y;
			y = 0.045 * t + 0.86 * y + 2.6;
		}
		else if (p <= 92 && p > 85)
		{
			x = 0.20 * x - 0.26 * y;
			y = 0.23 * t + 0.25   * y + 2.6;
		}
		else if (p <= 99 && p > 92)
		{
			x = -0.135 * x + 0.28 * y;
			y = 0.26 * t + 0.245 * y + 1.44;
		}
		else
		{
			x = 0.0;
			y = 0.16 * y;
		}
		ft_pixel_color_fern(ptr, mid_x + round(radius * x) + ptr->x_move,
			mid_y-round(radius*y)+35 + ptr->y_move, 225, 0);
	}
}

void	ft_fern(t_struct *ptr)
{
	ft_bzero(ptr->mlx_addr, W * H * 4);
	ft_fern_init(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->mlx_img, 0, 0);
}