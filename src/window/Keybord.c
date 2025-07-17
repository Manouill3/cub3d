/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keybord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 07:35:52 by tcybak            #+#    #+#             */
/*   Updated: 2025/07/17 13:01:00 by tcybak           ###   ########.fr       */
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
    // mlx_clear_window(cub->mlx,cub->win->window, color(0x00FF00FF));
    // ft_draw_pixel(cub);
    return ;
}