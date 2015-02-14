/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebijuu <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 15:09:44 by lebijuu           #+#    #+#             */
/*   Updated: 2015/02/14 16:19:36 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
void		ft_draw_line(t_2d p0, t_2d p1, t_env *e, int color)
{
	t_line	l;
	double	iterations;
	int		i;
	
	
	l.dx = p1.x - p0.x;
	l.dy = p1.y - p0.y;	
	l.size = sqrt(l.dx * l.dx + l.dy * l.dy);		
	iterations = ceil(l.size);	
	i = (int)iterations;
	mlx_pixel_put(e->mlx, e->win, p0.x, p0.y, color);
	l.dx /= iterations;
	l.dy /= iterations;

	while (i--)
	{
		p0.x += l.dx;
		p0.y += l.dy;
		mlx_pixel_put(e->mlx, e->win, p0.x, p0.y, color);
	}
}
