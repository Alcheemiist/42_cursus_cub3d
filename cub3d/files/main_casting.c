/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 03:14:41 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/22 03:14:44 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			get_angle(float rayangle)
{
	rayangle = normalizeangle(rayangle);
	s_tmp.israyfacingdown = rayangle > 0 && rayangle < PI;
	s_tmp.israyfacinup = !s_tmp.israyfacingdown;
	s_tmp.israyfacinright = rayangle < 0.5 * PI || rayangle > 1.5 * PI;
	s_tmp.israyfacinleft = !s_tmp.israyfacinright;
}

void			got_destance(void)
{
	s_tmp.horzhitdistance = s_tmp.foundhorzwallhit ?\
	ft_distancebetweenpoints(s_player.x, s_player.y,\
	s_tmp.horzwallhitx, s_tmp.horzwallhity) : __FLT_MAX__;
	s_tmp.verthitdistance = s_tmp.foundvertwallhit ?\
	ft_distancebetweenpoints(s_player.x, s_player.y,\
	s_tmp.vertwallhitx, s_tmp.vertwallhity) : __FLT_MAX__;
}

void			do_cast(float rayangle)
{
	cast_init();
	get_angle(rayangle);
	hor_cast(rayangle);
	ver_cast(rayangle);
	got_destance();
}

int				ray_cast(float rayangle, int stripid)
{
	do_cast(rayangle);
	if (s_tmp.verthitdistance < s_tmp.horzhitdistance)
	{
		s_rays[stripid].distance = s_tmp.verthitdistance;
		s_rays[stripid].wallhitx = s_tmp.vertwallhitx;
		s_rays[stripid].wallhity = s_tmp.vertwallhity;
		s_rays[stripid].wallhitcontent = s_tmp.vertwallcontent;
		s_rays[stripid].washitvertical = TRUE;
	}
	else
	{
		s_rays[stripid].distance = s_tmp.horzhitdistance;
		s_rays[stripid].wallhitx = s_tmp.horzwallhitx;
		s_rays[stripid].wallhity = s_tmp.horzwallhity;
		s_rays[stripid].wallhitcontent = s_tmp.horzwallcontent;
		s_rays[stripid].washitvertical = FALSE;
	}
	s_rays[stripid].rayangle = rayangle;
	s_rays[stripid].israyfacingdown = s_tmp.israyfacingdown;
	s_rays[stripid].israyfacingup = s_tmp.israyfacinup;
	s_rays[stripid].israyfacingleft = s_tmp.israyfacinleft;
	s_rays[stripid].israyfacingright = s_tmp.israyfacinright;
	return (s_rays[stripid].distance);
}

void			castallrays(void)
{
	float	rayangle;
	int		stripid;

	rayangle = s_player.rotationangle - (FOV_ANGLE / 2);
	stripid = 0;
	while (stripid < g_num_rays)
	{
		rayangle = normalizeangle(rayangle);
		ray_cast(rayangle, stripid);
		s_rays[stripid].rayangle = rayangle;
		rayangle += FOV_ANGLE / g_num_rays;
		stripid++;
	}
}
