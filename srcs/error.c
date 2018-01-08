/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 22:48:18 by aledru            #+#    #+#             */
/*   Updated: 2018/01/08 13:41:13 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	malloc_error(void)
{
	ft_putstr_fd("error : Malloc failed\n", 2);
	exit(EXIT_FAILURE);
}

void	palette_error(void)
{
	ft_putstr_fd("error: Color must be specified in hexadecimal \
(ex 0xFFFFF)\n", 2);
	exit(EXIT_FAILURE);
}

void	arg_error(void)
{
	ft_putstr_fd("usage: fdf [map_file] [c1] [c2] [c3] [c4] [c5]\n", 2);
	exit(EXIT_FAILURE);
}

void	map_error(void)
{
	ft_putstr_fd("error : Map invalid\n", 2);
	exit(EXIT_FAILURE);
}

void	system_error(void)
{
	perror("error ");
	exit(EXIT_FAILURE);
}
