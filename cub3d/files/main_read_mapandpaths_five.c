/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_read_mapandpaths_five.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 05:35:32 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/24 05:35:35 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			invalid_c(char **d, int j)
{
	int i;

	i = 0;
	j = 0;
	while (d[++i])
	{
		while (d[i][j])
		{
			if ((d[i][j] < '0') || (d[i][j] > '9'))
			{
				ft_error("\n* INVALID CORDINATE COLORS OF PLAFOND\
				*\n\n(they should be numerque)\nTRY : C 0,102,204\
				\nerrorC6");
			}
			j++;
		}
	}
}

void			read_all(int fd)
{
	char	*line;

	line = NULL;
	read_resolution(fd, line);
	read_no_path(fd, line);
	read_so_path(fd, line);
	read_we_path(fd, line);
	read_ea_path(fd, line);
	skip_the_line(fd, 50, line);
	read_s_path(fd, line);
	read_f_couleur(fd, line);
	read_c_couleur(fd, line);
	skip_the_line(fd, 60, line);
	free(line);
}

int				handle_player(char c, int g_player_number)
{
	if (c == 'N')
	{
		g_map[g_maps_x][g_maps_y++] = 8;
		g_deriction = 'N';
		g_player_number++;
	}
	else if (c == 'S')
	{
		g_map[g_maps_x][g_maps_y++] = 5;
		g_deriction = 'S';
		g_player_number++;
	}
	else if (c == 'E')
	{
		g_map[g_maps_x][g_maps_y++] = 6;
		g_deriction = 'E';
		g_player_number++;
	}
	else if (c == 'W')
	{
		g_map[g_maps_x][g_maps_y++] = 4;
		g_deriction = 'W';
		g_player_number++;
	}
	return (g_player_number);
}

int				handle(char c, int ip, int wight_t, int g_player_number)
{
	if (ip > wight_t)
		ip = (int)ip;
	if (c == '1')
		g_map[g_maps_x][g_maps_y++] = 1;
	else if (c == '0')
		g_map[g_maps_x][g_maps_y++] = 0;
	else if (c == '2')
	{
		g_map[g_maps_x][g_maps_y] = 2;
		g_sprites[g_number_of_sprites].y = g_maps_x;
		g_sprites[g_number_of_sprites++].x = g_maps_y++;
	}
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		g_player_number = handle_player(c, g_player_number);
	else if (c == ' ' || c == '\t' || c == '\n' || c == '\0' || c != '0')
		g_map[g_maps_x][g_maps_y++] = 3;
	else
		g_map[g_maps_x][g_maps_y++] = 7;
	return (g_player_number);
}
