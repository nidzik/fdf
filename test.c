#include "lib.h"

int		main()
{
	void		*mlx;
	void		*win;
	int		width;
	int		length;

	width = 800;
	length = 800;
	mlx = mlx_init();
	win = mlx_new_window(mlx, width, length, "lul");
	line(mlx, win, width, length);
	sleep(5);
	return (0);
}

void		line(void *mlx, void *win, int width, int length)
{
	int		x;
	int		y;

	x = width;
	y = length;
	width = width - (x / 10);
	while (width >= (x / 10))
	{
		length = y - (y / 10);
		while (length != (y / 10))
		{
			mlx_pixel_put(mlx, win, width, length, 0x0000FF);
			length--;
		}
		width = width - (x / 10);	
	}
	length = y;
	width = x;
	length = length - (y / 10);
	while (length >= (y / 10))
	{
		width = x - (x / 10);
		while (width != (x / 10))
		{
			mlx_pixel_put(mlx, win, width, length, 0x0000FF);
			width--;
		}
		length = length - (y / 10);	
	}
}
