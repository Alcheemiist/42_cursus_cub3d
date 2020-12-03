/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TECHNICAL_FUNCTIONS.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 03:13:13 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/22 03:13:31 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			hassprite(int x, int y)
{
	int		i;
	int		d;

	if (x <= 0 || x >= g_resolution_x || y <= 0 || y >= g_resolution_y)
		return (TRUE);
	i = 0;
	while (i < g_number_of_sprites)
	{
		d = ft_distancebetweenpoints(g_sprites[i].x, g_sprites[i].y, x, y);
		if (d < 35)
			return (1);
		else
			i++;
	}
	return (FALSE);
}

int			haswallat(int x, int y)
{
	int		mapgridindexx;
	int		mapgridindexy;

	if (x <= 0 || x >= g_resolution_x || y <= 0 || y >= g_resolution_y)
		return (TRUE);
	mapgridindexx = floor(x / g_tile_size);
	mapgridindexy = floor(y / g_tile_size);
	return (g_map[mapgridindexy][mapgridindexx] == 1);
}

int			rgb_to_int(int r, int g, int b)
{
	return (r * 256 * 256 + g * 256 + b);
}

void		check_save(char *str)
{
	if (strcmp("--save", str))
		ft_error("\n* Number of argument incorrect *\n\
		if u wanna take a screenshoot \n Try : '--save' \nerror'save'");
}

void		clearcolorbuffer(int color)
{
	int		x;
	int		y;

	x = 0;
	while (x < g_resolution_x)
	{
		y = 0;
		while (y < g_resolution_y)
		{
			g_p[(g_resolution_x * y) + x] = color;
			y++;
		}
		x++;
	}
}
