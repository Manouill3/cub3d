/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 06:10:05 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/17 13:55:00 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_win
{
	float	win_x;
	float	win_y;
	mlx_window	window;
}	t_win;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
}	t_player;

typedef struct s_map
{
	char    **map;
	int		size_ver;
	int		nb_player;
}   t_map;

typedef struct s_cub
{
	t_map       *map;
	t_player    *player;
	t_win		*win;
	mlx_context	mlx;
}   t_cub;


#endif