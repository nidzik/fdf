/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebijuu <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 02:10:53 by lebijuu           #+#    #+#             */
/*   Updated: 2015/04/09 11:57:01 by bbichero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3d		*ft_create3d(int x, int y, int z)
{
	t_3d	*p;

	p = malloc(sizeof(t_2d *));
	p->x = x;
	p->y = y;
	p->z = z;
	return (p);
}

t_3d		ft_create_3d_point_from_2d(t_2d pdx, int z)
{
	t_3d	p;

	p.x = pdx.x;
	p.y = pdx.y;
	p.z = z;
	return (p);
}
