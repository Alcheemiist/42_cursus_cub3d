/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_functions_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 03:52:16 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/24 03:52:18 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		draw_ssprite(int i, int j, int block_size)
{
	draw_square(i, j, block_size, 0);
	draw_circle((j + 0.5) * block_size, (i + 0.5) * block_size,\
	25 * MINIMAP_SCALE, rgb_to_int(255, 100, 0));
}

void		draw_square(int row, int col, int grid_size, int color)
{
	double	y;
	double	max_y;
	double	max_x;
	double	x;

	max_x = col * grid_size + grid_size;
	max_y = row * grid_size + grid_size;
	y = row * grid_size;
	while (y < max_y)
	{
		x = grid_size * col;
		while (x < max_x)
			put_pixel(new_vector(x++, y), color);
		y++;
	}
}

void		draw_line(int a, int b, float angle, int d)
{
	int		i;
	int		c;

	c = 1703425;
	i = 0;
	if (d == 0)
		d = 50;
	while (i <= d)
	{
		a = (s_player.x * MINIMAP_SCALE) + cos(angle) * i;
		b = (s_player.y * MINIMAP_SCALE) + sin(angle) * i;
		put_pixel(new_vector(a, b), c);
		i++;
	}
}

void		draw_splayer(int i, int j)
{
	if (g_map[i][j] == 8)
		assigne('N', i, j);
	else if (g_map[i][j] == 5)
		assigne('S', i, j);
	else if (g_map[i][j] == 6)
		assigne('E', i, j);
	else if (g_map[i][j] == 4)
		assigne('W', i, j);
}
