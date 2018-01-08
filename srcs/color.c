/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 13:49:20 by aledru            #+#    #+#             */
/*   Updated: 2018/01/08 17:15:08 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	*create_color(int decimal)
{
	t_color	*color;

	if (!(color = (t_color*)ft_memalloc(sizeof(t_color))))
		malloc_error();
	color->decimal = decimal;
	color->r = (decimal >> 16) & 0xff;
	color->g = (decimal >> 8) & 0xff;
	color->b = decimal & 0xff;
	return (color);
}

int		rgb_to_decimal(t_color *color)
{
	color->decimal = (color->r << 16) + (color->g << 8) + (color->b);
	return (color->decimal);
}
