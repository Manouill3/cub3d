/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 07:26:46 by tcybak            #+#    #+#             */
/*   Updated: 2025/07/29 09:03:00 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

int ft_strlen_map(char *str)
{
    int i;
    int n;

    i = -1;
    n = 0;
    if (!str || !str[0])
        return 0;
    while (str[++i])
    {
        if (str[i] == '\n')
            n++;
    }
    if (i > 0 && str[i - 1] != '\n')
        n++;
    return (n);
}

int ft_charac_accetable(char str, t_cub *cub, int x, int y)
{
    // printf ("caractere = %d\n", str);
    if (str == 'N' || str == 'S' || str == 'E' || str == 'W')
    {
        cub->player->pos_x = x;
        cub->player->pos_y = y;
        cub->map->nb_player++;
    }
    if ((str == '0' || str == '1' || str == 'N'
        || str == 'S' || str == 'E' || str == 'W' 
        || str == '\b' || str == '\t' || str == ' '))
        return (0);
    return (1);
}

int ft_error_charac(t_cub *cub)
{
    if (cub->map->nb_player > 1)
    {
        write (2, "Error too many player\n",22);
        return (1);
    }
    else if (cub->map->nb_player < 1)
    {
        write (2, "Error not enough players\n",25);
        return (1);
    }
    return (0);
}

char    **ft_strcopy(char **str, t_cub *cub)
{
    int     len;
    int     i;
    int     j;
    char    **new_str;

    len = cub->map->size_ver;
    new_str = ft_calloc(len + 1, sizeof(char *));
    if (!new_str)
        return (NULL);
    len = 0;
    i = 0;
    while (str[i])
    {
        j = 0;
        len = ft_strlen(str[i]);
        new_str[i] = ft_calloc(len + 1, sizeof(char));
        if (!new_str[i])
        {
            ft_free(new_str);
            return (NULL);
        }
        while (j < len)
        {
            new_str[i][j] = str[i][j];
            j++;
        }
        i++;
    }
    return (new_str);
}
