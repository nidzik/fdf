/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 09:35:43 by nidzik            #+#    #+#             */
/*   Updated: 2015/03/22 16:46:59 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char *ft_get_join(char *s1, char *s2)
{
	char    *dst;
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
	/* 	free(s1); */

	ft_strcat(dst, s2);
	return (dst);
}

static int		ft_read(int fd, char **tmp)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	if (*tmp != NULL && ft_strchr(*tmp, '\n'))
		return (1);
	ft_bzero(buf, sizeof(buf));
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		*tmp = ft_get_join(*tmp, buf);

		/* 		*tmp = ft_strjoin(*tmp == NULL ? "" : *tmp, buf); */
		//	printf("     (%s)\n", *tmp);
		if (*tmp == NULL) //verif malloc
			return (-1);
		if (ft_strchr(*tmp, '\n') != NULL)
			break ;
		ft_bzero(buf, sizeof(buf));
	}
	return (ret <= 0 ? ret : 1);
}

static void	ft_truc(char **line, char **tmp, int *ret) //line est vide, //tmp contient mes trucs
{
	char	*ptr;

	//	printf("[%s]\n", *tmp);
	if (*tmp != NULL && ft_strlen(*tmp) > 0)
	{
		//		printf("salut\n");
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
	int			ret;
	static char	*current = NULL;

	if (line == NULL)
		return (-1);
	*line = NULL; //a enlever
	/* 	ret = BUF_SIZE; */
	ret = ft_read(fd, &current);/* line, &current, &ret); */
	/* 	ft_putendl(*line); */
	if (ret < 0)
		return (-1);
	ft_truc(line, &current, &ret);
	/* 	if (ret != BUF_SIZE && ret > 0) */
	/* 		ft_add_line (line, &current, ret - 1); */
	/* 	if (ret <= 0) */
	/* 	{ */
	/* 		ft_add_line (line, &current, ret - 1); */
	/* 		ft_putendl(*line); */
	/* 		free(*line); */
	/* 		line = NULL; */
	/* 		free(current); */
	/* 		current = NULL; */
	return (ret);
	/* 	} */
	/* 	return (1); */
}

t_env ft_main(t_env *e, char *file)
{
	int	fd;
	char	** line;
	int i;
	int y;

	y = 0;
	ft_count_rows(file);
	i = 0;
	fd = open(file, O_RDONLY);
	e->map = malloc(100);
	printf("%d\n",i);fflush(stdout);
	e->mapi = (int **)malloc(sizeof(int *) * 100);
	if ( fd > 1 )
	{
		line = (char **) malloc(2);
		while (get_next_line (fd, line) > 0)
		{
			/* if (y == 0) */
			/* { */
			/* 	e->mapi = (int **)malloc(sizeof(int *) * ft_count_columns(*line)); */
			/* 	y++; */
			/* } */
			e->map[i] = *line;
			ft_char_to_int(*e, *line, i);
			printf("--%s--\n",e->map[i]);fflush(stdout);
			i++;
		}
		e->mapi[i + 1] = NULL;
		e->map[i] = NULL;
		i = 0;
		free (line);
		close(fd);
	}
	//printf("->%d",e->mapi[0][0]);fflush(stdout);
	//printf("->%d",e->mapi[0][1]);fflush(stdout);
	//printf("->%d",e->mapi[1][0]);fflush(stdout);
	while (e->mapi[i] != NULL)
	{
		y = 0;
		while (e->mapi[i][y] != '\n' || e->mapi[i][y+1] != 127)
		{
			printf("-----%d------",e->mapi[i][y]);fflush(stdout);
			y++;
		}
		ft_putchar('\n');
		i++;
	}
	return (*e);
}
