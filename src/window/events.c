/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:13:54 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/17 10:40:40 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void    move_left(int keycode, void *param)
{
    t_cub   *cub;

    cub = (t_cub *)param;
    printf("%d\n", keycode);
    if (keycode == 7)
        
}

void    events(t_cub *cub)
{
    mlx_on_event(cub->mlx, cub->win->window, 0, move_left, (void *)cub);
}