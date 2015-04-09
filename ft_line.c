/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebijuu <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 15:09:44 by lebijuu           #+#    #+#             */
/*   Updated: 2015/04/09 09:46:20 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_draw_line(t_3d p2, t_3d p3, t_env *e, int color)
{
	t_line		l;
	double		iterations;
	int		i;
	double		a;
	double		b;
	t_2d p0;
	t_2d p1;
	int ite_max;
	int cpt;
	int nb_pix;
	int z_min;
	double fac;
	int color_min;
	int real_color;
	cpt = 0;
	p0 = ft_transform2d(p2, *e);
	p1 = ft_transform2d(p3, *e);
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
	ite_max = i;
	color = ft_color(*e, p2, p3);
	
	z_min = (p2.z < p3.z) ? p2.z : p3.z;
	/* if (z_min != 0) */
		/* fac = ((double)z_min / (double)abs(e->min)) * 10 ; */
	/* fac = (double)abs(e->min) / (double)abs(z_min); */
	/* else if (z_min == 0) */
	/* fac = ((abs(e->min) + z_min) / ((e->max - e->min)/10)); */
	fac = (((double)abs(z_min) + (double)(e->max) )/ ((double)abs(e->min)  + (double)abs(e->max)))*10 ;
	color_min = (int)fac;
	if (z_min == e->min)// || color_min <= 0 || color_min > 11)
		color_min = 1;
	printf("itemax : %d color min : %d color :%d e->min : %d  zmin:%d",ite_max, color_min , color, e->min, z_min);
	if (color - abs(color_min) != 0)
		nb_pix = (int)ceil((ite_max / (color - abs(color_min))));
	if (z_min == p3.z)
		real_color = color;
	else if (z_min == p2.z)
		real_color = color_min;
	while (i--)
	{
	e->red[0] = 11;
	e->red[1] = 0xFFFFFF;
	/* e->red[1] = 0xE5A500; */
	e->red[2] = 0xE49600;
	e->red[3] = 0xE48701;
	e->red[4] = 0xE37801;
	e->red[5] = 0xE36902;
	e->red[6] = 0xE25B03;
	e->red[7] = 0xE24C03;
	e->red[8] = 0xE13D04;
	e->red[9] = 0xE12E04;
	e->red[10] = 0xE01F05;
	e->red[11] = 0xE01106;
	if (z_min == p2.z && cpt == nb_pix && p2.z != p3.z)
	{
		real_color++;
		cpt = 0;
	}
	else if (cpt == nb_pix && p2.z != p3.z && z_min == p3.z)
	{
		real_color--;
		cpt = 0;
	}
	cpt++;
	a = a + l.dx;
	b += l.dy;
	mlx_pixel_put(e->mlx, e->win, (int)a, b, e->red[real_color]);
	}
}

int			ft_color(t_env e, t_3d p0, t_3d p1)
{
	int color;
	int z_max;
	int i;
	double fac;

	i = 0;
	z_max = (p0.z > p1.z) ? p0.z : p1.z;
	/* fac = (    (double) ((double)abs(e.max) + (double)z_max)    /     (double)(    ((double)e.max - (double)e.min)  / 10)     ); */
	fac = (((double)(z_max) - (double)(e.min) )/ ((double)abs(e.max)  + (double)abs(e.min))) * 10 ;
	color = (int)fac;
	printf("    z_max %d   /   e.max %d   = %lf\n", z_max, e.max, fac);
	if (color <= 0 || color > 11)
		return (1);
	/* else if (color < 0) */
		/* return color  */
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
