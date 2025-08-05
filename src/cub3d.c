/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 07:15:27 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/31 17:13:32 by tcybak           ###   ########.fr       */
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
	int		ray_x;
	int		ray_y;
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
			// create_rect(cub, ray_x * 32, ray_y * 32, 32, 32, color(0xFF0000FF));
			if (cub->map->map[ray_y][ray_x] == '1')
				break;
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
	while (win_y < 8)
	{
		win_x = 0;
		while (win_x < 8)
		{
			mlx_pixel_put(cub->mlx, cub->win->window, win_x + cub->player->pos_x * 8, win_y + cub->player->pos_y * 8, color(0x0000FFFF));
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
				while (win_y < 8)
				{
					win_x = 0;
					while (win_x < 8)
					{
						mlx_pixel_put(cub->mlx, cub->win->window, win_x + x * 8, win_y + y * 8, color(0xFFFFFFFF));
						win_x++;
					}
					win_y++;
				}
			}
			if (cub->map->map[y][x] == '0' || cub->map->map[y][x] == 'N' || cub->map->map[y][x] == 'S' || cub->map->map[y][x] == 'E' || cub->map->map[y][x] == 'W')
			{
				win_y = 0;
				while (win_y < 8)
				{
					win_x = 0;
					while (win_x < 8)
					{
						mlx_pixel_put(cub->mlx, cub->win->window, win_x + x * 8, win_y + y * 8, color(0x00FF00FF));
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
	float	dx;
	float	dy;
	float	dist;
	float	start_y;
	float	end_y;
	float 	player_angle;
	float 	ray_angle;
	float 	wall_x;
	float	start_y_tmp;
	int		tex_x;
	int		tex_y;
	mlx_color pixel_color;

	if (cub->player->arrow_left)
		cub->player->angle -= 1;
	if (cub->player->arrow_right)
		cub->player->angle += 1;
	i = 0;
	while (i < WIDTH)
	{	
		ray_x = (int)cub->player->pos_x;
		ray_y = (int)cub->player->pos_y;
		cosx = cos(((cub->player->angle % 360 - FOV / 2) + i * FOV / (float)WIDTH) * (PI / 180.0));
		siny = sin(((cub->player->angle % 360 - FOV / 2) + i * FOV / (float)WIDTH) * (PI / 180.0));
		delx = sqrt(1 + (siny * siny) / (cosx * cosx));
		dely = sqrt(1 + (cosx * cosx) / (siny * siny));
		if (cosx > 0)
		{
			cub->player->stepx = 1;
			dx = (1 - (cub->player->pos_x - (float)ray_x)) * delx;
		}
		else
		{
			cub->player->stepx = -1;
			dx = (cub->player->pos_x - (float)ray_x) * delx;
		}
		if (siny > 0)
		{
			cub->player->stepy = 1;
			dy = (1 - (cub->player->pos_y - (float)ray_y)) * dely;
		}
		else
		{
			cub->player->stepy = -1;
			dy = (cub->player->pos_y - (float)ray_y) * dely;
		}
		int	side;

		side = 0;
		while (1)
		{
			if (cub->map->map[ray_y][ray_x] == '1')
				break;
			if (dx > dy)
			{
				ray_y += cub->player->stepy;
				dy += dely;
				side = 0;
			}
			else
			{
				ray_x += cub->player->stepx;
				dx += delx;
				side = 1;
			}
		}
		if (side == 1)
			dist = (dx - delx);
		else
			dist = (dy - dely);
		ray_angle = ((cub->player->angle % 360 - FOV / 2) + i * FOV / (float)WIDTH) * (PI / 180.0);
		player_angle = (cub->player->angle % 360) * (PI / 180.0);
		dist = dist * cos(ray_angle - player_angle);
		cub->player->height = HEIGHT / dist;
		start_y = (-cub->player->height / 2) + (HEIGHT / 2);
		if (start_y < 0)
			start_y = 0;
		end_y = start_y + cub->player->height;
		if (end_y > HEIGHT)
			end_y = HEIGHT - 1;
		start_y_tmp = start_y;
		if (side == 0)
		{
			if (cub->player->stepy == - 1)
			{
				while (start_y < end_y)
				{
					wall_x = cub->player->pos_x + dist * cosx;
					wall_x = wall_x - floor(wall_x);
					tex_x = (int)(wall_x * cub->map->w_n);
					tex_y = (int)(((start_y - start_y_tmp) * cub->map->h_n) / cub->player->height);
					pixel_color = mlx_get_image_pixel(cub->mlx ,cub->map->img_nord, tex_x, tex_y);
					mlx_pixel_put(cub->mlx, cub->win->window, i, start_y, pixel_color);
					start_y++;
				}
			}
			else
			{
				while (start_y < end_y)
				{
					wall_x = cub->player->pos_x + dist * cosx;
					wall_x = wall_x - floor(wall_x);
					tex_x = (int)(wall_x * cub->map->w_s);
					tex_y = (int)(((start_y - start_y_tmp) * cub->map->h_s) / cub->player->height);
					pixel_color = mlx_get_image_pixel(cub->mlx ,cub->map->img_sud, tex_x, tex_y);
					mlx_pixel_put(cub->mlx, cub->win->window, i, start_y, pixel_color);
					start_y++;
				}
			}
		}
		if (side == 1)
		{
			if (cub->player->stepx == - 1)
			{
				while (start_y < end_y)
				{
					wall_x = cub->player->pos_y + dist * siny;
					wall_x = wall_x - floor(wall_x);
					tex_x = (int)(wall_x * cub->map->w_o);
					tex_y = (int)(((start_y - start_y_tmp) * cub->map->h_o) / cub->player->height);
					pixel_color = mlx_get_image_pixel(cub->mlx ,cub->map->img_Ouest, tex_x, tex_y);
					mlx_pixel_put(cub->mlx, cub->win->window, i, start_y, pixel_color);
					start_y++;
				}
			}
			else
				while (start_y < end_y)
				{
					wall_x = cub->player->pos_y + dist * siny;
					wall_x = wall_x - floor(wall_x);
					tex_x = (int)(wall_x * cub->map->w_e);
					tex_y = (int)(((start_y - start_y_tmp) * cub->map->h_e) / cub->player->height);
					pixel_color = mlx_get_image_pixel(cub->mlx ,cub->map->img_Est, tex_x, tex_y);
					mlx_pixel_put(cub->mlx, cub->win->window, i, start_y, pixel_color);
					start_y++;
				}
		}
		i++;
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
	cub->map->img_nord = mlx_new_image_from_file(cub->mlx,"./includes/pictures/me.png", &cub->map->w_n, &cub->map->h_n);
	if (!cub->map->img_nord )
		exit(1);
	cub->map->img_sud = mlx_new_image_from_file(cub->mlx,"./includes/pictures/chat_sud.png", &cub->map->w_s, &cub->map->h_s);
	cub->map->img_Est = mlx_new_image_from_file(cub->mlx,"./includes/pictures/chat_est.png", &cub->map->w_e, &cub->map->h_e);
	cub->map->img_Ouest = mlx_new_image_from_file(cub->mlx,"./includes/pictures/chat_ouest.png", &cub->map->w_o, &cub->map->h_o);
	if (!cub->map->img_Ouest)
	{
		perror("Erreur chargement image Ouest");
		exit(1);
	}
	// draw_ray(cub);
	raycast(cub);
	ft_draw_map(cub);
	ft_draw_player(cub);
	events(cub);
}

void    cub3d(t_cub *cub)
{
	cub->mlx = mlx_init();
	init_win(cub);
}
