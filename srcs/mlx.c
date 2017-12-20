/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:26:08 by aledru            #+#    #+#             */
/*   Updated: 2017/12/20 18:41:22 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_window(t_fdf *fdf, char *file_name)
{
	void	*mlx;
	void	*win;
	char	**file_name_split;

	if (NULL == (mlx = mlx_init()))
		exit(EXIT_FAILURE);
	file_name_split = ft_strsplit(file_name, '/');
	while (*file_name_split)
		file_name_split++;
	file_name_split--;
	if (NULL == (win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT,
		*file_name_split)))
		exit(EXIT_FAILURE);
	fdf->mlx = mlx;
	fdf->win = win;
	fdf->img = create_img(mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT));
	fdf->img->data = (int *)mlx_get_data_addr(fdf->img->img_ptr, &fdf->img->bpp,
						&fdf->img->size_line, &fdf->img->endian);
	mlx_key_hook(win, mlx_escape, fdf);
	set_points_setup(fdf);
	draw_points(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img_ptr, 0, 0);
	mlx_mouse_hook(win, mlx_zoom, fdf);
	mlx_loop(mlx);
}
