/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:27:32 by aledru            #+#    #+#             */
/*   Updated: 2017/12/20 16:06:27 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img	*create_img(void *img)
{
	t_img *s_img;

	s_img = (t_img*)ft_memalloc(sizeof(t_img));
	s_img->img_ptr = img;
	s_img->bpp = 0;
	s_img->size_line = 0;
	s_img->endian = 0;
	s_img->data = NULL;
	return (s_img);
}
