/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:18:49 by aledru            #+#    #+#             */
/*   Updated: 2018/01/09 17:06:18 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mlx_key(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		mlx_translate(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (keycode == 123)
		fdf->translation->x -= 10;
	if (keycode == 124)
		fdf->translation->x += 10;
	if (keycode == 125)
		fdf->translation->y += 10;
	if (keycode == 126)
		fdf->translation->y -= 10;
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
	{
		free_all_points(fdf);
		mlx_destroy_image(fdf->mlx, fdf->img->img_ptr);
		free(fdf->img);
		fdf->img = create_img(mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT));
		set_points_setup(fdf);
		draw_points(fdf, create_point(0, 0));
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img_ptr, 0, 0);
	}
	return (0);
}

int		mlx_zoom(int button, int x, int y, void *param)
{
	t_fdf		*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf*)param;
	if (button == 4 || button == 5)
	{
		mlx_destroy_image(fdf->mlx, fdf->img->img_ptr);
		free(fdf->img);
		fdf->img = create_img(mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT));
		if (button == 4)
			set_point(fdf->spaces, fdf->spaces->x + 1, fdf->spaces->x / 2);
		if (fdf->spaces->x > 10)
		{
			if (button == 5)
				set_point(fdf->spaces, fdf->spaces->x - 1, fdf->spaces->x / 2);
		}
		set_points_setup(fdf);
		draw_points(fdf, create_point(0, 0));
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img_ptr, 0, 0);
	}
	return (0);
}
