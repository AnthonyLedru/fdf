/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:20:26 by aledru            #+#    #+#             */
/*   Updated: 2018/01/10 14:30:39 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_segment	*create_segment(int dx, int dy, int sx, int sy)
{
	t_segment	*segment;

	if (!(segment = (t_segment*)ft_memalloc(sizeof(t_segment))))
		malloc_error();
	segment->d = create_point(dx, dy);
	segment->s = create_point(sx, sy);
	return (segment);
}

void		free_segment(t_segment *segment)
{
	(void)segment;
	ft_memdel((void**)&segment->d);
	ft_memdel((void**)&segment->s);
	ft_memdel((void**)&segment);
}
