/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:08:22 by aledru            #+#    #+#             */
/*   Updated: 2017/12/21 14:53:38 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <mlx.h>
# include "../libft/includes/libft.h"
# define WIN_HEIGHT 1300
# define WIN_WIDTH 2350

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

/*
** -------------------------------- Reader -------------------------------------
*/

t_fdf			*check_valid_file(int fd);

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

int				mlx_escape(int keycode, void *param);
int				mlx_zoom(int button, int x, int y, void *param);

/*
** ---------------------------------- FDF --------------------------------------
*/

t_point			*get_spaces(t_fdf *fdf);
t_fdf			*create_fdf(t_line *line);
int				get_number_of_line(t_fdf *fdf);
int				get_max_line_size(t_fdf *fdf);

/*
** ---------------------------------- Draw -------------------------------------
*/

void			draw_points(t_fdf *fdf);

/*
** ----------------------------------- Img -------------------------------------
*/

t_img			*create_img(void *img);
#endif
