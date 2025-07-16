/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 06:10:33 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/15 17:41:33 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 42
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "MacroLibX/includes/mlx.h"
#include "MacroLibX/includes/mlx_extended.h"
#include "MacroLibX/includes/mlx_profile.h"
#include "struct.h"



//main.c

int		check_ext(char *file, char *ext);

//parsing

int		check_ext(char *file, char *ext);
int		ft_parsing(char **map, t_cub *cub);
int		ft_transfer_map(t_cub *cub, char *tab);

// parsing map

int	flood_fill(t_cub *cub, int x, int y, int status);

// utils

char	*get_next_line(int fd);
int		ft_strlen_map(char *str);

//free

void	free_all(t_cub *cub);


#endif