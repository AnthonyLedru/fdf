/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:48:57 by aledru            #+#    #+#             */
/*   Updated: 2018/01/04 15:24:07 by aledru           ###   ########.fr       */
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
	gradient->color = begin;
	gradient->step = (float)1 / (float)nb_pixel;
	gradient->mix = gradient->step;
	return (gradient);
}
