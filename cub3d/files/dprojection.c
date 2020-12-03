/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_PROJECTION.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 03:12:54 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/22 03:13:01 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		init_generat(int i)
{
	render.perpdistance = s_rays[i].distance * cos(\
	s_rays[i].rayangle - s_player.rotationangle);
	render.distanceprojplane = (s_tmp.window_width / 2)\
	/ tan(FOV_ANGLE / 2);
	render.projectedwallheight = (TILE_SIZE / 2 /\
	render.perpdistance) * render.distanceprojplane;
	render.wallstripheight = (int)render.projectedwallheight;
	render.walltoppixel = (s_tmp.window_height / 2) - (\
	render.wallstripheight / 2);
	render.walltoppixel = render.walltoppixel < 0 ? 0\
	: render.walltoppixel;
	render.wallbottompixel = (s_tmp.window_height / 2) + (\
	render.wallstripheight / 2);
	render.wallbottompixel = render.wallbottompixel\
	> s_tmp.window_height ?\
	s_tmp.window_height : render.wallbottompixel;
	render.perpdistance -= 700;
	render.c = render.perpdistance > 100 ? 1000 : 0;
}

void		plafond_g(int y, int i)
{
	while (y < s_tmp.window_height)
	{
		put_pixel(new_vector(i, y), g_plafond_couleur);
		y++;
	}
}

void		txt_choose(int i)
{
	if (s_rays[i].washitvertical)
		render.textureoffsetx = (int)s_rays[i].wallhity\
		% TEXTURE_HEIGHT;
	else
		render.textureoffsetx = (int)s_rays[i].wallhitx\
		% TEXTURE_WIDTH;
}

void		generate3dprojection(void)
{
	int		txt;
	int		i;
	int		y;

	i = -1;
	txt = 0;
	while (++i < g_num_rays)
	{
		init_generat(i);
		y = -1;
		while (++y < render.walltoppixel)
			put_pixel(new_vector(i, y), g_sol_couleur);
		txt = texture_num(i);
		txt_choose(i);
		y = render.walltoppixel;
		while (y <= render.wallbottompixel)
		{
			render_render(i, y, txt);
			y++;
		}
		y = render.wallbottompixel;
		plafond_g(y, i);
	}
}
