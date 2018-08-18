#include "fractol.h"

int		exit_x(t_struct *ptr)
{
	mlx_destroy_window(ptr->mlx_ptr, ptr->mlx_win);
	ptr = NULL;
	exit(0);
	return (0);
}

void	usage_help(void)
{
	ft_putstr("\n  usage: ./fractol fractol_name\n");
	ft_putstr("__________________________________\n");
	ft_putstr("  1: mandelbrot\n");
	ft_putstr("  2: julia\n");
	ft_putstr("  3: fern\n");
	ft_putstr("  4: trik\n");
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		usage_help();
	else if (argc > 2)
	{
		ft_putstr("\n  too many argument\n");
		usage_help();
	}
	else if (argc == 2)
		ft_fractol(argv[1]);
	return (0);
}