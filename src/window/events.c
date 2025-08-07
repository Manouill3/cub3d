/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:13:54 by mdegache          #+#    #+#             */
/*   Updated: 2025/08/07 13:34:07 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void    move_right(t_cub *cub)
{
    float   cosx;
    float   siny;

    cosx = cos(((cub->player->angle + 90) % 360) * (PI / 180)) * 0.1;
	siny = sin(((cub->player->angle + 90) % 360) * (PI / 180)) * 0.1;
    cub->player->pos_x += cosx;
    cub->player->pos_y += siny;
}

void    move_left(t_cub *cub)
{
    float   cosx;
    float   siny;

    cosx = cos(((cub->player->angle - 90) % 360) * (PI / 180)) * 0.1;
	siny = sin(((cub->player->angle - 90) % 360) * (PI / 180)) * 0.1;
    cub->player->pos_x += cosx;
    cub->player->pos_y += siny;
}

void    move_backward(t_cub *cub)
{
    float   cosx;
    float   siny;

    cosx = cos((cub->player->angle % 360) * (PI / 180)) * 0.1;
	siny = sin((cub->player->angle % 360) * (PI / 180)) * 0.1;
    cub->player->pos_x -= cosx;
    cub->player->pos_y -= siny;
}

void    move_forward(t_cub *cub)
{
    float   cosx;
    float   siny;

    cosx = cos((cub->player->angle % 360) * (PI / 180)) * 0.1;
	siny = sin((cub->player->angle % 360) * (PI / 180)) * 0.1;
    cub->player->pos_x += cosx;
    cub->player->pos_y += siny;
}

void    move(int keycode, void *param)
{
    t_cub   *cub;

    cub = (t_cub *)param;
    if (keycode == 4)
        move_left(cub);
    if (keycode == 7)
        move_right(cub);
    if (keycode == 26)
        move_forward(cub);
    if (keycode == 22)
        move_backward(cub);
}

void handle_key_up(int keycode, void *param)
{
    t_cub *cub;

    cub = (t_cub *)param;
    if (keycode == 79)
        cub->player->arrow_right = 0;
    if (keycode == 80)
        cub->player->arrow_left = 0;
    return ;
}

void    events(t_cub *cub)
{
    cub->player->arrow_left = 0;
    cub->player->arrow_right = 0;
    mlx_on_event(cub->mlx, cub->win->window, MLX_KEYDOWN, handle_key, (void *)cub);
    mlx_on_event(cub->mlx, cub->win->window, MLX_KEYUP, handle_key_up, (void *)cub);
    mlx_on_event(cub->mlx, cub->win->window, MLX_WINDOW_EVENT, event_window, (void *)cub);
}
