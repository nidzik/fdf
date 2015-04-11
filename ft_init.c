
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebijuu <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 16:53:59 by lebijuu           #+#    #+#             */
/*   Updated: 2015/04/11 11:26:16 by lebijuu          ###   ########.fr       */
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
				//	ft_print2d(ft_transform2d(*ctx->p, e), 0xff0000, &e);
				ft_stock_mapi(*ctx);
			}
			ctx->j++;
		}
		e.count = e.count + e.space;
		ctx->y += e.space;
	}
}

int			ft_argv(int agc, char **agv, t_env e)
{
	e.w = agc;
	if (agc == 1)
	{
		ft_putstr("Too few arguments, please make sure to use ./fdf");
		ft_putendl("[~/Path/maps] R[255] G[100] B[0]");
		return (0);
	}
//	else if (agc == 2)
//		ft_palette(&e);
	else if (agc == 5)
	{
		e.r = ft_atoi(agv[2]);
		e.g = ft_atoi(agv[3]);
		e.b = ft_atoi(agv[4]);
//		ft_palette(&e);
	}
	else
		return (0);
	return (1);
}

t_env		*ft_palette(t_env *e, char **av)
{
	int		i;
	int		rr;
	int		vv;
	int		bb;

	rr = atoi(av[2]);
	vv = atoi(av[3]);
	bb = atoi(av[4]);
	i = 254;
	e->palette[255] = (atoi(av[2]) * 65536) + (atoi(av[3]) * 256) + (atoi(av[4]));
	/* printf("%#08x   , %d   %d    %d  \n\n\n",e->palette[255],rr, vv, bb); */

	 if (e->w == 2)
		 while (i != 0)
			e->palette[i--] = 0xFFFFFF;
	else
	{
		while (i != 0)
		{
			/* printf("%#08x\n",e->palette[i + 1]); */
			e->palette[i] = e->palette[i + 1];
			if ((rr -= 1) > 0)
			{
				e->palette[i] = e->palette[i] - 0x010000;
				ft_putstr("r");
			}
			if ((vv -= 1) > 0)
			{
				e->palette[i] = e->palette[i] - 0x000100;
				ft_putchar('g');
			}
			if ((bb -= 1) > 0)
			{
				e->palette[i] = e->palette[i] - 0x000001;
				ft_putchar('b');
			}
			if (rr <= 0 && vv <= 0 && bb <= 0)
				e->palette[i] = 0x000000;
			/* printf("%#08x\n\n",e->palette[i]); */
			i--;
		}
	}
	return (e);
}
