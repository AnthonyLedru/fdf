/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:27:32 by aledru            #+#    #+#             */
/*   Updated: 2018/01/08 12:32:25 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img	*create_img(void *img)
{
	t_img *s_img;

	if (!(s_img = (t_img*)ft_memalloc(sizeof(t_img))))
		malloc_error();
	s_img->img_ptr = img;
	s_img->data = (int *)mlx_get_data_addr(s_img->img_ptr, &s_img->bpp,
			&s_img->size_line, &s_img->endian);
	return (s_img);
}
