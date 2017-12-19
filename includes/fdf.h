/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:08:22 by aledru            #+#    #+#             */
/*   Updated: 2017/12/16 17:28:45 by aledru           ###   ########.fr       */
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

typedef	struct	s_line_points
{
	int	height;
	int	color;
}				t_line_points;

typedef struct	s_line
{
	struct s_line_points	**points;
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
	void			*mlx;
	void			*win;
	struct s_img	*img;
	struct s_point	*spaces;
	struct s_line	*line;

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

t_line			*create_line(t_line_points **points, int num, int size);
t_line_points	*create_line_points(int height, int color);

/*
** -------------------------------- Point --------------------------------------
*/
t_point			*create_point(int x, int y);
void			set_point(t_point **point, int x, int y);

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
int				mlx_zoom(int keycode, void *param);

/*
** ---------------------------------- FDF --------------------------------------
*/

t_point			*get_spaces(t_fdf *fdf);
t_fdf			*create_fdf(t_line *line);

/*
** ---------------------------------- Draw -------------------------------------
*/

void			draw_setup(t_fdf *fdf);

/*
** ----------------------------------- Img -------------------------------------
*/

t_img			*create_img(void *img);
#endif
