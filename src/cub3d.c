/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 07:15:27 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/22 14:40:14 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void    create_rect(t_cub *cub, int x, int y, int w, int h, mlx_color color)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < h)
    {
        j = 0;
        while (j < w)
        {
            mlx_pixel_put(cub->mlx, cub->win->window, x + j, y + i, color);
            j++;
        }
        i++;
    }
}

void    ft_draw_line(t_cub *cub)
{
    int     i;
    int     map_x;
    int     map_y;
    int     step_x;
    int     step_y;
    float   cos_x;
    float   sin_y;
    float   ray_x;
    float   ray_y;
    float   lenght_x;
    float   lenght_y;

    i = 0;
    map_x = (int)cub->player->pos_x;
    map_y = (int)cub->player->pos_y;
    while (i < FOV)
    {
        cos_x = cos((cub->player->angle + i) % 360 * (3.14 / 180.0));
        sin_y = sin((cub->player->angle + i) % 360 * (3.14 / 180.0));
        ray_x = sqrt(1 + (sin_y / cos_x) * (sin_y / cos_x));
        ray_y = sqrt(1 + (cos_x / sin_y) * (cos_x / sin_y));
        if (cos_x > 0)
        {
            step_x = 1;
            lenght_x = (1 - (cub->player->pos_x - (float)map_x)) * ray_x;
        }
        else
        {
            step_x = -1;
            lenght_x = (cub->player->pos_x - (float)map_x) * ray_x;
        }
        if (sin_y > 0)
        {
            step_y = 1;
            lenght_y = (1 - (cub->player->pos_y - (float)map_y)) * ray_y;
        }
        else
        {
            step_y = -1;
            lenght_y = (cub->player->pos_y - (float)map_y) * ray_y;
        }
        while (1)
        {
            if (cub->map->map[map_y][map_x] == '1')
                break;
            create_rect(cub, map_x * 32, map_y * 32, 32, 32, color(0xFF0000FF));
            if (lenght_x > lenght_y)
            {
                map_y += step_y;
                lenght_y += ray_y;
            }
            else
            {
                map_x += step_x;
                lenght_x += ray_x;
            }
        }
        i++;
    }
    if (cub->player->arrow_left == 1)
        cub->player->angle += 1 % 360;
    if (cub->player->arrow_right == 1)
        cub->player->angle -= 1 % 360;
}

void    ft_draw_player(t_cub *cub)
{
    int win_x;
    int win_y;
    
    win_y = 0;
    while (win_y < 32)
    {
        win_x = 0;
        while (win_x < 32)
        {
            mlx_pixel_put(cub->mlx, cub->win->window, win_x + cub->player->pos_x * 32, win_y + cub->player->pos_y * 32, color(0x000000FF));
            win_x++;
        }
        win_y++;
    }
}

void    ft_draw_map(t_cub *cub)
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
            if (cub->map->map[y][x] == '0' || cub->map->map[y][x] == 'N' || cub->map->map[y][x] == 'S' || cub->map->map[y][x] == 'E' || cub->map->map[y][x] == 'W')
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
    ft_draw_map(cub);
    ft_draw_line(cub);
    ft_draw_player(cub);
    events(cub);
}

void    cub3d(t_cub *cub)
{
    cub->mlx = mlx_init();
    init_win(cub);
}
