/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik  <nidzik@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:56:31 by nidzik            #+#    #+#             */
/*   Updated: 2015/04/02 09:23:43 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#ifndef FDF_H

# define FDF_H

# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <stdlib.h>
# define LINE_COLOR 0xccff00
# define WIN_H		900
# define WIN_W		1200
# define SPACE		115

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	**map;
	int		**mapi;
	char	*filename;
	float	factor;
	int		max;
	int		min;
	int		red[11];
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

typedef struct	s_ctx
{
	int			x;
	int			y;
	int			i;
	int			j;
	t_3d		*p;
	t_3d		**tabp;
}				t_ctx;

/* void	stock_map(char *str); */
int		ft_color(t_env e, t_3d p0, t_3d p1, int iteration);
void	ft_min_max(t_env *e);
void	ft_printf_line(t_ctx ctx, t_env e);
void	ft_stock_mapi(t_ctx ctx);
int     ft_getnbr(char *str);
void    ft_char_to_int(t_env e, char *str, int i);
void    ft_draw_line(t_3d p0, t_3d p1, t_env *e, int color);
t_3d	ft_create_3d_point_from_2d(t_2d pdx, int z);
t_3d	*ft_create3d(int x, int y, int z);
void	ft_print2d(t_2d p, unsigned int color, t_env *e);
t_2d	ft_transform2d(t_3d p, t_env e);
t_2d	*ft_create2d(int x, int y);
int     ft_count_columns(char *str);
int     ft_count_columns_int(int *str);
int		ft_count_rows(char *name);
void    draw(t_env e);
int     expose_hook(t_env *e);
t_env	ft_main(t_env *e, char *file);
int     get_next_line(int const fd, char **line);
static int	ft_read(int fd, char **tmp);
void    ft_add_line(char **line, char **tmp, long len);
int     ft_strpos(const char *str, char c);
static char		*ft_get_join(char *s1, char *s2);
static void		ft_truc(char **line, char **tmp, int *ret);


#endif
