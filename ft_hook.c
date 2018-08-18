#include "fractol.h"

int		deal_key(int key, t_struct *ptr)
{
	if (key == 53)
		exit(0);
	if (key == 69)
		ft_key_69(ptr);
	else if (key == 78)
		ft_key_78(ptr);
	else if (key == 49)
		ft_enter_fractol(ptr);
	else if (key == 126)
		ft_key_126(ptr);
	else if (key == 125)
		ft_key_125(ptr);
	else if (key == 123)
		ft_key_123(ptr);
	else if (key == 124)
		ft_key_124(ptr);
	else if (key == 1)
		ft_stop_julia(ptr);
	else if (key == 91)
		ft_colors_keys(ptr);
	return (0);
}

int		deal_key_mouse(int key, int x, int y, t_struct *ptr)
{
	x = 0;
	y = 0;
	if (key == 5)
		ft_key_5(ptr);
	else if (key == 4)
		ft_key_4(ptr);
	return (0);
}

int		deal_key_mouse_1(int x, int y, t_struct *ptr)
{
	if (ptr->id == 1)
	{
		if (x > 0 && x < W && y > 0 && y < H && ptr->stop_julia == 1)
			{
				if (ptr->zoom < 5)
				{
					ptr->Re = -0.7469 - (double)x / 1000;
					ptr->Im = -0.1089 - (double)y / 1000;
				}
				else
				{
					ptr->Re = -0.7469 - (double)x / 2000;
					ptr->Im = -0.1089 - (double)y / 2000;
				}
				ft_julia(ptr);
			}
	}
	return (0);
}







