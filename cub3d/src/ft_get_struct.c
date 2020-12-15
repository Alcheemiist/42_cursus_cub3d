/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:26:24 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:26:32 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_set_resolution(char **params)
{
	if (t_mlx.resul.width || t_mlx.resul.height)
		ft_puterror("Resolution duplicated");
	if (ft_isnumber(params[1]) && ft_isnumber(params[2]))
	{
		t_mlx.resul.width = ft_atoi(params[1]);
		t_mlx.resul.height = ft_atoi(params[2]);
		if (t_mlx.resul.width < 0 || t_mlx.resul.height < 0)
			ft_puterror("Resolution must be great than (1x1)");
		t_mlx.resul.width = (t_mlx.resul.width > 2560) ?
			2560 : t_mlx.resul.width;
		t_mlx.resul.height = (t_mlx.resul.height > 1440) ?
			1440 : t_mlx.resul.height;
		return (retfreetwo(params, 1));
	}
	ft_puterror("Resolution parametrs must be a numbers!");
	return (retfreetwo(params, -1));
}

int	texture(char **params)
{
	if (ft_strncmp(params[0], "NO", 3) == 0 && !t_full.no.path
		&& validfile(params[1], "xpm"))
		t_full.no.path = ft_strdup(params[1]);
	else if (ft_strncmp(params[0], "SO", 3) == 0 && !t_full.so.path
		&& validfile(params[1], "xpm"))
		t_full.so.path = ft_strdup(params[1]);
	else if (ft_strncmp(params[0], "WE", 3) == 0 && !t_full.we.path
		&& validfile(params[1], "xpm"))
		t_full.we.path = ft_strdup(params[1]);
	else if (ft_strncmp(params[0], "EA", 3) == 0 && !t_full.ea.path
		&& validfile(params[1], "xpm"))
		t_full.ea.path = ft_strdup(params[1]);
	else if (ft_strncmp(params[0], "S", 3) == 0 && !t_sprite.file_spr
		&& validfile(params[1], "xpm"))
		t_sprite.file_spr = ft_strdup(params[1]);
	else
	{
		return (retfreetwo(params,
			ft_puterror("Sum Texture Params are invalid or duplicated.")));
	}
	return (retfreetwo(params, 1));
}

int	ft_set_colors(char fp, char **params)
{
	g_freetmp = params;
	params = ft_split(params[1], ',');
	retfreetwo(g_freetmp, 0);
	if (ft_help(params[0]) && ft_help(params[1])
		&& ft_help(params[2]))
	{
		if (ft_toupper(fp) == 'F')
		{
			if (t_map.colorf > -1)
				ft_puterror("(F) Color Params are duplicated.");
			t_map.colorf = check_rgb(ft_atoi(params[0]),
						ft_atoi(params[1]), ft_atoi(params[2]));
			return (retfreetwo(params, 1));
		}
		else if (ft_toupper(fp) == 'C')
		{
			if (t_map.colorc > -1)
				ft_puterror("(C) Color Params are duplicated.");
			t_map.colorc = check_rgb(ft_atoi(params[0]),
						ft_atoi(params[1]), ft_atoi(params[2]));
			return (retfreetwo(params, 1));
		}
	}
	return (retfreetwo(params,
		ft_puterror("RGB color must be a numbers between 0 and 255!")));
}
