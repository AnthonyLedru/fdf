/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 13:49:20 by aledru            #+#    #+#             */
/*   Updated: 2018/01/10 17:52:14 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	*get_color(t_fdf *fdf, int n)
{
	t_palette	*palette;

	palette = fdf->palette;
	if (n <= 0)
		if (palette->c1)
			return (create_color(palette->c1->decimal));
	if (n >= 10 && n < 100)
		if (palette->c2)
			return (create_color(palette->c2->decimal));
	if (n >= 100 && n < 200)
		if (palette->c3)
			return (create_color(palette->c3->decimal));
	if (n >= 200 && n < 300)
		if (palette->c4)
			return (create_color(palette->c4->decimal));
	if (n >= 300)
		if (palette->c5)
			return (create_color(palette->c5->decimal));
	return (create_color(0xFFFFFF));
}

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
