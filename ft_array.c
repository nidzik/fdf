/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebijuu <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 15:48:44 by lebijuu           #+#    #+#             */
/*   Updated: 2015/02/16 13:21:41 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_char_to_int(t_env e, char *str, int i)
{
	int		cpt;

	cpt = 0;
	e.mapi[i] = (int *)malloc(sizeof(int) * ft_strlen(str));
	while (*str)
	{
		if (*str == ' ')
			str++;
		else
			e.mapi[i][cpt++] = ft_getnbr(str);
		ft_putnbr(e.mapi[i][cpt - 1]);
	}
	e.mapi[i][cpt] = '\0'
}

int			ft_getnbr(char *str)
{
	int sign;
	int res;

	res = 0;
	sign = 1;
	if (str == NULL)
		return (0);
	if (*str == '-')
		sign = -1;
	while ((*str > 47) && (*str < 58))
	{
		res = (res * 10) + *str - '0';
		str++;
	}
	res = res * sign;
	return (res);
}
