/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:52:39 by aledru            #+#    #+#             */
/*   Updated: 2018/01/05 15:48:46 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		check_hexa(char *line)
{
	int	i;

	i = 0;
	if (*line && *line != '0')
		return (0);
	line++;
	if (*line && *line != 'x')
		return (0);
	line++;
	while (*line && *line != ' ')
	{
		if ((*line < 'A' || *line > 'F') && (*line < 'a' || *line > 'f') &&
				(*line < '0' || *line > '9'))
			return (0);
		line++;
		i++;
	}
	if (i == 0 || i > 6)
		return (0);
	return (1);
}

static	void	init_palette(t_palette *palette)
{
	palette->c1 = NULL;
	palette->c2 = NULL;
	palette->c3 = NULL;
	palette->c4 = NULL;
	palette->c5 = NULL;
}

t_palette		*create_palette(int ac, char **av)
{
	t_palette	*palette;
	int			i;

	i = 2;
	palette = (t_palette*)ft_memalloc(sizeof(t_palette));
	init_palette(palette);
	while (i < ac)
	{
		if (i == 2 && check_hexa(av[i]) == 1)
			palette->c1 = create_color(ft_htoi(av[i]));
		if (i == 3 && check_hexa(av[i]) == 1)
			palette->c2 = create_color(ft_htoi(av[i]));
		if (i == 4 && check_hexa(av[i]) == 1)
			palette->c3 = create_color(ft_htoi(av[i]));
		if (i == 5 && check_hexa(av[i]) == 1)
			palette->c4 = create_color(ft_htoi(av[i]));
		if (i == 6 && check_hexa(av[i]) == 1)
			palette->c5 = create_color(ft_htoi(av[i]));
		i++;
	}
	return (palette);
}
