/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:52:27 by nidzik            #+#    #+#             */
/*   Updated: 2015/02/15 15:36:06 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_count_rows(char *name)
{
	char	**ret;
	int		res;
	int		f;

	res = 0;
	ret = ft_memalloc (sizeof(char **) * 2);
	f = open(name, O_RDONLY, 0644);
	while (get_next_line (f, ret) > 0)
		res++;
	free (ret);
	close(f);
	return (res);
}

int			ft_count_columns(char **elts)
{
	int		c;

	c = 0;
	while (elts[c] != NULL)
	{
		c++;
	}
	return (c);
}


