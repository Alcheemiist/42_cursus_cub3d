/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_read_mapandpaths_three.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 04:14:54 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/24 04:14:56 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			skip_the_line(int fd, int index, char *line)
{
	int		ret;

	line = NULL;
	ret = 1;
	if (index == 50)
	{
		ret = get_next_line(fd, &line);
		if (strlen(line))
		{
			ft_error("\n* IT MUST BE AN EMPTY LINE BEETWEN PATHS\
			OF TEXTURES AND SPRITE TEXTURE PATH *\n\nerror50");
		}
	}
	else if (index == 60)
	{
		ret = get_next_line(fd, &line);
		if (strlen(line))
		{
			ft_error("\n* IT MUST BE AN EMPTY LINE BEETWEN COLORS\
			\nCORDINATE  AND THE MAP DESCRIPTION *\n\nerror60");
		}
	}
	free(line);
}

void			free_double_p(char **d)
{
	int j;

	j = 0;
	while (d[j])
	{
		free(d[j]);
		d[j] = NULL;
		j++;
	}
	free(d);
	d = NULL;
}

void			invalid_resolution(int i, int j, char **d)
{
	while (d[i][j])
	{
		if ((d[i][j] < '0') || (d[i][j] > '9'))
		{
			ft_error("\n* coordinates of resolution x or y are INVALID\
			*\n\nTRY : R 1000 1000\nerror03");
		}
		j++;
	}
}

void			get_r(char **d)
{
	if (!strcmp(d[0], "R"))
	{
		g_resolution_x = ft_atoi((d[1]));
		g_resolution_y = ft_atoi((d[2]));
	}
	else
	{
		ft_error("\n* resolution not Found *\n* INVALID FILE FORMAT *\n\n\
		error03");
	}
}
