/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:34:08 by tcybak            #+#    #+#             */
/*   Updated: 2025/07/15 12:24:35 by tcybak           ###   ########.fr       */
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
	cub->size_ver = 0;
	cub->size_ver = ft_strlen_map(tab);
	cub->map = ft_calloc(cub->size_ver + 1, sizeof(char *));
	if (!cub->map)
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
		cub->map[j] = ft_calloc(line_size + 1, sizeof(char));
		if (!cub->map[j])
			return (1);
		while (tab[i] && tab[i] != '\n')
			cub->map[j][z++] = tab[i++];
        if (tab[i] == '\n')
            i++;
		j++;
	}
	free(tab);
	return (0);
}

int    ft_parsing(char **map, t_cub *cub)
{
    char    *tab;

	tab = ft_copytab(map);
    if (ft_map_tab(cub, tab) == 1)
        return (1);
    int i = 0;
    while (cub->map[i])
    {
        printf("%s\n", cub->map[i]);
        i++;
    }
    return (0);
}
