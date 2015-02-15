/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik  <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:32:57 by nidzik            #+#    #+#             */
/*   Updated: 2015/02/15 15:01:04 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
#include "fdf.h"
//#include <unistd.h>
//#include "libft/libft.h"
/* void	stock_map(char *str, t_env e) */
/* { */
	
/* } */

void	draw(t_env e)
{
	/* double		xp; */
	/* double		yp; */
	int x;
	int y;
	int		i;
	int		j;
	double count;
	t_3d	*p;
	t_2d	p1;
	t_2d	p0;

	i = 0;
	j = 0;
	/* yp = (WIN_W - 200) / ft_count_columns(e.map); */
	/* xp = (WIN_H - 200) / ft_count_rows("test"); */
	/* printf("\n%f  %f  %f\n",yp,xp); */
	y = 100;
	x = 100;
	
	count = 0;
	p0 = *ft_create2d(300,400);
	p1 = *ft_create2d(500,600);
	ft_draw_line(p0,p1, &e, 0xffff00);
	printf("col : %d    line : %d\n",ft_count_columns(e.map),ft_count_rows("test"));fflush(stdout);
	while (x < e.width - 100)
	{
		while (y < e.height - 100)
		{
			if (SPACE == count) //(y % SPACE == 0&& 
			{
				count = 0;
				if (e.map[j][i] == '1' && e.map[j][i])
				{
					p = ft_create3d(x, y, 10);
					ft_print2d(ft_transform2d(*p),0xccff00, &e);
				}
				else if (e.map[j][i] && e.map[j][i] == '2')
				{
					ft_draw_line(ft_transform2d(*ft_create3d(x, y, 10)),   ft_transform2d(*ft_create3d(x, y, 20)), &e,0xff0000);
					ft_print2d(ft_transform2d(*ft_create3d(x,y, 10)),0xff0000, &e);
					p = ft_create3d(x, y, 20);
					ft_print2d(ft_transform2d(*p),0xff0000, &e);
				}
				j++;
			}
			count = count + 1;
			y+=1;
		}
		i+=2;
		j = 0;
		y = 100;
		x+=SPACE;
	}
}

/* void draw(void *mlx, void *win) */
/* { */
	
/* } */

/* int		expose_hook(t_env *e) */
/* { */
/* 	draw(*e); */
/* 	return (0); */
//}

int		main(void)
{
	t_env e;

	e = ft_main(&e);
	//printf("%s:3", e.map[0]);fflush(stdout);
	e.width = 1200;
	e.height = 900;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.width, e.height, "42");
	
	draw(e);
	sleep(5);
//	mlx_expose_hook(e.win, expose_hook, &e);
//	mlx_loop(e.mlx);
	return (0);
}
