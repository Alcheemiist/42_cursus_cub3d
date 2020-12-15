/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:27:00 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:27:04 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		keypressed(int key)
{
	if (key == 259)
		help_keypress();
	if (key == 13)
		t_key.up = 1;
	if (key == 1)
		t_key.down = 1;
	if (key == 0)
		t_key.left = 1;
	if (key == 2)
		t_key.right = 1;
	if (key == 123)
		t_key.fcleft = 1;
	if (key == 124)
		t_key.fcright = 1;
	if (key == 53)
		t_key.esc = 1;
	if (key == 259)
		help_keypress();
	return (0);
}

int		keyreleased(int key)
{
	if (key == 259)
		help_keypress();
	if (key == 13)
		t_key.up = 0;
	if (key == 1)
		t_key.down = 0;
	if (key == 0)
		t_key.left = 0;
	if (key == 2)
		t_key.right = 0;
	if (key == 123)
		t_key.fcleft = 0;
	if (key == 124)
		t_key.fcright = 0;
	if (key == 53)
		t_key.esc = 0;
	return (0);
}

int		check_for_step(void)
{
	t_pos	p;
	char	c;
	int		an;

	p.x = t_player.pos.x;
	p.y = t_player.pos.y;
	if (t_key.down)
	{
		p.x -= cos(t_player.ang * RAD) * (STEP * 5);
		p.y -= sin(t_player.ang * RAD) * (STEP * 5);
	}
	if (t_key.up || t_key.right || t_key.left)
	{
		an = (t_key.right) ? 90 : 0;
		an = (t_key.left) ? -90 : an;
		p.x += cos((t_player.ang + an) * RAD) * (STEP * 5);
		p.y += sin((t_player.ang + an) * RAD) * (STEP * 5);
	}
	c = t_map.map[(int)(p.y / TILE_SIZE)][(int)(p.x / TILE_SIZE)];
	if (c != '1' && c != '2' && c != ' ')
		return (1);
	return (0);
}

void	ft_handl_key(void)
{
	int an;

	if (check_for_step())
	{
		if (t_key.down)
		{
			t_player.pos.x -= cos(t_player.ang * RAD) * STEP;
			t_player.pos.y -= sin(t_player.ang * RAD) * STEP;
		}
		if (t_key.up || t_key.right || t_key.left)
		{
			an = (t_key.right) ? 90 : 0;
			an = (t_key.left) ? -90 : an;
			t_player.pos.x += cos((t_player.ang + an) * RAD) * STEP;
			t_player.pos.y += sin((t_player.ang + an) * RAD) * STEP;
		}
	}
	if (t_key.fcright)
		t_player.ang = normalizeang(t_player.ang + STEP / 2);
	if (t_key.fcleft)
		t_player.ang = normalizeang(t_player.ang - STEP / 2);
	if (t_key.esc)
		quit();
}

int		update(void)
{
	mlx_destroy_image(t_mlx.mlx_ptr, t_mlx.img.img);
	mlx_clear_window(t_mlx.mlx_ptr, t_mlx.win_ptr);
	t_mlx.img.img = mlx_new_image(t_mlx.mlx_ptr,
			t_mlx.resul.width, t_mlx.resul.height);
	ft_handl_key();
	drawmap();
	mlx_put_image_to_window(t_mlx.mlx_ptr, t_mlx.win_ptr, t_mlx.img.img, 0, 0);
	return (0);
}
