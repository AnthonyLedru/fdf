/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:20:26 by aledru            #+#    #+#             */
/*   Updated: 2017/12/15 18:20:51 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_segment		*create_segment(int dx, int dy, int sx, int sy)
{
	t_segment	*segment;

	segment = (t_segment*)ft_memalloc(sizeof(t_segment));
	segment->d = create_point(dx, dy);
	segment->s = create_point(sx, sy);
	return (segment);
}
