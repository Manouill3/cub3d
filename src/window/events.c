/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:13:54 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/17 14:47:02 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void    move_down(int keycode, void *param)
{
    t_cub   *cub;

    cub = (t_cub *)param;
    if (keycode == 22 && cub->player->pos_y < 720)
    {
        cub->player->pos_y += 0.2;
        mlx_clear_window(cub->mlx, cub->win->window, color(0x000000FF));
        ft_draw_map(cub);
        ft_draw_player(cub);
    }
}

void    move_up(int keycode, void *param)
{
    t_cub   *cub;

    cub = (t_cub *)param;
    if (keycode == 26 && cub->player->pos_y > 0)
    {
        cub->player->pos_y -= 0.2;
        mlx_clear_window(cub->mlx, cub->win->window, color(0x000000FF));
        ft_draw_map(cub);
        ft_draw_player(cub);
    }
}

void    move_right(int keycode, void *param)
{
    t_cub   *cub;

    cub = (t_cub *)param;
    if (keycode == 7 && cub->player->pos_x < 1280)
    {
        cub->player->pos_x += 0.2;
        mlx_clear_window(cub->mlx, cub->win->window, color(0x000000FF));
        ft_draw_map(cub);
        ft_draw_player(cub);
    }
}

void    move_left(int keycode, void *param)
{
    t_cub   *cub;

    cub = (t_cub *)param;
    if (keycode == 4 && cub->player->pos_x > 0)
    {
        cub->player->pos_x -= 0.2;
        mlx_clear_window(cub->mlx, cub->win->window, color(0x000000FF));
        ft_draw_map(cub);
        ft_draw_player(cub);
    }
}

void    events(t_cub *cub)
{
    mlx_on_event(cub->mlx, cub->win->window, MLX_KEYDOWN, handle_key, (void *)cub);
    mlx_on_event(cub->mlx, cub->win->window, MLX_WINDOW_EVENT, event_window, (void *)cub);
    mlx_on_event(cub->mlx, cub->win->window, 0, move_right, (void *)cub);
    mlx_on_event(cub->mlx, cub->win->window, 0, move_left, (void *)cub);
    mlx_on_event(cub->mlx, cub->win->window, 0, move_up, (void *)cub);
    mlx_on_event(cub->mlx, cub->win->window, 0, move_down, (void *)cub);
}
