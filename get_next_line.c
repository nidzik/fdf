/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 09:35:43 by nidzik            #+#    #+#             */
/*   Updated: 2015/04/12 13:11:56 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		*ft_get_join(char *s1, char *s2)
{
	char		*dst;

	if (s1 == NULL)
	{
		s1 = ft_strnew(1);
		ft_bzero(s1, sizeof(s1));
		s1 = "";
	}
	if (!s1 || !s2)
		return ((char *)0);
	dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return ((char *)0);
	ft_strcpy(dst, s1);
	ft_strcat(dst, s2);
	return (dst);
}

int		ft_read(int fd, char **tmp)
{
	int			ret;
	char		buf[BUF_SIZE + 1];

	if (*tmp != NULL && ft_strchr(*tmp, '\n'))
		return (1);
	ft_bzero(buf, sizeof(buf));
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		*tmp = ft_get_join(*tmp, buf);
		if (*tmp == NULL)
			return (-1);
		if (ft_strchr(*tmp, '\n') != NULL)
			break ;
		ft_bzero(buf, sizeof(buf));
	}
	return (ret <= 0 ? ret : 1);
}

void		ft_truc(char **line, char **tmp, int *ret)
{
	char		*ptr;

	if (*tmp != NULL && ft_strlen(*tmp) > 0)
	{
		*ret = 1;
		ptr = ft_strchr(*tmp, '\n');
		if (ptr == NULL)
		{
			*line = *tmp;
			*tmp = NULL;
		}
		else
		{
			*line = *tmp;
			*ptr = '\0';
			*tmp = ft_strdup(ptr + 1);
		}
	}
	return ;
}

int			get_next_line(const int fd, char **line)
{
	int		ret;
	static char	*current = NULL;

	if (line == NULL)
		return (-1);
	*line = NULL;
	ret = ft_read(fd, &current);
	if (ret < 0)
		return (-1);
	ft_truc(line, &current, &ret);
	return (ret);
}

t_env			ft_main(t_env *e, char *file)
{
	int		i;
	int		fd;
	char		**line;

	ft_count_rows(file);
	i = 1;
	fd = open(file, O_RDONLY);
	e = ft_error_gnl(e, fd);
	line = (char **)malloc(sizeof(char *) * ft_count_rows(e->filename) + 1);
	if (fd > 1)
		*e = ft_main_suite(e, fd, i, line);
	return (*e);
}
