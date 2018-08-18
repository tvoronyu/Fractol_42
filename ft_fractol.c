#include "fractol.h"

double 	random_me(int n, int it)
{
	int p;

	if (n < 11)
	{
		p = random() % 10;
		if (p < n && p > 0)
			return (p);
	}
	else if ( n > 10)
		{
			p = random() % 100;
			if (p < n && p > 0)
				return (p);
		}
	random_me(n, it);
	return (2);
}

int		ft_name_check(char *name)
{
	if (ft_strcmp("mandelbrot", name) == 0 || ft_strcmp("1", name) == 0)
		return (0);
	else if (ft_strcmp("julia", name) == 0 || ft_strcmp("2", name) == 0)
		return (1);
	else if (ft_strcmp("fern", name) == 0 || ft_strcmp("3", name) == 0)
		return (2);
	else if (ft_strcmp("trik", name) == 0 || ft_strcmp("4", name) == 0)
		return (4);
	usage_help();
	exit(1);
}

void	ft_fractol(char *name)
{
	t_struct ptr[1];

	ptr->id = ft_name_check(name);
	ft_mlx_init(ptr);
}