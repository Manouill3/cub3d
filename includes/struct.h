/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 06:10:05 by mdegache          #+#    #+#             */
/*   Updated: 2025/08/07 15:19:01 by tcybak           ###   ########.fr       */
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
	// float	ray_x;
	// float	ray_y;
	// float 	pos_end_x;
	// float 	pos_end_y;
	float	pos_x;
	float	pos_y;
	float	dist;
	int		height;
	int		stepx;
	int		stepy;
	int		angle;
	int		arrow_left;
	int		arrow_right;
	char	chara;
}	t_player;

typedef struct s_map
{
	char    	**map;
	int			w_n;
	int			h_n;
	int			w_s;
	int			h_s;
	int			w_e;
	int			h_e;
	int			w_o;
	int			h_o;
	int			size_ver;
	int			nb_player;
}   t_map;

typedef enum s_image
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	SIZE,
} t_image;


typedef struct s_cub
{
	mlx_image	img[SIZE];
	int			key[250];
	t_map       *map;
	t_player    *player;
	t_win		*win;
	mlx_context	mlx;
}   t_cub;


#endif