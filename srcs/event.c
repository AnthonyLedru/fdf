/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:18:49 by aledru            #+#    #+#             */
/*   Updated: 2018/01/12 18:39:08 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				mlx_key(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

static void		mlx_translation(int keycode, t_fdf *fdf)
{
	if (keycode == 123)
		fdf->translation->x -= 10;
	if (keycode == 124)
		fdf->translation->x += 10;
	if (keycode == 125)
		fdf->translation->y += 10;
	if (keycode == 126)
		fdf->translation->y -= 10;
	mlx_destroy_image(fdf->mlx, fdf->img->img_ptr);
	ft_memdel((void**)&fdf->img);
	fdf->img = create_img(mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT),
			0x212121, WIN_WIDTH, WIN_HEIGHT);
	set_points(fdf);
	draw_points(fdf, create_point(0, 0));
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img_ptr, 300, 0);
}

static void		mlx_height_zoom(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	mlx_destroy_image(fdf->mlx, fdf->img->img_ptr);
	ft_memdel((void**)&fdf->img);
	fdf->img = create_img(mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT),
			0x212121, WIN_WIDTH, WIN_HEIGHT);
	if (keycode == 78)
		fdf->coef_z--;
	if (keycode == 69)
		fdf->coef_z++;
	set_points(fdf);
	draw_points(fdf, create_point(0, 0));
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img_ptr, 300, 0);
}

int				mlx_key_pressed(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		mlx_translation(keycode, fdf);
	if (keycode == 78 || keycode == 69)
		mlx_height_zoom(keycode, fdf);
	return (0);
}

int				mlx_zoom(int button, int x, int y, void *param)
{
	t_fdf		*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf*)param;
	if (button == 4 || button == 5)
	{
		mlx_destroy_image(fdf->mlx, fdf->img->img_ptr);
		ft_memdel((void**)&fdf->img);
		fdf->img = create_img(mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT),
				0x212121, WIN_WIDTH, WIN_HEIGHT);
		if (button == 4)
			set_point(fdf->spaces, fdf->spaces->x + 1, fdf->spaces->y + 1);
		if (fdf->spaces->x > 1)
		{
			if (button == 5)
				set_point(fdf->spaces, fdf->spaces->x - 1, fdf->spaces->y - 1);
		}
		set_points(fdf);
		draw_points(fdf, create_point(0, 0));
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img_ptr, 300, 0);
	}
	return (0);
}
