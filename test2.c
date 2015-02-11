/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbichero <bbichero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 10:07:12 by bbichero          #+#    #+#             */
/*   Updated: 2015/02/11 12:55:16 by bbichero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

void		line(void *mlx, void *win, int width, int length);
void		line2(void *mlx, void *win, float x1, float y1, float x2, float y2);

int			main()
{
	void		*mlx;
	void		*win;
	int			width;
	int			length;

	width = 800;
	length = 800;
	mlx = mlx_init();
	win = mlx_new_window(mlx, width, length, "lul");
	//line(mlx, win, width, length);
	line2(mlx, win, 400, 109, 500, 250);
	sleep(10);
	return (0);
}

void		line(void *mlx, void *win, int width, int length)
{
	int			x;
	int			y;

	x = width;
	y = length;
	width = width - (x / 10);
	while (width >= (x / 10))
	{
		length = y - (y / 10);
		while (length != (y / 10))
		{
			mlx_pixel_put(mlx, win, width, length, 0xFFFFFF);
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
			mlx_pixel_put(mlx, win, width, length, 0xFFFFFF);
			width--;
		}
		length = length - (y / 10);	
	}
}

void		line2(void *mlx, void *win, float x1, float y1, float x2, float y2)
{
	//int		yd;

	//yd = ((y2 - y1) / 100);
	while ((x1 <= x2) || (x1 >= x2)) 
	{
		while ((y1 <= y2) || (y1 >= y2))
		{
			if (y1 == y2 && x1 < x2)
				mlx_pixel_put(mlx, win, x1++, y1, 0xFF00000);
			else if (x1 == x2 && y1 < y2)
				mlx_pixel_put(mlx, win, x1, y1++, 0xFF00000);
			if (y1 == y2 && x1 > x2)
				mlx_pixel_put(mlx, win, x1--, y1, 0xFF00000);
			else if (x1 == x2 && y1 > y2)
				mlx_pixel_put(mlx, win, x1, y1++, 0xFF00000);
			else if (x1 > x2 && y1 > y2)
				mlx_pixel_put(mlx, win, x1--, y1--, 0xFF00000);
			else if (x1 < x2 && y1 < y2)
				mlx_pixel_put(mlx, win, x1++, y1 = y1 + 1.41, 0xFF00000);
			else if (x1 > x2 && y1 < y2)
				mlx_pixel_put(mlx, win, x1--, y1++, 0xFF00000);
			else if (x1 < x2 && y1 > y2)
				mlx_pixel_put(mlx, win, x1++, y1--, 0xFF00000);
			else if (x1 == x2 && y1 == y2)
			{
				sleep(10);
				exit(1);
			}
		}
	}
}
