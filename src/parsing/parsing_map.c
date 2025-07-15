/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:31:44 by tcybak            #+#    #+#             */
/*   Updated: 2025/07/15 16:50:18 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

int ft_check_border(t_cub *cub)
{
    int ver;
    int hor;
    int hor_next;

    ver = 0;
    while (cub->map[ver])
    {
        hor = 0;
        hor_next = 0;
        while (cub->map[ver][hor] && cub->map[ver][hor + 1] != '\0')
            hor++;
        if (!cub->map[ver + 1])
            break;
        while (cub->map[ver] && cub->map[ver + 1] && cub->map[ver + 1][hor_next] && cub->map[ver + 1][hor_next + 1] != '\0')
            hor_next++;
        if (cub->map[ver][hor] != '1' || cub->map[ver + 1][hor_next] != '1' )
        {
            write(2, "bad map edge\n", 13);    
            return (1);
        }
        ver++;
    }
    return (0);
}
