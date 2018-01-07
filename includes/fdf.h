/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:08:22 by aledru            #+#    #+#             */
/*   Updated: 2018/01/07 23:30:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <mlx.h>
# include "../libft/includes/libft.h"
# define WIN_HEIGHT		1300
# define WIN_WIDTH		2350

/*
** -------------------------------- Struct -------------------------------------
*/

typedef	struct	s_line_values
{
	int	height;
	int	color;
}				t_line_values;

typedef struct	s_line
{
	struct s_line_values	**values;
	struct s_point			**points;
	int						size;
	int						num;
	struct s_line			*next;
}				t_line;

typedef struct	s_img
{
	void	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;
	int		*data;
}				t_img;

typedef struct	s_fdf
{
	void					*mlx;
	void					*win;
	struct s_img			*img;
	struct s_point			*spaces;
	struct s_line			*line;
	struct s_point			*translation;
	struct s_palette		*palette;
}				t_fdf;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef	struct	s_segment
{
	struct s_point	*d;
	struct s_point	*s;
}				t_segment;

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
	int	decimal;
}				t_color;

typedef	struct	s_gradient
{
	struct s_color	*begin;
	struct s_color	*end;
	struct s_color	*color;
	int				nb_pixel;
	float			step;
	float			mix;
}				t_gradient;

typedef	struct	s_palette
{
	struct s_color	*c1;
	struct s_color	*c2;
	struct s_color	*c3;
	struct s_color	*c4;
	struct s_color	*c5;
}				t_palette;

/*
** -------------------------------- Parser -------------------------------------
*/

t_fdf			*check_valid_file(int fd, int ac, char **av);

/*
** --------------------------------- Line --------------------------------------
*/

t_line			*create_line(t_line_values **values, int num, int size);
t_line_values	*create_line_values(int height, int color);

/*
** -------------------------------- Point --------------------------------------
*/
t_point			*create_point(int x, int y);
void			set_point(t_point **point, int x, int y);
void			set_points_setup(t_fdf *fdf);
void			translate_points(t_fdf *fdf);

/*
** -------------------------------- Segment ------------------------------------
*/
t_segment		*create_segment(int dx, int dy, int sx, int sy);

/*
** --------------------------------- MLX ---------------------------------------
*/

void			create_window(t_fdf *fdf, char *file_name);

/*
** --------------------------------- Event -------------------------------------
*/

int				mlx_key(int keycode, void *param);
int				mlx_zoom(int button, int x, int y, void *param);
int				mlx_translate(int keycode, void *param);

/*
** ---------------------------------- FDF --------------------------------------
*/

t_fdf			*create_fdf(t_line *line, int ac, char **av);
int				get_max_line_size(t_fdf *fdf);

/*
** ---------------------------------- Draw -------------------------------------
*/

void			draw_points(t_fdf *fdf);

/*
** ----------------------------------- Img -------------------------------------
*/

t_img			*create_img(void *img);

/*
** ------------------------------ Color Gradient -------------------------------
*/

t_gradient		*create_gradient(t_color *begin, t_color *end, int nb_pixel);

/*
** ---------------------------------- Color ------------------------------------
*/

t_color			*create_color(int decimal);
int				rgb_to_decimal(t_color *color);

/*
** --------------------------------- Palette -----------------------------------
*/

t_palette		*create_palette(int ac, char **av);

/*
** ---------------------------------- Error ------------------------------------
*/

void			malloc_error();
#endif
