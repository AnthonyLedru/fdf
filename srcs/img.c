/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:27:32 by aledru            #+#    #+#             */
/*   Updated: 2018/01/10 19:56:52 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_img(t_img *img, int color, int width, int height)
{
	int i;

	i = 0;
	while (i < height * width)
	{
		img->data[i] = color;
		i++;
	}
}

t_img	*create_img(void *img, int color, int width, int height)
{
	t_img *s_img;

	if (!(s_img = (t_img*)ft_memalloc(sizeof(t_img))))
		malloc_error();
	s_img->img_ptr = img;
	s_img->data = (int *)mlx_get_data_addr(s_img->img_ptr, &s_img->bpp,
			&s_img->size_line, &s_img->endian);
	fill_img(s_img, color, width, height);
	return (s_img);
}
