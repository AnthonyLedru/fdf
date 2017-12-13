/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:07:19 by aledru            #+#    #+#             */
/*   Updated: 2017/12/13 19:35:51 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error ");
		exit(EXIT_FAILURE);
	}
	check_valid_file(fd);
	/*char *line;
	int i = 0;
	while (get_next_line(fd, &line))
	{
		if (i == 6)
			printf("%s\n", line);
		i++;
	}*/
	return (0);
}
