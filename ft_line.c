/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebijuu <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 15:09:44 by lebijuu           #+#    #+#             */
/*   Updated: 2015/04/08 07:25:35 by lebijuu          ###   ########.fr       */
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
	fac = ((double)z_min / (double)e->max) * 10 ;
	color_min = (int)fac;
	printf("%d %d %d ",ite_max, color_min , color);
	if (color - abs(color_min) != 0)
		nb_pix = (int)ceil((ite_max / (color - abs(color_min))));
	/* else */
		/* color = 2; */
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
	if (cpt == nb_pix && p2.z != p3.z)
	{
		color--;
		cpt = 0;
	}
	/* if (color == 0) */
		/* color = 1; */
	cpt++;
	//ft_putnbr(color);
	//ft_putchar('\n');
	a = a + l.dx;
	b += l.dy;
	mlx_pixel_put(e->mlx, e->win, (int)a, b, e->red[color]);
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
	fac = (((double)abs(z_max) + (double)abs(e.min) )/ ((double)abs(e.max)  + (double)abs(e.min))) * 10 ;
	color = (int)fac;
	printf("e.red[0] %d / z_max %d / e.max %d   = %lf\n", e.red[0], z_max, e.max, fac);
	if (color == 0)
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
