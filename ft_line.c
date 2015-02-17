/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebijuu <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 15:09:44 by lebijuu           #+#    #+#             */
/*   Updated: 2015/02/17 11:42:49 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
void		ft_draw_line(t_2d p0, t_2d p1, t_env *e, int color)
{
	t_line	l;
	double	iterations;
	int		i;
	double a;
	double b;
	
	l.dx = p1.x - p0.x;
	l.dy = p1.y - p0.y;	
	l.size = sqrt(l.dx * l.dx + l.dy * l.dy);		
	iterations = ceil(l.size);	
	i = (int)iterations;
	//printf("\n%f    %d %d    %d\n",iterations,p0.x,p1.x,i);
	mlx_pixel_put(e->mlx, e->win, p0.x, p0.y, color);
	l.dx /= iterations;
	l.dy /= iterations;
	a = p0.x;
	b = p0.y;
	while (i--)
	{
		
		a = a + l.dx;
		b += l.dy;
		//printf("%d   %d    %f \n",p0.x,p0.y,l.dx);
		mlx_pixel_put(e->mlx, e->win, (int)a, b, color);
	}
}

void		ft_stock_mapi(t_ctx ctx, t_env e)
{
	//if (ctx.i == 0 && ctx.j == 0)
	//ctx.tabp=(t_3d **)malloc(sizeof(t_3d *) * ft_count_rows("test"));
	//if (ctx.j == 0)
	//ctx.tabp[ctx.j] = (t_3d *)malloc(sizeof(t_3d) * ft_count_columns_int(e.mapi[0]));
	ctx.tabp[ctx.j][ctx.i] = *ctx.p;
//	ctx.tabp[ctx.j + 1] = NULL;
	
	printf(" %d %d %d %d %d %d\n", ctx.j, ctx.i, ctx.tabp[ctx.j][ctx.i].x, ctx.tabp[ctx.j][ctx.i].y, ctx.tabp[ctx.j][ctx.i].z, ft_count_columns_int(e.mapi[0]));fflush(stdout);

}


void		ft_printf_line(t_ctx ctx, t_env e)
{
	int i; 
	int j;
	int stop;

	i = 0;
	j = 0;
	stop = ctx.i;
	while (ctx.tabp[j])
	{

		while (i + 1 != stop )
		{
		if (ctx.tabp[j + 1])
ft_draw_line(ft_transform2d(ctx.tabp[j][i]), ft_transform2d(ctx.tabp[j + 1][i]), &e, 0xff0000);

			printf(" %d %d %d %d %d %d\n", j, i, ctx.tabp[j][i].x, ctx.tabp[j][i].y, ctx.tabp[j][i].z, ft_count_columns_int(e.mapi[0]));fflush(stdout);			
			ft_draw_line(ft_transform2d(ctx.tabp[j][i]), ft_transform2d(ctx.tabp[j][i + 1]), &e, 0xff0000);
			i++;

		}
		if (ctx.tabp[j + 1])
ft_draw_line(ft_transform2d(ctx.tabp[j][i]), ft_transform2d(ctx.tabp[j + 1][i]), &e, 0xff0000);
		j++;
		i = 0;
	}
	/* ft_putchar('q'); */
	/* i = 0; */
	/* j = 0; */
	/* stop = ctx.j; */
	/* while (ctx.tabp[i]) */
	/* { */
	/* 	/\* ft_draw_line(ft_transform2d(ctx.tabp[j][i]), ft_transform2d(ctx.tabp[j][i + 1]), &e, 0xff0000); *\/ */
	/* 	while (j + 1 != stop) */
	/* 	{ */
	/* 		ft_draw_line(ft_transform2d(ctx.tabp[j][i]), ft_transform2d(ctx.tabp[j][i + 1]), &e, 0xff0000); */
	/* 		j++; */
	
	/* 	} */
	/* 	i++; */
	/* 	j = 0; */
	/* } */

}
