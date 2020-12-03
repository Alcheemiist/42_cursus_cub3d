/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_read_mapANDpaths.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 03:14:55 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/22 03:15:00 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			read_s_path(int fd, char *line)
{
	int		i;
	int		ret;
	char	**d;

	ret = get_next_line(fd, &line);
	if (line[0] == ' ' || !strncmp(line, " ", strlen(line)) || line == '\0')
		ft_error("\n* SPRITE TEXTURE NOT FOUND *\n\n ( 1 empty line must\
		be before )\nTRY : S ./PATH \nerror44");
	d = ft_split(line, ' ');
	i = 0;
	while (d[i])
		i++;
	if (i <= 1)
		ft_error("\n* NO PATH OF SPRITE TEXTURE *\n\nTRY : S ./PATH\nerror45");
	if (i > 2)
		ft_error("\n* INVALID CORDINATE NUMBER OF SPRITE TEXTURE *\n\nTRY :S\
		./PATH\nerror46");
	if (!strcmp(d[0], "S"))
		g_s_chemin = ft_strdup(d[1]);
	else
		ft_error("\n* PATH not Found *\n* INVALID FILE FORMAT *\nTRY : S\
		./PATH\nerror47");
	free(line);
	free_double_p(d);
}

void			read_f_couleur(int fd, char *line)
{
	int		i;
	int		j;
	char	**d;

	d = NULL;
	get_next_line(fd, &line);
	cheak_line((line));
	d = ft_split((line), ' ');
	if (strcmp(d[0], "F"))
		ft_error("\n* FLOOR COLORS CORDINATE  NOT FOUND *\n\n(no space must\
		be before F && it should start with F ) \nTRY : F 0,102,204\nerrorF2");
	i = 0;
	while (d[i])
		i++;
	not_found(i);
	i = -1;
	j = 0;
	while (d[1][++i])
		if (d[1][i] == ',')
			j++;
	not_numerique(d, j);
	free(line);
	free_double_p(d);
}

void			read_c_couleur(int fd, char *line)
{
	int		i;
	char	**d;

	d = NULL;
	get_next_line(fd, &line);
	if (line[0] == ' ' || !strncmp(line, " ", strlen(line)) || line == '\0')
		ft_error("\n* PLAFOND COLORS CORDINATE  NOT FOUND *\n\n( 1 empty\
		line must be before )\n(no space must be before C ) \nTRY : C 0,\
		102,204\nerrorC1");
	d = ft_split(line, ' ');
	if (strcmp(d[0], "C"))
		ft_error("\n* PLAFOND COLORS CORDINATE  NOT FOUND *\n\n(no space must\
		be before C && it should start with C ) \nTRY : C 0,102,204 \nerrorC2");
	i = 0;
	while (d[i])
		i++;
	if (i <= 1)
		ft_error("\n* PLAFONDCOLORS CORDINATE  NOT FOUND *\n\nTRY :\
		C 0,102,204\nerrorC3");
	if (i > 2)
		ft_error("\n* INVALID CORDINATE COLORS OF PLAFOND *\n\nTRY :\
		C 0,102,204\nerrorC4");
	read_c_couleur_seconde(d);
	free_double_p(d);
	free(line);
}

int				read_boucle(int ret, int uy, int fd)
{
	char	*line;
	int		ip;
	int		wight_t;
	int		i;

	if (ret == -1 || ret == 0)
		return (-1);
	ret = get_next_line(fd, &line);
	ft_memcpy(g_t[uy], line, strlen(line));
	i = 0;
	while (line[i])
		if (!is_valid(line[i++]))
		{
			ft_error("INVALID MAP\nerror909");
		}
	(g_wight <= (int)strlen(line)) ? g_wight = strlen(line) : g_wight;
	wight_t = (int)strlen(line);
	g_high++;
	g_maps_y = 0;
	ip = -1;
	while (++ip < g_wight)
		g_player_number = handle(line[ip], ip, wight_t, g_player_number);
	free(line);
	return (ret);
}

int				read_map(char **argv)
{
	int		ret;
	int		fd;
	int		uy;

	uy = 0;
	ret = 1;
	g_high = 0;
	g_wight = 0;
	if (!(fd = open(argv[1], O_RDONLY)))
		ft_error("\n * file map mot opened *\n\nerror404");
	read_all(fd);
	g_maps_x = 0;
	g_number_of_sprites = 0;
	while (ret)
	{
		if ((ret = read_boucle(ret, g_maps_x, fd)) == -1)
			return (-1);
		g_maps_x++;
	}
	if (g_player_number >= 2)
		ft_error("*{ it must be just one player position }*\n||OR TRY AGAIN\
		:>> THE TEXTURES WERE'NT READ CORRECTLY||\nerrorP0");
	else if (g_player_number == 0)
		ft_error("it must be at least one player position\nerrorP1");
	return (1);
}
