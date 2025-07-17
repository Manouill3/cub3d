/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:34:08 by tcybak            #+#    #+#             */
/*   Updated: 2025/07/17 09:12:00 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

int	check_ext(char *file, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(file) - 1;
	j = ft_strlen(ext) - 1;
	if (ft_strlen(file) < 4)
		return (1);
	while (j > 0)
	{
		if (ext[j] != file[i])
			return (1);
		i--;
		j--;
	}
	return (0);	
}

static char	*ft_copytab(char **map)
{
	int     fd;
	char    *tmp = NULL;
	char    *gnl;
	char    *tab = NULL;

	fd = open(map[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	tab = ft_calloc(1 ,1);
	if (!tab)
		return (NULL);
	gnl = get_next_line(fd);
	while (gnl != 0)
	{
		tmp = ft_strjoin(tab, gnl);
		free(tab);
		free(gnl);
		tab = tmp;
		gnl = get_next_line(fd);
	}
	free(gnl);
	close(fd);
	return (tab);
}

static int	 ft_map_tab(t_cub *cub, char *tab)
{
	if (!tab)
		return (1);
	cub->map->size_ver = 0;
	cub->map->size_ver = ft_strlen_map(tab);
	cub->map->map = ft_calloc(cub->map->size_ver + 1, sizeof(char *));
	if (!cub->map->map)
	{
		free(tab);
		return (1);
	}
	if (ft_transfer_map(cub, tab) == 1)
	{
		free(tab);
		return (1);
	}
	return (0);
}

int	ft_transfer_map(t_cub *cub, char *tab)
{
	int	i;
	int	j;
	int	z;
	int	line_size;

	i = 0;
	j = 0;
	while (tab && tab[i])
	{
		z = 0;
		line_size = 0;
		while (tab[i + line_size] && tab[i + line_size] != '\n')
        	line_size++;
		cub->map->map[j] = ft_calloc(line_size + 1, sizeof(char));
		if (!cub->map->map[j])
			return (1);
		while (tab[i] && tab[i] != '\n')
			cub->map->map[j][z++] = tab[i++];
        if (tab[i] == '\n')
            i++;
		j++;
	}
	free(tab);
	return (0);
}


int	verif_character_map(char **map_tmp, t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	cub->map->nb_player = 0;
	while (map_tmp[y])
	{
		x = 0;
		while (map_tmp[y][x])
		{
			// printf("x = %d, y = %d map = %c\n", x, y, map_tmp[y][x]);
			if (ft_charac_accetable(map_tmp[y][x], cub, x, y) == 1)
			{
				write (2, "Error the characters to create the map are not compliant\n",57);
				return (1);
			}
			x++;
		}
		y++;
	}
	if (ft_error_charac(cub) == 1)
		return (1);
	return (0);
}

int   ft_parsing(char **map, t_cub *cub)
{
    char    *tab;
	char	**map_tmp;
	
	tab = ft_copytab(map);
    if (ft_map_tab(cub, tab))
		return (1);
	map_tmp = ft_strcopy(cub->map->map, cub);
	if (!map_tmp)
		return (1);
	if (verif_character_map(map_tmp, cub) == 1)
	{
		ft_free(map_tmp);
		return (1);
	}
	if (flood_fill(map_tmp, 2, 1, 0) == 1)
	{
		ft_free(map_tmp);
		write (2, "Error map not good\n",19);
		return (1);
	}
    int i = 0;
    while (cub->map->map[i])
    {
        printf("map = %s\n", cub->map->map[i]);
        i++;
    }
	ft_free(map_tmp);
    return (0);
}
