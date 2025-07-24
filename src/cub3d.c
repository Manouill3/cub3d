/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 07:15:27 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/24 14:58:31 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void    create_rect(t_cub *cub, int x, int y, int w, int h, mlx_color color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			mlx_pixel_put(cub->mlx, cub->win->window, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_ray(t_cub *cub)
{
	int	i;
	float	cosx;
	float	siny;
	int	ray_x;
	int	ray_y;
	float	delx;
	float	dely;
	float	distx;
	float	disty;

	if (cub->player->arrow_left)
		cub->player->angle -= 1;
	if (cub->player->arrow_right)
		cub->player->angle += 1;
	i = 0;
	while (i < FOV)
	{
		cosx = cos(((cub->player->angle % 360) + i) * (PI / 180));
		siny = sin(((cub->player->angle % 360) + i) * (PI / 180));
		delx = sqrt(1 + (siny / cosx) * (siny / cosx));
		dely = sqrt(1 + (cosx / siny) * (cosx / siny));
		ray_x = (int)cub->player->pos_x;
		ray_y = (int)cub->player->pos_y;
		if (cosx > 0)
		{
			cub->player->stepx = 1;
			distx = (1 - (cub->player->pos_x - (float)ray_x)) * delx;
		}
		else
		{
			cub->player->stepx = -1;
			distx = (cub->player->pos_x - (float)ray_x) * delx;
		}
		if (siny > 0)
		{
			cub->player->stepy = 1;
			disty = (1 - (cub->player->pos_y - (float)ray_y)) * dely;
		}
		else
		{
			cub->player->stepy = -1;
			disty = (cub->player->pos_y - (float)ray_y) * dely;
		}
		while (1)
		{
			if (cub->map->map[ray_y][ray_x] == '1')
				break;
			create_rect(cub, ray_x * 32, ray_y * 32, 32, 32, color(0xFF0000FF));
			if (distx > disty)
			{
				ray_y += cub->player->stepy;
				disty += dely;
			}
			else
			{
				ray_x += cub->player->stepx;
				distx += delx;
			}
		}
		i++;	
	}
}

void    ft_draw_player(t_cub *cub)
{
	int win_x;
	int win_y;
	
	win_y = 0;
	while (win_y < 32)
	{
		win_x = 0;
		while (win_x < 32)
		{
			mlx_pixel_put(cub->mlx, cub->win->window, win_x + cub->player->pos_x * 32, win_y + cub->player->pos_y * 32, color(0x0000FFFF));
			win_x++;
		}
		win_y++;
	}
}

void    ft_draw_map(t_cub *cub)
{
	int win_x;
	int win_y;
	int x;
	int y;

	y = 0;
	while (cub->map->map[y])
	{
		x = 0;
		while (cub->map->map[y][x])
		{
			if (cub->map->map[y][x] == '1')
			{
				win_y = 0;
				while (win_y < 32)
				{
					win_x = 0;
					while (win_x < 32)
					{
						mlx_pixel_put(cub->mlx, cub->win->window, win_x + x * 32, win_y + y * 32, color(0xFFFFFFFF));
						win_x++;
					}
					win_y++;
				}
			}
			if (cub->map->map[y][x] == '0' || cub->map->map[y][x] == 'N' || cub->map->map[y][x] == 'S' || cub->map->map[y][x] == 'E' || cub->map->map[y][x] == 'W')
			{
				win_y = 0;
				while (win_y < 32)
				{
					win_x = 0;
					while (win_x < 32)
					{
						mlx_pixel_put(cub->mlx, cub->win->window, win_x + x * 32, win_y + y * 32, color(0x00FF00FF));
						win_x++;
					}
					win_y++;
				}
			}
			x++;
		}
		y++;
	}
}

void	raycast(t_cub *cub)
{
	int		i;
	int		ray_x;
	int		ray_y;
	float	cosx;
	float	siny;
	float	delx;
	float	dely;
	float	distx;
	float	disty;
	float	diff;

	i = 0;
	while (i < WIDTH)
	{	
		ray_x = (int)cub->player->pos_x;
		ray_y = (int)cub->player->pos_y;
		cosx = cos((cub->player->angle % 360) * (PI / 180.0));
		siny = sin((cub->player->angle % 360) * (PI / 180.0));
		delx = sqrt(1 + (siny * siny) / (cosx * cosx));
		dely = sqrt(1 + (cosx * cosx) / (siny * siny));
		if (cosx > 0)
		{
			cub->player->stepx = 1;
			distx = (1 - (cub->player->pos_x - (float)ray_x)) * delx;
		}
		else
		{
			cub->player->stepx = -1;
			distx = (cub->player->pos_x - (float)ray_x) * delx;
		}
		if (siny > 0)
		{
			cub->player->stepy = 1;
			disty = (1 - (cub->player->pos_y - (float)ray_y)) * dely;
		}
		else
		{
			cub->player->stepy = -1;
			disty = (cub->player->pos_y - (float)ray_y) * dely;
		}
	}
}

void    init_win(t_cub *cub)
{
	mlx_window_create_info info;
	
	ft_memset(&info, 0, sizeof(info));
	info.title = "Cub3D";
	info.width = WIDTH;
	info.height = HEIGHT;
	cub->win->window = mlx_new_window(cub->mlx, &info);
	cub->player->angle = (180 - FOV) / 2;
	// ft_draw_map(cub);
	// draw_ray(cub);
	// ft_draw_player(cub);
	events(cub);
}

void    cub3d(t_cub *cub)
{
	cub->mlx = mlx_init();
	init_win(cub);
}
