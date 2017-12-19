/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:19:25 by aledru            #+#    #+#             */
/*   Updated: 2017/12/15 18:34:47 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			*create_point(int x, int y)
{
	t_point	*point;

	point = (t_point*)ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

void			set_point(t_point **point, int x, int y)
{
	(*point)->x = x;
	(*point)->y = y;
}
