/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbichero <bbichero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 12:08:16 by bbichero          #+#    #+#             */
/*   Updated: 2015/04/10 18:23:29 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw(t_env *e, t_ctx *ctx)
{
	ft_min_max(e);
    ctx->i = 1;
    ctx->j = 1;
    ctx->y = 50;
    ctx->x = 200;
    e->space = (WIN_H - 200) / (10 + ft_count_rows(e->filename));
    e->count = e->space;
    ctx->tabp = (t_3d **)malloc(sizeof(t_3d *) * ft_count_rows(e->filename) + 1);
	while (e->mapi[1][0] >= ctx->i && ctx->x < e->width - 50)
	{
		ft_draw_loop(*e, ctx);
		ctx->i += 1;
		ctx->j = 1;
		ctx->y = 50;
		ctx->x += e->space;
	}
	ctx->tabp[ft_count_rows(e->filename)] = NULL;
	ft_printf_line(*ctx, *e);
	free (ctx->tabp);
}

int			key_hook(int keycode, t_env *e, t_ctx *ctx)
{
	printf("key : %d\n", keycode);
//	if (keycode == 65307)
	if (keycode == 53)
		exit(0);
//	if (keycode == 65362 || keycode == 65364)
	if (keycode == 126 || keycode == 125)
		ft_test(e, keycode, ctx);
//	if (keycode == 119)
	if (keycode == 12)
	{
		e->factor += 0.01;
		mlx_clear_window(e->mlx, e->win);
		draw(e, ctx);
	}
//	if (keycode == 113)
	if (keycode == 13)
	{
		e->factor -= 0.01;
		mlx_clear_window(e->mlx, e->win);
		draw(e, ctx);
	}
	return (0);
}

int			expose_hook(t_env *e,t_ctx ctx)
{
	draw(e, &ctx);
	return (0);
}

int			ft_test(t_env *e, int keycode, t_ctx *ctx)
{
	int		y;
	int		i;

	i = 1;
	while (e->mapi[i] != NULL)
	{
		y = 1;
		while (y <= e->mapi[i][0])
		{
			if (e->mapi[i][y] != 0)
			{
				if (keycode == 125)
			//	if (keycode == 65362)
					e->mapi[i][y]++;
				if (keycode == 126)
			//	if (keycode == 65362)
					e->mapi[i][y]--;
			}
			y++;
		}
		i++;
	}
	mlx_clear_window(e->mlx, e->win);
	draw(e, ctx);
	return (0);
}

int			main(int ac, char **av)
{
	t_env	e;
	t_ctx	ctx;

	if (ft_argv(ac, av, e) == 0)
		return (0);
	e.filename = av[1];
	e.factor = 0.2;
	ft_init_ftmain(&e);
	printf("%#08x \n",e.palette[254]);
	e = ft_main(&e, av[1]);
	ft_palette(&e,av);
	e.width = 1200;
	e.height = 900;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.width, e.height, "42");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
