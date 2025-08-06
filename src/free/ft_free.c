/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:33:11 by tcybak            #+#    #+#             */
/*   Updated: 2025/08/06 14:23:26 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void    ft_free(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

void	ft_destroy(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->map->img_nord);
	mlx_destroy_image(cub->mlx, cub->map->img_sud);
	mlx_destroy_image(cub->mlx, cub->map->img_Est);
	mlx_destroy_image(cub->mlx, cub->map->img_Ouest);
	mlx_destroy_window(cub->mlx, cub->win->window);
	mlx_destroy_context(cub->mlx);
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
