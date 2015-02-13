/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik  <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:32:57 by nidzik            #+#    #+#             */
/*   Updated: 2015/02/13 13:02:44 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <unistd.h>

/* void	stock_map(char *str, t_env e) */
/* { */
	
/* } */

void	draw(t_env e)
{
	double		x;
	double		y;
	int		i;
	int		j;
	double space;
	/* t_env	e; */
	/* e.width = 1024; */
	/* e.height = 720; */
	i = 0;
	j = 0;
	y = (e.width - 200) / ft_count_columns(e.map);
	x = (e.height - 200) / ft_count_rows("test");
	space = y < x ? y : x;
	y = 100;
	x = 100;
	printf("yy%dyy",ft_count_rows("test"));fflush(stdout);
	while (x < e.width - 100)
	{
		/* if (x % 100 == 0) //|| y % 100 == 0) */
			/* mlx_pixel_put(mlx, win, x, y, 0xCCFF00); */
		while (y < e.height - 100)
		{
			if (y / space == 0) //|| y % 100 == 0)
			{
				if (e.map[j][i] == '1' && e.map[j][i])
					mlx_pixel_put(e.mlx, e.win, x, y, 0xCCFF00);
				else
					mlx_pixel_put(e.mlx, e.win, x, y, 0xff0000);
				ft_putnbr(j);
				j++;
			}
			

			y+=1;
		}
		ft_putnbr(i);
		ft_putchar(' ');
		i++;
		j = 0;
		y = 100;
		x+=space;
//		if (x % 100 == 0)
//			sleep(1);
	}
}

/* void draw(void *mlx, void *win) */
/* { */
	
/* } */

int		expose_hook(t_env *e)
{
	draw(*e);
	return (0);
}

int		main(void)
{
	t_env e;

	e = ft_main(&e);
	printf("%s:3", e.map[0]);fflush(stdout);
	e.width = 1024;
	e.height = 720;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.width, e.height, "42");
	
	draw(e);
//	sleep(5);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
