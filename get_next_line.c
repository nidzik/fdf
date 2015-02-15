/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 10:17:08 by nidzik            #+#    #+#             */
/*   Updated: 2015/02/15 16:31:01 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft/libft.h"
#include "fdf.h"

int		ft_strpos(const char *str, char c)
{
  char *cpstr;
  int i;

  i = 0;
  cpstr = (char *)str;
  while (*cpstr != '\0') 
    {
      if (*cpstr == c)
	return (i);
      cpstr++;
      i++;
    }
  return (i);
}

void		ft_add_line(char **line, char **tmp, long len)
{
  char		*thistmp;
  long		leni;

  if (line == NULL)
    //line = (char **)malloc(sizeof(char **));
    line = (char **)ft_memalloc(sizeof(char **));
  leni = ft_strlen(*line);
  *line = (char *)ft_realloc(*line, leni, leni + len + 1);

 if (*line)
    {
 
      (*line)[leni + len] = '\0';
 
      ft_strncat (*line, *tmp, len);
      thistmp = ft_strnew(BUF_SIZE * sizeof(char *));

      if (thistmp)
	{
	  ft_strncat(thistmp, (*tmp) + len + 1, BUF_SIZE - len - 1);
	  free(*tmp);
	  *tmp = thistmp;
      
	}
    }
}

void ft_read(int const *fd, char **line, char **tmp, long *ret)
{
  int stop;

  stop = 0;
  if (*tmp == NULL)
    {
      *tmp = ft_strnew(BUF_SIZE * sizeof(char *));
      *ret = read(*fd, *tmp, BUF_SIZE);
      //printf("%s**",*tmp);
    }  
  *line = ft_strnew(BUF_SIZE * sizeof(char *));
  
  while (*line != NULL && *ret == BUF_SIZE && !stop)
    {

      if (ft_strchr(*tmp, '\n') != 0)
	{
	  //printf("-coucouif trouv /n-\n\n");fflush(stdout);	  
	  ft_add_line(line, tmp, ft_strpos(*tmp, '\n'));
	  stop = 1;
	  // printf("-coucou-  tmp : %s-       line : %s \n\n", *tmp, *line);fflush(stdout);
  //exit(0);
	}
      else
	{
	  //printf("-coucouelse pas trouv tmp = %s-\n\n",*tmp);fflush(stdout);	  
	  ft_add_line(line, tmp, BUF_SIZE);
	  *ret = read(*fd, *tmp, BUF_SIZE);
	  
	}
    }
}


int		get_next_line(int const fd, char **line)
{
  long ret;
  static char *current;

  if (fd < 0 || line == NULL)
    return (-1);

  ret = BUF_SIZE;
  (void)ft_read(&fd, line, &current, &ret);

  if (ret != BUF_SIZE && ret > 0)
    ft_add_line (line, &current, ret - 1);
  if (ret <= 0)
    {
      free(*line);
      free(current);
      current = NULL;
      return (ret);
    }
  return (1);
}

t_env ft_main(t_env *e)
{
  int	fd;
  char	** line;
  int i;
  e.mapi = malloc
  ft_count_rows("test");
  i = 0;
  fd = open("test", O_RDONLY);
  e->map = malloc(100);
			printf("%d\n",i);fflush(stdout);
  if ( fd > 1 )
    {
      line = (char **) malloc(2);
      while (get_next_line (fd, line) > 0)
    {

			e->map[i] = *line;
//			printf("%d\n",i);fflush(stdout);
			printf("%s--\n",e->map[i]);fflush(stdout);
			i++;
    }
	  e->map[i] = NULL;
    free (line);
    close(fd);
}
return (*e);
}
