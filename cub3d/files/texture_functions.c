/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 03:15:28 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/22 03:15:32 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		swap(t_sprite *a, t_sprite *b)
{
	t_sprite	c;

	c.x = a->x;
	c.y = a->y;
	c.dist = a->dist;
	a->x = b->x;
	a->y = b->y;
	a->dist = b->dist;
	b->x = c.x;
	b->y = c.y;
	b->dist = c.dist;
}

void		render_spt(int x, int y, int sp_size, int k)
{
	int		color;
	int		i;
	int		j;

	i = 0;
	color = 0;
	while (i++ < sp_size)
	{
		if (x + i < 0 || x + i > g_resolution_x)
			continue;
		if (g_sprites[k].dist >= s_rays[x + i].distance)
			continue;
		j = 0;
		while (j++ < sp_size)
		{
			if ((int)(g_textures[4].height * (j * g_textures[4].width /\
			sp_size) + (i * g_textures[4].height / sp_size)) < \
			g_textures[4].width * g_textures[4].height)
				color = g_textures[4].data[(int)(g_textures[4].height *\
				(j * g_textures[4].width / sp_size) +\
				(i * g_textures[4].height / sp_size))];
			if (color != 0)
				put_pixel(new_vector(x + i, y + j), color);
		}
	}
}

void		ft_sprites_draw(int i)
{
	float		sp_size;
	float		x_inter;
	float		y_inter;
	float		sp_angle;

	sp_angle = atan2(g_sprites[i].y - s_player.y, g_sprites[i].x - s_player.x);
	while (sp_angle - s_player.rotationangle > M_PI)
		sp_angle -= 2 * M_PI;
	while (sp_angle - s_player.rotationangle < -M_PI)
		sp_angle += 2 * M_PI;
	if (g_resolution_y > g_resolution_x)
		sp_size = (g_resolution_y / g_sprites[i].dist) * g_tile_size;
	else
		sp_size = (g_resolution_x / g_sprites[i].dist) * g_tile_size;
	y_inter = (g_resolution_y / 2) - (sp_size / 2);
	x_inter = (sp_angle - s_player.rotationangle) /\
	FOV_ANGLE * g_resolution_x + (g_resolution_x / 2 - sp_size / 2);
	render_spt(x_inter, y_inter, sp_size, i);
}

void		ft_sort_sprites(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_number_of_sprites)
	{
		j = 0;
		while (j < g_number_of_sprites - i - 1)
		{
			if (g_sprites[j].dist < g_sprites[j + 1].dist)
				swap(&g_sprites[j], &g_sprites[j + 1]);
			j++;
		}
		i++;
	}
}

void		draw_textures(void)
{
	int i;

	i = -1;
	while (++i < g_number_of_sprites)
		g_sprites[i].dist = ft_distancebetweenpoints((int)s_player.x,\
		(int)s_player.y
		, (int)g_sprites[i].x, (int)g_sprites[i].y);
	ft_sort_sprites();
	i = -1;
	while (++i < g_number_of_sprites)
		ft_sprites_draw(i);
}
