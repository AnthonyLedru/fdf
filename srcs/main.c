/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:07:19 by aledru            #+#    #+#             */
/*   Updated: 2017/12/15 18:03:47 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	t_fdf	*fdf;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error ");
		exit(EXIT_FAILURE);
	}
	fdf = check_valid_file(fd);
	fdf->spaces = get_spaces(fdf);
	create_window(fdf, av[1]);
	return (0);
}
