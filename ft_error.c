/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebijuu <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:21:14 by lebijuu           #+#    #+#             */
/*   Updated: 2015/04/11 13:37:04 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

t_env			*ft_error_gnl(t_env *e, int err)
{
	e->error = 0;
	if (err < 1)
	{
		e->error = 1;
		ft_putendl("Please give me a real map !");
		return (e);
	}
		return (e);
}
