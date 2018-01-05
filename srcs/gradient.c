/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:48:57 by aledru            #+#    #+#             */
/*   Updated: 2018/01/05 17:02:20 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_gradient	*create_gradient(t_color *begin, t_color *end, int nb_pixel)
{
	t_gradient *gradient;

	gradient = (t_gradient*)ft_memalloc(sizeof(t_gradient));
	gradient->begin = begin;
	gradient->end = end;
	gradient->nb_pixel = nb_pixel;
	gradient->color = create_color(begin->decimal);
	gradient->step = 1.0 / (float)nb_pixel;
	gradient->mix = gradient->step;
	return (gradient);
}
