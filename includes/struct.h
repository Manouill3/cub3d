/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 06:10:05 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/31 10:22:00 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#define PI 3.14159265
#define WIDTH 1280
#define HEIGHT 720

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
}	t_player;

typedef struct s_map
{
	char    	**map;
	mlx_image	img;
	int			size_ver;
	int			nb_player;
}   t_map;

typedef struct s_cub
{
	t_map       *map;
	t_player    *player;
	t_win		*win;
	mlx_context	mlx;
}   t_cub;


#endif