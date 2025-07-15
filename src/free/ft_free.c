/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:33:11 by tcybak            #+#    #+#             */
/*   Updated: 2025/07/15 12:33:46 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void    ft_free(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (str[i])
			free(str[i]);
	}
	if (str)
		free(str);
}

void	free_all(t_cub *cub)
{
	if (cub->map)
		ft_free(cub->map);
	if (cub)
		free(cub);
}
