/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik  <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:32:57 by nidzik            #+#    #+#             */
/*   Updated: 2015/04/07 18:43:17 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw(t_env e)
{
	double	count;
	t_ctx	ctx;
	int	space;

	ft_min_max(&e);
	ctx.i = 1;
	ctx.j = 1;
	ctx.y = 50;
	ctx.x = 200;
	space = (WIN_H - 200 ) / (10 + ft_count_rows(e.filename)); 
	count = space;
	ctx.tabp = (t_3d **)malloc(sizeof(t_3d *) * ft_count_rows(e.filename) + 1);
	while (e.mapi[1][0] >= ctx.i && ctx.x < e.width - 50)
	{
		while (ft_count_rows(e.filename) != ctx.j)
		{
			if (space == count) 
			{
				count = 0;
				if (ctx.i <= e.mapi[1][0])
				{
					if (ctx.i == 1)
						ctx.tabp[ctx.j] = (t_3d *)malloc(sizeof(t_3d) * ft_count_columns_int(e.mapi[1]));
					ctx.p = ft_create3d(ctx.x, ctx.y, e.mapi[ctx.j][ctx.i]);
					ft_print2d(ft_transform2d(*ctx.p, e),0xff0000, &e);
					ft_stock_mapi(ctx);
				}
				ctx.j++;
			}
			count = count + space;
			ctx.y+=space;
		}
		ctx.i += 1;
		ctx.j = 1;
		ctx.y = 50;
		ctx.x+=space;
	}
	ctx.tabp[ft_count_rows(e.filename)] = NULL;
	ft_printf_line(ctx, e);
	free (ctx.tabp);
}

int	key_hook(int keycode, t_env *e)
{
	printf("key : %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	if (keycode == 65362 || keycode == 65364)
		ft_test(e, keycode);
	if (keycode == 119)
	{
		e->factor+=0.01;
		mlx_clear_window(e->mlx, e->win);
		draw(*e);
	}
	if (keycode == 113)
	{
		e->factor-=0.01;
		mlx_clear_window(e->mlx, e->win);
		draw(*e);
	}
	return (0);
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

	i = 1;
	while (e->mapi[i] != NULL)
	{
		y = 1;
		while (e->mapi[i][0] >= (y + 1))
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
	return (0);
}

int		main(int ac, char **av)
{
	t_env e;
	(void)ac;
	e.filename = av[1];
	e.factor = 0.3;
	e = ft_main(&e, av[1]);
	e.width = 1200;
	e.height = 900;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.width, e.height, "42");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
