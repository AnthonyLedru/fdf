/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:07:19 by aledru            #+#    #+#             */
/*   Updated: 2018/01/08 19:53:40 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int			fd;
	t_fdf		*fdf;

	if (ac < 2 || ac > 7)
		arg_error();
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		system_error();
	fdf = check_valid_file(fd, ac, av);
	close(fd);
	create_window(fdf, av[1]);
	return (0);
}
