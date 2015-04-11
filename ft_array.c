/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebijuu <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 15:48:44 by lebijuu           #+#    #+#             */
/*   Updated: 2015/04/10 09:25:31 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_len(char *str)
{
	int		len;
	int		i;
	int		l;

	l = 0;
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == ' ' && l == 1)
			l = 0;
		if (str[i] != ' ' && l == 0)
		{
			len++;
			l = 1;
		}
		i++;
	}
	return (len);
}

void		ft_char_to_int(t_env e, char *str, int i)
{
	int		cpt;
	int		getnb;

	getnb = 0;
	cpt = 1;
	e.mapi[i] = (int *)malloc(sizeof(int) * ft_strlen(str));
	e.mapi[i][0] = ft_len(str);
	while (*str)
	{
		if (*str == ' ')
			str++;
		else
		{
			getnb = ft_getnbr(str);
			e.mapi[i][cpt] = getnb;
			if (getnb >= 10)
				str++;
			else if (getnb < 0 && getnb > -10)
				str++;
			else if (getnb <= -10)
				str += 2;
			cpt++;
			str++;
		}
	}
}

int			ft_getnbr(char *str)
{
	int		sign;
	int		res;

	res = 0;
	sign = 1;
	if (str == NULL)
		return (0);
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (((*str > 47) && (*str < 58)))
	{
		res = (res * 10) + *str - 48;
		str++;
	}
	res = res * sign;
	return (res);
}

void		ft_min_max(t_env *e)
{
	int		i;
	int		j;

	i = 1;
	e->max = e->mapi[1][1];
	e->min = e->mapi[1][1];
	while (e->mapi[i] != NULL)
	{
		j = 1;
		while (j <= e->mapi[i][0])
		{
			if (e->mapi[i][j] > e->max)
				e->max = e->mapi[i][j];
			if (e->mapi[i][j] < e->min)
				e->min = e->mapi[i][j];
			j++;
		}
		i++;
	}
}
