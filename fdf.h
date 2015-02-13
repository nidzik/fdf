/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik  <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:56:31 by nidzik            #+#    #+#             */
/*   Updated: 2015/02/13 12:24:02 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include "libft/libft.h"

# define LINE_COLOR 0xccff00
# define WIN_H		1200
# define WIN_W		1900
# define INTERVAL	30

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	**map;
}				t_env;
typedef struct s_win
{
	int			w;
	int			h;
}				t_win;

/* void	stock_map(char *str); */
int     ft_count_columns(char **elts);
int		ft_count_rows(char *name);
void    draw(t_env e);
int     expose_hook(t_env *e);
t_env	ft_main(t_env *e);
int     get_next_line(int const fd, char **line);
void	ft_read(int const *fd, char **line, char **tmp, long *ret);
void    ft_add_line(char **line, char **tmp, long len);
int     ft_strpos(const char *str, char c);

#endif
