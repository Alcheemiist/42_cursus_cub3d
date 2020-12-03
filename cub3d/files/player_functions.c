/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 03:15:15 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/22 03:15:18 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		key_pressed(int key)
{
	if (key == KEY_UP)
		s_player.walkdirection = 1;
	else if (key == KEY_DOWN)
		s_player.walkdirection = -1;
	else if (key == KEY_CAMERA_RIGHT)
		s_player.turndirection = -1;
	else if (key == KEY_CAMERA_LEFT)
		s_player.turndirection = +1;
	if (key == KEY_RIGHT)
		s_player.moveright = 1;
	if (key == KEY_LEFT)
		s_player.moveleft = 1;
}

int			keyrelease(int key)
{
	if (key == KEY_UP)
		s_player.walkdirection = 0;
	else if (key == KEY_DOWN)
		s_player.walkdirection = 0;
	else if (key == KEY_CAMERA_RIGHT)
		s_player.turndirection = 0;
	else if (key == KEY_CAMERA_LEFT)
		s_player.turndirection = 0;
	if (key == KEY_RIGHT)
		s_player.moveright = 0;
	if (key == KEY_LEFT)
		s_player.moveleft = 0;
	return (0);
}

void		end_function(int movestep, int newplayerx, int newplayery)
{
	if (s_player.moveleft)
	{
		s_player.walkdirection = 1;
		movestep = s_player.walkdirection * s_player.walkspeed / 2;
		newplayerx = s_player.x + cos(s_player.rotationangle\
		+ 90 * (M_PI / 180)) * (movestep);
		newplayery = s_player.y + sin(s_player.rotationangle\
		+ 90 * (M_PI / 180)) * (movestep);
		s_player.walkdirection = 0;
	}
	if (s_player.moveright)
	{
		s_player.walkdirection = 1;
		movestep = s_player.walkdirection * s_player.walkspeed / 2;
		newplayerx = s_player.x + cos(s_player.rotationangle\
		- 90 * (M_PI / 180)) * (movestep);
		newplayery = s_player.y + sin(s_player.rotationangle\
		- 90 * (M_PI / 180)) * (movestep);
		s_player.walkdirection = 0;
	}
	if (!haswallat(newplayerx, newplayery))
	{
		s_player.x = newplayerx;
		s_player.y = newplayery;
	}
}

void		action_player(void)
{
	int		newplayerx;
	int		newplayery;
	int		movestep;

	s_player.rotationangle += s_player.turndirection * s_player.turnspeed;
	movestep = s_player.walkdirection * s_player.walkspeed;
	newplayerx = s_player.x + cos(s_player.rotationangle) * (movestep);
	newplayery = s_player.y + sin(s_player.rotationangle) * (movestep);
	end_function(movestep, newplayerx, newplayery);
}

void		draw_the_player(void)
{
	int d;
	int c;

	c = 0xff0000;
	d = 40 * MINIMAP_SCALE;
	draw_circle(s_player.x * MINIMAP_SCALE, s_player.y * MINIMAP_SCALE, d, c);
	draw_line(s_player.x * MINIMAP_SCALE, s_player.y * MINIMAP_SCALE,\
	s_player.rotationangle, 50 * MINIMAP_SCALE);
}
