/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 06:10:33 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/17 13:46:39 by mdegache         ###   ########.fr       */
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
#include <math.h>
#include "libft/libft.h"
#include "MacroLibX/includes/mlx.h"
#include "MacroLibX/includes/mlx_extended.h"
#include "MacroLibX/includes/mlx_profile.h"
#include "struct.h"

//main.c

int		    check_ext(char *file, char *ext);
int		    ft_init(t_cub **cub);

//parsing

int		    check_ext(char *file, char *ext);
int		    ft_parsing(char **map, t_cub *cub);
int		    ft_transfer_map(t_cub *cub, char *tab);
int         ft_charac_accetable(char str, t_cub *cub, int x, int y);

// parsing map

int	        flood_fill(char **cub, int x, int y, int status);

// utils

char	    *get_next_line(int fd);
int		    ft_strlen_map(char *str);
char        **ft_strcopy(char **str, t_cub *cub);
int         ft_error_charac(t_cub *cub);
mlx_color   color(uint32_t color);

//free

void	    ft_destroy(t_cub *cub);
void	    free_all(t_cub *cub);
void        ft_free(char **str);

// window /Keybord

void        event_window(int event, void *param);
void        handle_key(int keycode, void *param);

// cub3d

void        cub3d(t_cub *cub);
void        ft_draw_map(t_cub *cub);
void        ft_draw_player(t_cub *cub);

//events

void        events(t_cub *cub);

#endif