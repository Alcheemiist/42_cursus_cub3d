/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:28:27 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:28:31 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	normalizeang(float ang)
{
	if (ang < 0)
		ang += 360;
	if (ang >= 360)
		ang -= 360;
	t_ray.faceup = (ang >= 0 && ang <= 180) ? 0 : 1;
	t_ray.faceleft = (ang >= 90 && ang <= 270) ? 1 : 0;
	return (ang);
}

int		checkforwall(t_pos p, int h)
{
	int x;
	int y;

	p.y -= (h && t_ray.faceup) ? 1 : 0;
	p.x -= (!h && t_ray.faceleft) ? 1 : 0;
	x = p.x / TILE_SIZE;
	y = p.y / TILE_SIZE;
	if (t_map.map[y][x] == '1')
		return (1);
	return (0);
}

void	pixput(int x, int y, int color)
{
	int	*add;

	add = (int *)mlx_get_data_addr(t_mlx.img.img, &t_mlx.img.bits_per_pixel,
			&t_mlx.img.line_length, &t_mlx.img.endian);
	if (x < t_mlx.resul.width && y < t_mlx.resul.height && x >= 0 && y >= 0)
		add[y * (int)t_mlx.resul.width + x] = color;
}

void	ft_get_texture(void)
{
	if (!(t_full.no.img = mlx_xpm_file_to_image(t_mlx.mlx_ptr, t_full.no.path,
					&t_full.no.xpm.width, &t_full.no.xpm.height)))
		ft_puterror("NO Texture not found");
	t_full.no.addr = (int *)mlx_get_data_addr(t_full.no.img,
					&t_mlx.img.bits_per_pixel, &t_mlx.img.line_length,
					&t_mlx.img.endian);
	if (!(t_full.so.img = mlx_xpm_file_to_image(t_mlx.mlx_ptr, t_full.so.path,
					&t_full.so.xpm.width, &t_full.so.xpm.height)))
		ft_puterror("SO Texture not found");
	t_full.so.addr = (int *)mlx_get_data_addr(t_full.so.img,
					&t_mlx.img.bits_per_pixel, &t_mlx.img.line_length,
					&t_mlx.img.endian);
	if (!(t_full.we.img = mlx_xpm_file_to_image(t_mlx.mlx_ptr, t_full.we.path,
					&t_full.we.xpm.width, &t_full.we.xpm.height)))
		ft_puterror("WE Texture not found");
	t_full.we.addr = (int *)mlx_get_data_addr(t_full.we.img,
					&t_mlx.img.bits_per_pixel, &t_mlx.img.line_length,
					&t_mlx.img.endian);
	if (!(t_full.ea.img = mlx_xpm_file_to_image(t_mlx.mlx_ptr, t_full.ea.path,
					&t_full.ea.xpm.width, &t_full.ea.xpm.height)))
		ft_puterror("EA Texture not found");
	t_full.ea.addr = (int *)mlx_get_data_addr(t_full.ea.img,
					&t_mlx.img.bits_per_pixel, &t_mlx.img.line_length,
					&t_mlx.img.endian);
}

int		shadow(int color, float dest)
{
	int r;
	int g;
	int b;

	if ((dest / TILE_SIZE) > 1.7)
	{
		b = fmod(color, 256) / (dest / (TILE_SIZE * 1.7));
		g = fmod(color / 256, 256) / (dest / (TILE_SIZE * 1.7));
		r = fmod(color / pow(256, 2), 256) / (dest / (TILE_SIZE * 1.7));
		return (check_rgb(r, g, b));
	}
	return (color);
}
