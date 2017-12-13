/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:08:22 by aledru            #+#    #+#             */
/*   Updated: 2017/12/13 16:51:51 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

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
	struct s_line_points **points;
	int					size;
	int					num;
	struct s_line		*next;
}				t_line;

/*
** -------------------------------- Reader -------------------------------------
*/

void			check_valid_file(int fd);

/*
** --------------------------------- Line --------------------------------------
*/

t_line			*create_line(t_line_points **points, int num, int size);
t_line_points	*create_line_points(int height, int color);

#endif
