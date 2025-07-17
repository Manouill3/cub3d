/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:13:54 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/17 10:52:04 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void    move_left(int keycode, void *param)
{
    t_cub   *cub;

    cub = (t_cub *)param;
    printf("%d\n", keycode);
    if (keycode == 7)
        cub->player->pos_x += 0.1;
}

void    events(t_cub *cub)
{
    mlx_on_event(cub->mlx, cub->win->window, 0, move_left, (void *)cub);
}