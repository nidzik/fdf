/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebijuu <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 15:48:44 by lebijuu           #+#    #+#             */
/*   Updated: 2015/03/20 10:25:52 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_char_to_int(t_env e, char *str, int i)
{
	int		cpt;
	int getnb;

	getnb = 0;
	cpt = 0;
	e.mapi[i] = (int *)malloc(sizeof(int) * ft_strlen(str));
	while (*str)
	{
		if (*str == ' ')
			str++;
		else
		{
			getnb = ft_getnbr(str);
			/* if (getnb == 10) */
				/* ft_putstr("yolo"); */
			e.mapi[i][cpt] = getnb;
			if (getnb >= 10)
				str++;
		printf("!!! %d !!!\n", e.mapi[i][cpt]);
		cpt++;
		str++;
		}
	}
		/* e.mapi[i][cpt] = '\n'; */
		/* cpt++; */
	e.mapi[i][cpt] = '\n';
	e.mapi[i][cpt + 1] = 127;
		/* cpt = 0; */
		/* while (e.mapi[i][cpt]) */
			/* printf("-> %d ", e.mapi[i][cpt++]); */
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
	{
		sign = -1;
		str++;
	}
	while (((*str > 47) && (*str < 58)))
	{
		printf("coucou");fflush(stdout);
		res = (res * 10) + *str - 48;
		str++;
	}
	res = res * sign;
	ft_putnbr(res);
	return (res );
}
