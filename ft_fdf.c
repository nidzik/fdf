/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik  <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:32:57 by nidzik            #+#    #+#             */
/*   Updated: 2015/02/17 23:07:27 by lebijuu          ###   ########.fr       */
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
	double count;
	t_ctx	ctx;
	int space;
	ctx.i = 0;
	ctx.j = 0;
	/* yp = (WIN_W - 200) / ft_count_columns(e.map); */
	/* xp = (WIN_H - 200) / ft_count_rows("test"); */
	/* printf("\n%f  %f  %f\n",yp,xp); */
	ctx.y = 50;
	ctx.x = 50;
	space = (WIN_H - 200 ) / ft_count_rows("test"); 
	count = 0;
	printf("col : %d    line : %d\n",ft_count_columns_int(e.mapi[0]),ft_count_rows("test"));fflush(stdout);
    ctx.tabp=(t_3d **)malloc(sizeof(t_3d *) * ft_count_rows("test"));

	while (ctx.x < e.width - 50 && ft_count_columns_int(e.mapi[0]) != ctx.i)
	{

		while (ctx.y < e.height - 50 && (ft_count_rows("test") ) != ctx.j)
		{

			if (space == count ) //([ctx.y] % SPACE == 0&& 
			{
				/* printf("\n\n space : %d ctx.i : %d ctx.j : %d ctx.x : %d ctx.y : %d\n\n\n",space, ctx.i, ctx.j, ctx.x, ctx.y);fflush(stdout); */
				count = 0;
				if (e.mapi[ctx.j][ctx.i])
				{
					if (ctx.i == 0)
						ctx.tabp[ctx.j] = (t_3d *)malloc(sizeof(t_3d)*100);// ft_count_columns_int(e.mapi[0]));

					ctx.p = ft_create3d(ctx.x, ctx.y, e.mapi[ctx.j][ctx.i]);
					printf("%d-",e.mapi[ctx.j][ctx.i] );fflush(stdout);
					ft_print2d(ft_transform2d(*ctx.p),0xff0000, &e);
					//ft_print2d(ft_transform2d(*ctx.p),0x0000ff, &e);
					ft_stock_mapi(ctx, e);
				}

				/* else if (e.map[ctx.j][ctx.i] && e.map[ctx.j][ctx.i] == '2') */
				/* { */
				/* 	ft_draw_line(ft_transform2d(*ft_create3d(ctx.x, ctx.y, 10)),   ft_transform2d(*ft_create3d(ctx.x, ctx.y, 20)), &e,0xff0000); */
				/* 	ft_print2d(ft_transform2d(*ft_create3d(ctx.x,ctx.y, 10)),0xff0000, &e); */
				/* 	ctx.p = ft_create3d(ctx.x, ctx.y, 20); */
				/* 	ft_print2d(ft_transform2d(*ctx.p),0xff0000, &e); */
				/* } */
				ctx.j++;
			}
			count = count + 1;
			ctx.y+=1;
		}
		ctx.i+=1;
		ctx.j = 0;
		ctx.y = 50;
		ctx.x+=space;

	}
	ctx.tabp[ft_count_rows("test")] = NULL;
	ft_printf_line(ctx, e);
	/* free (ctx.tabp); */
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
