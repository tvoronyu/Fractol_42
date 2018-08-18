#include "fractol.h"

static	void	*ft_comand_threads(void *pot)
{
	t_threads	*potok;
	int			y;
	int			y_max;

	potok = (t_threads*)pot;
	y = (H / N) * potok->n;
	y_max = H / N * (potok->n + 1);
	if (potok->ptr->id == 0)
		ft_mandelbrot_init(potok->ptr, 0, y, y_max);
	else if (potok->ptr->id == 1)
		ft_julia_init(potok->ptr, 0, y, y_max);
	
	pthread_exit(0);
}

void			ft_threads(t_struct *ptr)
{
	t_threads		potok[N];
	int				i;
	int				n;

	n = -26;
	i = -1;
	while (++i < N)
	{
		++n;
		potok[i].ptr = ptr;
		potok[i].n = n;
		pthread_create(&potok[i].threads, NULL, ft_comand_threads, &potok[i]);
	}
	i = -1;
	while (++i < N)
		pthread_join(potok[i].threads, NULL);
	
}