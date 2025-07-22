/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:13:54 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/22 13:35:01 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void    move(int keycode, void *param)
{
    t_cub   *cub;

    cub = (t_cub *)param;
    if (keycode == 4 && cub->player->pos_x > 0)
        cub->player->pos_x -= 0.1;
    if (keycode == 7 && cub->player->pos_x < 1280)
        cub->player->pos_x += 0.1;
    if (keycode == 26 && cub->player->pos_y > 0)
        cub->player->pos_y -= 0.1;
    if (keycode == 22 && cub->player->pos_y < 720)
        cub->player->pos_y += 0.1;
}

void handle_key_up(int keycode, void *param)
{
    t_cub *cub;

    cub = (t_cub *)param;
    if (keycode == 79)
    {
        cub->player->arrow_right = 0;
    }
    if (keycode == 80)
    {
        cub->player->arrow_left = 0;
    }
    return ;
}

void    events(t_cub *cub)
{
    cub->player->arrow_left = 0;
    cub->player->arrow_right = 0;
    cub->player->angle = (180 - FOV) / 2;
    mlx_on_event(cub->mlx, cub->win->window, MLX_KEYDOWN, handle_key, (void *)cub);
    mlx_on_event(cub->mlx, cub->win->window, MLX_KEYUP, handle_key_up, (void *)cub);
    mlx_on_event(cub->mlx, cub->win->window, MLX_WINDOW_EVENT, event_window, (void *)cub);
}
