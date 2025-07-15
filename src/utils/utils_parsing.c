/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 07:26:46 by tcybak            #+#    #+#             */
/*   Updated: 2025/07/15 12:05:24 by tcybak           ###   ########.fr       */
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
