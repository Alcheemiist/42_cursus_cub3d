/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprojection_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 02:17:20 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/24 02:17:23 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			render_render(int i, int y, int txt)
{
	render.distancefromtop = y + (render.wallstripheight\
	/ 2) - (s_tmp.window_height / 2);
	render.textureoffsety = render.distancefromtop *\
	((float)TEXTURE_HEIGHT\
	/ render.wallstripheight);
	render.texelcolor = g_textures[txt].data\
	[(TEXTURE_WIDTH * render.textureoffsety)\
	+ render.textureoffsetx];
	put_pixel(new_vector(i, y), render.texelcolor + render.c);
}

void			cast_init(void)
{
	s_tmp.foundhorzwallhit = FALSE;
	s_tmp.horzwallhitx = 0;
	s_tmp.horzwallhity = 0;
	s_tmp.horzwallcontent = 0;
	s_tmp.foundvertwallhit = FALSE;
	s_tmp.vertwallhitx = 0;
	s_tmp.vertwallhity = 0;
	s_tmp.vertwallcontent = 0;
	s_tmp.window_width = g_resolution_x;
	s_tmp.window_height = g_resolution_y;
}

void			put_pixel(t_vector a, int color)
{
	if (a.x < g_resolution_x && a.y < g_resolution_y && a.x >= 0 && a.y >= 0)
		g_p[(int)a.x + (int)a.y * (int)g_resolution_x] = color;
}

void			put_pixel_texture(t_vector a, int color, int j)
{
	if (a.x < TEXTURE_WIDTH && a.y < TEXTURE_HEIGHT && a.x >= 0 && a.y >= 0)
		g_ttextures[j][(int)a.x + (int)a.y * (int)TEXTURE_WIDTH] = color;
}

void			renderrays(void)
{
	int c;
	int i;

	i = 0;
	c = 1703425;
	while (i < g_num_rays)
	{
		draw_line(s_player.x * MINIMAP_SCALE, s_player.y * MINIMAP_SCALE,\
		s_rays[i].rayangle, s_rays[i].distance * MINIMAP_SCALE);
		i++;
	}
}
