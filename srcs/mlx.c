/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:26:08 by aledru            #+#    #+#             */
/*   Updated: 2018/01/10 19:57:41 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	display_menu(t_fdf *fdf)
{
	t_img	*img;

	int width = 300;
	img = create_img(mlx_new_image(fdf->mlx, width, WIN_HEIGHT),
			0x262626, width, WIN_HEIGHT);
	mlx_put_image_to_window(fdf->mlx, fdf->win, img->img_ptr, 0, 0);
	mlx_string_put(fdf->mlx, fdf->win, 80, 10, 0xFFFFFF, "FDF Controls");
	mlx_string_put(fdf->mlx, fdf->win, 10, 60, 0xFFFFFF,
			"Translation: ^ v < >");
	mlx_string_put(fdf->mlx, fdf->win, 10, 90, 0xFFFFFF,
			"Zoom: MOUSE UP or MOUSE DOWN");
	mlx_string_put(fdf->mlx, fdf->win, 10, 120, 0xFFFFFF, "Exit: ESC");
}

void		create_window(t_fdf *fdf, char *file_name)
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
	fdf->img = create_img(mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT),
			0x212121, WIN_WIDTH, WIN_HEIGHT);
	mlx_key_hook(win, mlx_key, fdf);
	mlx_hook(win, 2, 0, mlx_translate, fdf);
	mlx_mouse_hook(win, mlx_zoom, fdf);
	set_points(fdf);
	draw_points(fdf, create_point(0, 0));
	display_menu(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img_ptr, 300, 0);
	mlx_loop(mlx);
}
