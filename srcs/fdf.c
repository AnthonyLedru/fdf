/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:17:49 by aledru            #+#    #+#             */
/*   Updated: 2017/12/16 17:20:15 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*get_spaces(t_fdf *fdf)
{
	int		max_x;
	int		max_y;
	t_line	*line;

	max_x = 0;
	max_y = 0;
	line = fdf->line;
	free(fdf->spaces);
	while (line)
	{
		if (max_x < line->size)
			max_x = line->size;
		max_y = line->num;
		line = line->next;
	}
	if (max_x > max_y)
		max_x = (WIN_WIDTH / max_x) / 2;
	else
		max_x = (WIN_WIDTH / max_y) / 2;
	max_y = max_x / 2;
	return (create_point(max_x, max_y));
}

t_fdf		*create_fdf(t_line *line)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf));
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->img = NULL;
	fdf->line = line;
	fdf->spaces = create_point(0, 0);
	return (fdf);
}
