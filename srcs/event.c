/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:18:49 by aledru            #+#    #+#             */
/*   Updated: 2017/12/19 10:44:59 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mlx_escape(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		mlx_zoom(int keycode, void *param)
{
	(void)param;
	if (keycode == 4)
	{

	}
	//zoom bas
	if (keycode == 5)
	{

	}
	return (0);
}