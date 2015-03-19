/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:52:27 by nidzik            #+#    #+#             */
/*   Updated: 2015/03/19 17:08:39 by lebijuu          ###   ########.fr       */
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

int			ft_count_columns(char *str)
{
	int		c;

	c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}

int         ft_count_columns_int(int *str)
{
    int     c;

    c = 0;
	printf("**%d", 5656565);fflush(stdout);
    while (( str[c] != '\n'))// && str[c] != '\n')
    {
        c++;
    }
    return (c);
}
