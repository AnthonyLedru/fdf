/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:07:00 by aledru            #+#    #+#             */
/*   Updated: 2017/12/09 19:55:25 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		check_first_line(int fd, int first_line_size)
{
	int		res;
	char	*line;

	res = get_next_line(fd, &line);
	if ((res = get_next_line(fd, &line)) == - 1 || res == 0)
		return (0);
	while (line)
		first_line_size++;
	return (first_line_size);
}

int		is_file_valid(char	*file_path)
{
	(void)file_path;
	int		space_count;
	int		first_line_size;
	int		fd;

	space_count = 0;
	first_line_size = 0;
	fd = open(file_path, O_RDONLY);
	if ((first_line_size = check_first_line(fd, first_line_size)) == 0)
		return (0);
	return (1);
}
