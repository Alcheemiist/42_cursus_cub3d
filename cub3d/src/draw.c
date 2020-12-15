/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:25:58 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:26:02 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	get_col(float stp, t_textr img, float wallheight)
{
	int deref;

	deref = (int)(t_full.offset + ((int)(stp) * img.xpm.width));
	if (deref >= 0 && deref < img.xpm.width * img.xpm.height)
		t_full.color = img.addr[deref];
	return (img.xpm.height / wallheight);
}

int		ft_get_text_color(float *stp, float wallheight)
{
	if (t_ray.faceup && t_ray.horay)
		*stp += get_col(*stp, t_full.no, wallheight);
	if (!t_ray.faceup && t_ray.horay)
		*stp += get_col(*stp, t_full.so, wallheight);
	if (!t_ray.faceleft && !t_ray.horay)
		*stp += get_col(*stp, t_full.ea, wallheight);
	if (t_ray.faceleft && !t_ray.horay)
		*stp += get_col(*stp, t_full.we, wallheight);
	return (t_full.color);
}

void	printwall(float dst, int px)
{
	float	wallheight;
	int		i;
	int		h;
	float	stp;

	if (t_map.colorc == -1 || t_map.colorf == -1)
		ft_puterror("Please set (F,C) colors");
	dst *= cos((t_player.ang - t_ray.ang) * RAD);
	wallheight = (TILE_SIZE / dst) * ((t_mlx.resul.width / 2) /
			(tan((FOV / 2) * RAD)));
	h = (t_mlx.resul.height / 2);
	i = -1;
	stp = 0;
	while (++i < (h - (wallheight / 2)))
		pixput(px, i, t_map.colorc);
	i = (h - (wallheight / 2));
	while (i++ < (h + (wallheight / 2)))
		pixput(px, i, shadow(ft_get_text_color(&stp, wallheight), dst));
	i = (h + (wallheight / 2));
	while (i++ < t_mlx.resul.height)
		pixput(px, i, t_map.colorf);
}

void	setwalldst(int dest, int mpx)
{
	t_sprite.wall_dst[mpx] = dest;
	if (t_sprite.wall_dst[mpx - 1] > t_sprite.wall_dst[mpx]
	&& t_sprite.wall_dst[mpx - 1] > t_sprite.wall_dst[mpx - 2])
		printwall(dest, mpx - 1);
}

void	drawmap(void)
{
	float	angle;
	float	dst;
	int		px;

	if (!t_player.dir)
		ft_puterror("Player not found :(");
	px = 0;
	angle = -(FOV / 2);
	while (angle < (FOV / 2))
	{
		if ((dst = get_dest(angle)) == 1)
			dst = 1;
		t_sprite.wall_dst[px] = dst;
		printwall(dst, px);
		setwalldst(dst, px);
		px++;
		angle += (FOV / t_mlx.resul.width);
	}
	t_sprite.wall_dst[px] = '\0';
	if (t_sprite.lstobj != NULL)
		print_sprite();
}
