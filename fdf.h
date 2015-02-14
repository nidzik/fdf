/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik  <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:56:31 by nidzik            #+#    #+#             */
/*   Updated: 2015/02/14 17:56:16 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdlib.h>
# define LINE_COLOR 0xccff00
# define WIN_H		900
# define WIN_W		1200
# define SPACE		116

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

typedef struct	s_2d
{
	int			x;
	int			y;
}				t_2d;

typedef	struct	s_3d
{
	int			x;
	int			y;
	int			z;
}				t_3d;

typedef struct	s_line
{
	double		dx;
	double		dy;
	double		size;
}				t_line;

/* void	stock_map(char *str); */
void      ft_draw_line(t_2d p0, t_2d p1, t_env *e, int color);
t_3d	ft_create_3d_point_from_2d(t_2d pdx, int z);
t_3d	*ft_create3d(int x, int y, int z);
void	ft_print2d(t_2d p, unsigned int color, t_env *e);
t_2d	ft_transform2d(t_3d p);
t_2d	*ft_create2d(int x, int y);
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
