/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:27:49 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:27:52 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	sp_render(int x, int y, int sp_size, t_obj *obj)
{
	int color_sp;
	int i;
	int j;

	i = -1;
	while (++i < sp_size)
	{
		if ((x + i) < 0 || (x + i) > t_mlx.resul.width)
			continue;
		if (obj->dest > t_sprite.wall_dst[x + i] &&
			(obj->dest - t_sprite.wall_dst[x + i]) > 40)
			continue;
		j = -1;
		while (++j < sp_size)
		{
			if ((y + j) < 0 || (y + j) >= t_mlx.resul.height)
				continue;
			color_sp = obj->sp_img->addr[(int)((obj->sp_img->xpm.width
					* (j * obj->sp_img->xpm.height / sp_size))
					+ (i * obj->sp_img->xpm.width / sp_size))];
			if (color_sp != obj->sp_img->addr[0])
				pixput((x + i), (y + j),
						shadow(color_sp, obj->dest));
		}
	}
}

short	set_sprtex(t_obj *obj)
{
	if (!(obj->sp_img->img = mlx_xpm_file_to_image(t_mlx.mlx_ptr,
					obj->sp_img->path, &obj->sp_img->xpm.width,
					&obj->sp_img->xpm.height)))
		return (0);
	if (!(obj->sp_img->addr = (int *)mlx_get_data_addr(obj->sp_img->img,
					&t_mlx.img.bits_per_pixel, &t_mlx.img.line_length,
					&t_mlx.img.endian)))
		return (0);
	return (1);
}

void	ft_sprite(t_obj *obj)
{
	float sp_size;
	float x_inter;
	float y_inter;
	float sp_ang;

	sp_ang = atan2(obj->p.y - t_player.pos.y, obj->p.x - t_player.pos.x);
	while ((sp_ang - (t_player.ang * RAD)) > M_PI)
		sp_ang -= 2 * M_PI;
	while ((sp_ang - (t_player.ang * RAD)) < -M_PI)
		sp_ang += 2 * M_PI;
	sp_size = (t_mlx.resul.width / obj->dest) * TILE_SIZE;
	y_inter = (t_mlx.resul.height / 2) - (sp_size / 2);
	x_inter = (sp_ang - t_player.ang * RAD) * t_mlx.resul.width /
	(FOV * RAD) + (t_mlx.resul.width / 2 - sp_size / 2);
	if (set_sprtex(obj) == 1)
		sp_render(x_inter, y_inter, sp_size, obj);
	else
		ft_puterror("Sprite textur not found!");
}

void	print_sprite(void)
{
	t_obj *ob;

	setdests();
	sortlst(&t_sprite.lstobj);
	ob = t_sprite.lstobj;
	while (ob)
	{
		ft_sprite(ob);
		ob = ob->next;
	}
}

void	set_sprite(int x, int y)
{
	char	*tex;

	tex = NULL;
	if (t_map.map[y][x] == '2' && t_sprite.file_spr)
		tex = t_sprite.file_spr;
	else
		ft_puterror("Please Set Sprites");
	x = (x * TILE_SIZE) + (TILE_SIZE / 2);
	y = (y * TILE_SIZE) + (TILE_SIZE / 2);
	ft_lstaddobj(&t_sprite.lstobj, ft_lstnewobj(x, y, 0, tex));
}
