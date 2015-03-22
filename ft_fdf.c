/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik  <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:32:57 by nidzik            #+#    #+#             */
/*   Updated: 2015/03/22 18:22:09 by lebijuu          ###   ########.fr       */
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
	ctx.x = 200;
	space = (WIN_H - 200 ) / ft_count_rows(e.filename); 
	count = space;
	printf("col : %d    line : %d\n",ft_count_columns_int(e.mapi[0]),ft_count_rows(e.filename));fflush(stdout);
    ctx.tabp=(t_3d **)malloc(sizeof(t_3d *) * ft_count_rows(e.filename));

	while (ctx.x < e.width - 50 && ft_count_columns_int(e.mapi[0]) != ctx.i)
	{

		while (/*ctx.y < e.height - 50 &&*/ (ft_count_rows(e.filename) ) != ctx.j)
		{

			if (space == count ) //([ctx.y] % SPACE == 0&& 
			{
				/* printf("\n\n space : %d ctx.i : %d ctx.j : %d ctx.x : %d ctx.y : %d   z : %d\n\n\n",space, ctx.i, ctx.j, ctx.x, ctx.y, e.mapi[ctx.i][ctx.j]);fflush(stdout); */
				count = 0;
				if (e.mapi[ctx.j][ctx.i] != '\n' || e.mapi[ctx.j][ctx.i + 1] != 127)
				{
					if (ctx.i == 0)
						ctx.tabp[ctx.j] = (t_3d *)malloc(sizeof(t_3d)*100);// ft_count_columns_int(e.mapi[0]));

					ctx.p = ft_create3d(ctx.x, ctx.y, e.mapi[ctx.j][ctx.i]);
					/* printf("%d-",e.mapi[ctx.j][ctx.i] );fflush(stdout); */
					ft_print2d(ft_transform2d(*ctx.p, e),0xff0000, &e);
					//ft_print2d(ft_transform2d(*ctx.p),0x0000ff, &e);
					ft_stock_mapi(ctx, e);
				}
				ctx.j++;
			}
			count = count + space;
			ctx.y+=space;
		}
		ctx.i+=1;
		ctx.j = 0;
		ctx.y = 50;
		ctx.x+=space;

	}
	ctx.tabp[ft_count_rows(e.filename)] = NULL;
	ft_printf_line(ctx, e);
	/* free (ctx.tabp); */
}

/* void draw(void *mlx, void *win) */
/* { */
	
/* } */

int key_hook(int keycode, t_env *e)
{
	printf("key : %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	if (keycode == 65362 || keycode == 65364)
		ft_test(e, keycode);
	if (keycode == 65450)
	{
		e->factor+=0.01;
		mlx_clear_window(e->mlx, e->win);
		draw(*e);
	}
	if (keycode == 65453)
	{
		e->factor-=0.01;
		mlx_clear_window(e->mlx, e->win);
		draw(*e);
	}
	if (keycode)
	return (0);
/*
 *fleche haut : 65362
 *fleche bas : 65364
 */
}

 int		expose_hook(t_env *e)
{
	draw(*e);

	return (0);
}

int ft_test(t_env *e, int keycode)
{
	int y;
	int i;

	i = 0;
	y = 0;
    while (e->mapi[i] != NULL)
    {
        y = 0;
        while (e->mapi[i][y] != '\n' || e->mapi[i][y+1] != 127)
        {
			if (e->mapi[i][y] != 0)
			{
				if (keycode == 65362)
					e->mapi[i][y]++;
				if (keycode == 65364)
					e->mapi[i][y]--;
			}
            y++;
        }
		i++;
	}
		mlx_clear_window(e->mlx, e->win);
		draw(*e);
}

int		main(int ac, char **av)
{
	t_env e;
	(void)ac;
	e.filename = av[1];
	e.factor = 0.2;
	e = ft_main(&e, av[1]);
	//printf("%s:3", e.map[0]);fflush(stdout);
	e.width = 1200;
	e.height = 900;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.width, e.height, "42");
	
	//draw(e);
	/* sleep(5); */
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
