
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebijuu <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 16:53:59 by lebijuu           #+#    #+#             */
/*   Updated: 2015/04/11 15:03:53 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_init_ftmain(t_env *e)
{
	e->map = (char **)malloc(sizeof(char *) * ft_count_rows(e->filename) + 1);
	e->mapi = (int **)malloc(sizeof(int *) * ft_count_rows(e->filename) + 1);
}

void ft_draw_loop(t_env e, t_ctx *ctx)
{
	while (ft_count_rows(e.filename) != ctx->j)
	{
		if (e.space == e.count)
		{
			e.count = 0;
			if (ctx->i <= e.mapi[1][0])
			{
				if (ctx->i == 1)
					ctx->tabp[ctx->j] = (t_3d *)malloc(sizeof(t_3d) *
							ft_count_columns_int(e.mapi[1]));
				ctx->p = ft_create3d(ctx->x, ctx->y, e.mapi[ctx->j][ctx->i]);
				ft_stock_mapi(*ctx);
			}
			ctx->j++;
		}
		e.count = e.count + e.space;
		ctx->y += e.space;
	}
}

t_env			ft_argv(int agc, char **agv, t_env e)
{
	if (agc == 1)
	{
		ft_putstr("Too few arguments, please make sure to use ./fdf");
		ft_putendl(" [~/Path/maps] R[255] G[100] B[0]");
		e.error = 1;
	}
	else if (agc == 2)
		ft_palette(&e);
	else if (agc == 5)
	{
		e.r = ft_atoi(agv[2]);
		e.g = ft_atoi(agv[3]);
		e.b = ft_atoi(agv[4]);
		if (e.r > 255 || e.g > 255 || e.b > 255 || e.r < 0 || e.g < 0 || e.b < 0)
		{
			ft_putstr("Too few arguments, please make sure to use a Value");
			ft_putendl("Between 0 and 255, thanks !");
			e.error = 1;
		}
		else
			ft_palette(&e);
	}
	else
		e.error = 1;
	
	return (e);
}

t_env		*ft_palette(t_env *e)
{
	int		i;

	printf("%d %d %d\n",e->r, e->g, e->b);
	i = 254;
	if (e->w == 5)
		e->palette[255] = (e->r * 65536) + (e->g * 256) + e->b;
	else
		i = 255;
	if (e->w == 2)
		while (i != 0)
			e->palette[i--] = 0xFFFFFF;
	else
	{
		while (i != 0)
		{
			e->palette[i] = e->palette[i + 1];
			if ((e->r -= 1) > 0)
				e->palette[i] = e->palette[i] - 0x010000;
			if ((e->g -= 1) > 0)
				e->palette[i] = e->palette[i] - 0x000100;
			if ((e->b -= 1) > 0)
				e->palette[i] = e->palette[i] - 0x000001;
			if (e->r <= 0 && e->g <= 0 && e->b <= 0)
				e->palette[i] = 0x000000;
			i--;
		}
	}
	return (e);
}
