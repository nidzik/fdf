/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:52:27 by nidzik            #+#    #+#             */
/*   Updated: 2015/04/12 15:00:32 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_count_rows(char *name)
{
	char		**ret;
	int		res;
	int		f;

	res = 0;
	ret = ft_memalloc(sizeof(char **) * 2);
	f = open(name, O_RDONLY, 0644);
	while (get_next_line(f, ret) > 0)
		res++;
	free(ret);
	close(f);
	return (res);
}

int			ft_count_columns(char *str)
{
	int		c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

int			ft_count_columns_int(int *str)
{
	int		c;

	c = 1;
	while (c <= str[0] + 1)
		c++;
	return (c);
}

t_env			ft_main_suite(t_env *e, int fd, int i, char **line)
{
	/* line = (char **)malloc(sizeof(char *) * ft_count_rows(e->filename) */
			/* + 1); */
	while (get_next_line (fd, line) > 0)
	{
		e->map[i] = (char *)malloc(sizeof(char) *
								   ((ft_strlen(*line) / 2)+10));
		e->map[i] = *line;
		ft_char_to_int(*e, *line, i);
		i++;
	}
	printf("cc%dcc", e->mapi[i-2][9]);
	e->mapi[i] = NULL;
	e->map[i] = NULL;
	i = 1;
	free(line);
	close(fd);
	ft_min_max(e);
	return (*e);
}
