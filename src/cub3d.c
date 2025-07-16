/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 07:15:27 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/16 10:08:26 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void    init_win(t_cub *cub)
{
    mlx_window_create_info info;
    
    ft_memset(&info, 0, sizeof(info));
    info.title = "Cub3D";
    info.width = 1280;
    info.height = 720;
    cub->win->window = mlx_new_window(cub->mlx, &info);
    mlx_on_event(cub->mlx, cub->win->window, MLX_KEYDOWN, handle_key, (void *)cub);
    mlx_on_event(cub->mlx, cub->win->window, MLX_WINDOW_EVENT, event_window, (void *)cub);
}

void    cub3d(t_cub *cub)
{
    cub->mlx = mlx_init();
    init_win(cub);
}
