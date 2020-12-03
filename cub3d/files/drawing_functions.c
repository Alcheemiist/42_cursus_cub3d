/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 03:13:54 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/22 03:13:57 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		assigne(char c, int i, int j)
{
	g_deriction = c;
	g_map[i][j] = 0;
	s_player.x = (int)(j * g_tile_size);
	s_player.y = (int)(i * g_tile_size);
	g_bousole.x = i;
	g_bousole.y = j;
}

void		draw(int i, int j, int block_size)
{
	if (g_map[i][j] == 1)
		draw_square(i, j, 0, 0xFFFFFF);
	else if (g_map[i][j] == (0))
		draw_square(i, j, block_size, 0x01000000);
	else if (g_map[i][j] == (2))
		draw_ssprite(i, j, block_size);
	else if (g_map[i][j] == 8 || g_map[i][j] == 5 ||\
	g_map[i][j] == 6 || g_map[i][j] == 4)
		draw_splayer(i, j);
	else if (g_map[i][j] == ' ')
		draw_square(i, j, 0, 0xFFFFFF);
}

void		draw_mini_map(void)
{
	int i;
	int j;
	int block_size;

	block_size = g_tile_size * MINIMAP_SCALE;
	i = 0;
	while (i < g_high)
	{
		j = 0;
		while (j < g_wight)
		{
			draw(i, j, block_size);
			j++;
		}
		i++;
	}
}

void		draw_circle(int a, int b, int d, int couleur)
{
	int		r;
	int		x;
	int		height;
	int		y;

	r = 0;
	x = -r;
	r = d / 2;
	while (x < r)
	{
		height = (int)sqrt(r * r - x * x);
		y = -height;
		while (y < height)
		{
			put_pixel(new_vector(x + a, y + b), couleur);
			y++;
		}
		x++;
	}
}

void		draw_cub(int i, int y, int couleur)
{
	int		max_x;
	int		max_y;

	max_x = i + (g_tile_size);
	max_y = y + (g_tile_size);
	while (i < (max_x))
	{
		y = max_y - g_tile_size;
		while (y < (max_y))
		{
			mlx_pixel_put(g_mlx_ptr, g_win_ptr, i, y, couleur);
			y++;
		}
		i++;
	}
}
