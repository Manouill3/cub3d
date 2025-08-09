/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keybord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 07:35:52 by tcybak            #+#    #+#             */
/*   Updated: 2025/08/07 15:53:26 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void event_window(int event, void *param)
{
    t_cub *cub;
    
    cub = (t_cub *)param;
    if (event == 0)
    {
        ft_destroy(cub);
        free_all(cub);
        exit(0);
    }
}

void handle_key(int keycode, void *param)
{
    t_cub *cub;

    cub = (t_cub *)param;
    if (keycode == 41)
    {
        ft_destroy(cub);
        free_all(cub);
        exit(0);
    }
    if (keycode == 79)
        cub->player->arrow_right = 1;   
    if (keycode == 80)
        cub->player->arrow_left = 1;
    if (4 == keycode)
        cub->key[4] = 1;
    if (7 == keycode)
        cub->key[7] = 1;
    if (22 == keycode)
        cub->key[22] = 1;
    if (26 == keycode)
        cub->key[26] = 1;
    // printf("keycode = %d | 4 = %d | 7 = %d | 22 = %d | 26 = %d\n", keycode, cub->key[4], cub->key[7], cub->key[22], cub->key[26]);
    //move(keycode, param);
    //mlx_clear_window(cub->mlx, cub->win->window, color(0x000000FF));
    // draw_ray(cub);
    //raycast(cub);
    ft_draw_map(cub);
    ft_draw_player(cub);
    return ;
}
