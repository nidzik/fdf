/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebijuu <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 22:54:54 by lebijuu           #+#    #+#             */
/*   Updated: 2015/02/14 04:09:18 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2d		*ft_create2d(int x, int y)
{
	t_2d	*p;

	p = malloc(sizeof(t_2d *));
	if (p)
	{
		p->x = x;
		p->y = y;
	}
	return (p);
}

t_2d ft_transform2d(t_3d p)
{
	t_2d	np;
	float	factor;

	factor = 0.16;
	np.x = (p.x * factor * 3) - (p.y * factor * 3) - (p.z / (16 * factor))
					 + (WIN_H / 2);
	np.y = (p.x * factor * 2) + (p.y * factor * 2) - (p.z * (16 * factor)) 
					- ((WIN_H * factor) - (1000 * factor));
	return (np);
}

t_2d	ft_3d_to_2d(t_3d p)
{
	t_2d pp;

	pp = ft_transform2d(p);
	return (pp);
}

void ft_print2d(t_2d p, unsigned int color, t_env *e)
{
	if (p.x > 0 && p.x < e->width && p.y > 0 && e->height)
		mlx_pixel_put(e->mlx, e->win, p.x, p.y, color);
}
