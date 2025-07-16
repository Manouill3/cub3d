/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:33:11 by tcybak            #+#    #+#             */
/*   Updated: 2025/07/16 07:14:51 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void    ft_free(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (str[i])
			free(str[i]);
	}
	if (str)
		free(str);
}

void	free_all(t_cub *cub)
{
	if (cub->map && cub->map->map)
		ft_free(cub->map->map);
	if (cub->map)
		free(cub->map);
	if (cub->player)
		free(cub->player);
	if (cub->win)
		free(cub->win);
	if (cub)
		free(cub);
}
