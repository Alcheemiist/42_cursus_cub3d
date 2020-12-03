/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_castin_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 01:53:26 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/24 01:53:31 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			hor_cast_init(float rayangle)
{
	s_tmp.yintercept = floor(s_player.y / g_tile_size) * g_tile_size;
	s_tmp.yintercept += s_tmp.israyfacingdown ? g_tile_size : -0.0001;
	s_tmp.xintercept = s_player.x + (s_tmp.yintercept - s_player.y)\
	/ tan(rayangle);
	s_tmp.ystep = g_tile_size;
	s_tmp.ystep *= s_tmp.israyfacinup ? -1 : 1;
	s_tmp.xstep = g_tile_size / tan(rayangle);
	s_tmp.xstep *= (s_tmp.israyfacinleft && s_tmp.xstep > 0) ? -1 : 1;
	s_tmp.xstep *= (s_tmp.israyfacinright && s_tmp.xstep < 0) ? -1 : 1;
	s_tmp.nexthorztouchx = s_tmp.xintercept;
	s_tmp.nexthorztouchy = s_tmp.yintercept;
}

void			hor_cast(float rayangle)
{
	hor_cast_init(rayangle);
	while (s_tmp.nexthorztouchx >= 0 && s_tmp.nexthorztouchx <=\
	s_tmp.window_width\
	&& s_tmp.nexthorztouchy >= 0 && s_tmp.nexthorztouchy <=\
	s_tmp.window_height)
	{
		s_tmp.xtocheck = s_tmp.nexthorztouchx;
		s_tmp.ytocheck = s_tmp.nexthorztouchy;
		if (haswallat((int)s_tmp.xtocheck, (int)s_tmp.ytocheck))
		{
			s_tmp.horzwallhitx = s_tmp.nexthorztouchx;
			s_tmp.horzwallhity = s_tmp.nexthorztouchy;
			s_tmp.horzwallcontent = g_map[(int)floor(s_tmp.ytocheck /\
			g_tile_size)][(int)floor(s_tmp.xtocheck / g_tile_size)];
			s_tmp.foundhorzwallhit = TRUE;
			break ;
		}
		else
		{
			s_tmp.nexthorztouchx += s_tmp.xstep;
			s_tmp.nexthorztouchy += s_tmp.ystep;
		}
	}
}

void			ver_cast_init(float rayangle)
{
	s_tmp.xintercept = floor(s_player.x / g_tile_size) * g_tile_size;
	s_tmp.xintercept += s_tmp.israyfacinright ? g_tile_size : -0.0001;
	s_tmp.yintercept = s_player.y + (s_tmp.xintercept - s_player.x)\
	* tan(rayangle);
	s_tmp.xstep = g_tile_size;
	s_tmp.xstep *= s_tmp.israyfacinleft ? -1 : 1;
	s_tmp.ystep = g_tile_size * tan(rayangle);
	s_tmp.ystep *= (s_tmp.israyfacinup && s_tmp.ystep > 0) ? -1 : 1;
	s_tmp.ystep *= (s_tmp.israyfacingdown && s_tmp.ystep < 0) ? -1 : 1;
	s_tmp.nextverttouchx = s_tmp.xintercept;
	s_tmp.nextverttouchy = s_tmp.yintercept;
}

void			ver_cast(float rayangle)
{
	ver_cast_init(rayangle);
	while (s_tmp.nextverttouchx >= 0 && s_tmp.nextverttouchx <=\
	s_tmp.window_width && s_tmp.nextverttouchy >= 0 &&\
	s_tmp.nextverttouchy <= s_tmp.window_height)
	{
		s_tmp.xtocheck = s_tmp.nextverttouchx + (s_tmp.israyfacinleft ? -1 : 0);
		s_tmp.ytocheck = s_tmp.nextverttouchy;
		if (haswallat((int)s_tmp.xtocheck, (int)s_tmp.ytocheck))
		{
			s_tmp.vertwallhitx = s_tmp.nextverttouchx;
			s_tmp.vertwallhity = s_tmp.nextverttouchy;
			s_tmp.vertwallcontent = g_map[(int)floor(s_tmp.ytocheck /\
			g_tile_size)][(int)floor(s_tmp.xtocheck / g_tile_size)];
			s_tmp.foundvertwallhit = TRUE;
			break ;
		}
		else
		{
			s_tmp.nextverttouchx += s_tmp.xstep;
			s_tmp.nextverttouchy += s_tmp.ystep;
		}
	}
}
