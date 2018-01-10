/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:48:57 by aledru            #+#    #+#             */
/*   Updated: 2018/01/10 16:13:27 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_gradient	*create_gradient(t_color *beg, t_color *end, t_point *a, t_point *b)
{
	t_gradient	*gradient;
	t_point		*a_cp;
	t_point		*b_cp;

	if (!(gradient = (t_gradient*)ft_memalloc(sizeof(t_gradient))))
		malloc_error();
	gradient->begin = beg;
	gradient->end = end;
	a_cp = copy_point(a);
	b_cp = copy_point(b);
	gradient->nb_pixel = get_nb_pixel(a_cp, b_cp);
	ft_memdel((void**)&a_cp);
	ft_memdel((void**)&b_cp);
	gradient->color = create_color(beg->decimal);
	gradient->step = 1.0 / (float)gradient->nb_pixel;
	gradient->mix = gradient->step;
	return (gradient);
}

void		free_gradient(t_gradient *gradient)
{
	ft_memdel((void**)&gradient->begin);
	ft_memdel((void**)&gradient->end);
	ft_memdel((void**)&gradient->color);
	ft_memdel((void**)&gradient);
}
