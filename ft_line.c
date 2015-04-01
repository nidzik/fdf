/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebijuu <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 15:09:44 by lebijuu           #+#    #+#             */
/*   Updated: 2015/03/27 12:26:01 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_draw_line(t_2d p0, t_2d p1, t_env *e, int color)
{
	t_line		l;
	double		iterations;
	int		i;
	double		a;
	double		b;

	l.dx = p1.x - p0.x;
	l.dy = p1.y - p0.y;
	l.size = sqrt(l.dx * l.dx + l.dy * l.dy);
	iterations = ceil(l.size);
	i = (int)iterations;
	mlx_pixel_put(e->mlx, e->win, p0.x, p0.y, color);
	l.dx /= iterations;
	l.dy /= iterations;
	a = p0.x;
	b = p0.y;
	while (i--)
	{
		a = a + l.dx;
		b += l.dy;
		mlx_pixel_put(e->mlx, e->win, (int)a, b, color);
	}
}

void		ft_stock_mapi(t_ctx ctx)
{
	ctx.tabp[ctx.j][ctx.i] = *ctx.p;
}

void		ft_printf_line(t_ctx ctx, t_env e)
{
	int	i; 
	int	j;
	int	stop;
	int	color;

	color = 0xffffff;
	i = 1;
	j = 1;
	stop = ctx.i;
	while (ctx.tabp[j])
	{
		while (i != (stop - 1))
		{
			if (ctx.tabp[j + 1])
			{
				if (ctx.tabp[j][i].z > 8 || ctx.tabp[j + 1][i].z > 8)
					color = 0xffffff;
				else 
					color = 0xff0000;
				ft_draw_line(ft_transform2d(ctx.tabp[j][i], e), ft_transform2d(ctx.tabp[j + 1][i], e), &e, color);
			}
			if (ctx.tabp[j][i].z > 8 || ctx.tabp[j][i + 1].z > 8)
				color = 0xffffff;
			else
				color = 0xff0000;
			ft_draw_line(ft_transform2d(ctx.tabp[j][i], e), ft_transform2d(ctx.tabp[j][i + 1], e), &e, color);
			i++;
		}
		if (ctx.tabp[j + 1])
			ft_draw_line(ft_transform2d(ctx.tabp[j][i], e), ft_transform2d(ctx.tabp[j + 1][i], e), &e, color);
		j++;
		i = 1;
	}
}
