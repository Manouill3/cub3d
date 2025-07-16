/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keybord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 07:35:52 by tcybak            #+#    #+#             */
/*   Updated: 2025/07/16 07:40:25 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void event_window(int event, void *param)
{
    t_cub *cub;
    
    cub = (t_cub *)param;
    if (event == 0) { 
        free_all(cub);
        exit(0);
    }
}

void handle_key(int keycode, void *param)
{
    t_cub *cub;
    
    cub = (t_cub *)param;
    if (keycode == 41) { 
        free_all(cub);
        exit(0);
    }
}
