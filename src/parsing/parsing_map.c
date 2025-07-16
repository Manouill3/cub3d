/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:31:44 by tcybak            #+#    #+#             */
/*   Updated: 2025/07/16 11:14:49 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

int	strlen_line(char **map)
{
	int y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

int	flood_fill(char **cub, int x, int y, int status) // status = 0;
{
	if (status == 1)
		return (1);
	if (x < 0 || y < 0 || (int)ft_strlen(cub[y]) <= x 
		|| (int)strlen_line(cub) <= y)
		return (1);
	if (cub[y][x] != '0')
		return (status);
	cub[y][x] = 'o';
	status = flood_fill(cub, x + 1, y, status);
	status = flood_fill(cub, x - 1, y, status);
	status = flood_fill(cub, x, y + 1, status);
	status = flood_fill(cub, x, y - 1, status);
	return (status);
}
