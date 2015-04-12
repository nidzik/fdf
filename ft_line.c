/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebijuu <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 15:09:44 by lebijuu           #+#    #+#             */
/*   Updated: 2015/04/12 12:45:01 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_line(t_3d p2, t_3d p3, t_env *e, int color)
{
	t_color	c;
	t_line	l;

	c.p0 = ft_transform2d(p2, *e);
	c.p1 = ft_transform2d(p3, *e);
	l.dx = c.p1.x - c.p0.x;
	l.dy = c.p1.y - c.p0.y;
	l.size = sqrt(l.dx * l.dx + l.dy * l.dy);
	c.iterations = ceil(l.size);
	c.i = (int)c.iterations;
	l.dx /= c.iterations;
	l.dy /= c.iterations;
	c.a = c.p0.x;
	c.b = c.p0.y;
	c.ite_max = c.i;
	color = ft_color(*e, p2, p3);
	c = ft_color_min(e, c, color, p2, p3);
	if (c.pass > 10)
		c.pass = c.real_color / c.ite_max;
	while (c.i--)
	{
		c = ft_degrader(c, e, p2, p3);
		c.a = c.a + l.dx;
		c.b += l.dy;
		mlx_pixel_put(e->mlx, e->win, c.a, c.b, e->palette[c.real_color]);
	}
}

t_color		ft_degrader(t_color c, t_env *e, t_3d p2, t_3d p3)
{
	if (c.color_min == c.real_color)
		c.pass = 0;
	if (c.nb_pix == 0)
		c.cpt++;
	else if (c.z_min == p2.z && c.cpt == c.nb_pix && p2.z != p3.z && (c.real_color + c.pass) <255)
	{
		c.real_color += c.pass;
		c.cpt = 0;
	}
	else if ((c.cpt == c.nb_pix && p2.z != p3.z && c.z_min == p3.z && (c.real_color - c.pass > 0)))
	{
		c.real_color -= c.pass;
		c.cpt = 0;
	}
	c.cpt++;
	return (c);
}

t_color		ft_color_min(t_env *e, t_color c, int color, t_3d p2, t_3d p3)
{
	c.cpt = 0;
	c.z_min = (p2.z < p3.z) ? p2.z : p3.z;
	c.fac = (((double)(c.z_min) + (double)abs(e->min))/ ((double)abs(e->min)
				+ (double)abs(e->max))) * 255;
	c.color_min = (int)c.fac;
	if (c.z_min == e->min)
		c.color_min = 1;
	if (color - abs(c.color_min) != 0 && (255 / c.ite_max <= 1))
	{
		c.nb_pix = (int)((c.ite_max / (color - abs(c.color_min))));
		c.pass = 1;
	}
 	else if (color - abs(c.color_min) != 0 && (255 / c.ite_max >= 1))
	{
		c.nb_pix = 1;
		c.pass = (abs(color - c.color_min) / c.ite_max);
	}
	else
		c.nb_pix = 0;
	if (c.z_min == p3.z)
		c.real_color = color;
	else if (c.z_min == p2.z)
		c.real_color = c.color_min;
	return (c);
}

int		ft_color(t_env e, t_3d p0, t_3d p1)
{
	int	color;
	int	z_max;
	int	i;
	double	fac;

	i = 0;
	z_max = (p0.z > p1.z) ? p0.z : p1.z;
	fac = (((double)(z_max) - (double)(e.min) )/ ((double)abs(e.max)
				+ (double)abs(e.min))) * 255;
	color = (int)fac;
	if (color <= 0 || color > 255)
		return (1);
	return(color);
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
				ft_draw_line(ctx.tabp[j][i], ctx.tabp[j + 1][i], &e, color);
			}
			ft_draw_line(ctx.tabp[j][i], ctx.tabp[j][i + 1], &e, color);
			i++;
		}
		if (ctx.tabp[j + 1])
			ft_draw_line(ctx.tabp[j][i], ctx.tabp[j + 1][i], &e, color);
		j++;
		i = 1;
	}
}
