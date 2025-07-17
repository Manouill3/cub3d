/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 07:15:27 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/17 12:41:22 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void    ft_draw_pixel(t_cub *cub)
{
    int win_x;
    int win_y;
    int x;
    int y;

    y = 0;
    while (cub->map->map[y])
    {
        x = 0;
        while (cub->map->map[y][x])
        {
            if (cub->map->map[y][x] == '1')
            {
                win_y = 0;
                while (win_y < 32)
                {
                    win_x = 0;
                    while (win_x < 32)
                    {
                        mlx_pixel_put(cub->mlx, cub->win->window, win_x + x * 32, win_y + y * 32, color(0xFFFFFFFF));
                        win_x++;
                    }
                    win_y++;
                }
            }
            if (cub->map->map[y][x] == '0')
            {
                win_y = 0;
                while (win_y < 32)
                {
                    win_x = 0;
                    while (win_x < 32)
                    {
                        mlx_pixel_put(cub->mlx, cub->win->window, win_x + x * 32, win_y + y * 32, color(0x00FF00FF));
                        win_x++;
                    }
                    win_y++;
                }
            }
            if (cub->map->map[y][x] == 'W')
            {
                win_y = 0;
                while (win_y < 32)
                {
                    win_x = 0;
                    while (win_x < 32)
                    {
                        mlx_pixel_put(cub->mlx, cub->win->window, win_x + x * 32, win_y + y * 32, color(0xFFFF00FF));
                        win_x++;
                    }
                    win_y++;
                }
            }
            x++;
        }
        y++;
    }
}

void    init_win(t_cub *cub)
{

    mlx_window_create_info info;
    
    ft_memset(&info, 0, sizeof(info));
    info.title = "Cub3D";
    info.width = 1280;
    info.height = 720;
    cub->win->window = mlx_new_window(cub->mlx, &info);

    ft_draw_pixel(cub);
    mlx_on_event(cub->mlx, cub->win->window, MLX_KEYDOWN, handle_key, (void *)cub);
    mlx_on_event(cub->mlx, cub->win->window, MLX_WINDOW_EVENT, event_window, (void *)cub);
}

void    cub3d(t_cub *cub)
{
    cub->mlx = mlx_init();
    init_win(cub);
}
