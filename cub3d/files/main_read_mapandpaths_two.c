/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_read_mapandpaths_two.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 04:08:41 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/24 04:08:44 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			read_resolution(int fd, char *line)
{
	int		i;
	int		j;
	char	**d;

	d = NULL;
	i = 0;
	get_next_line(fd, &line);
	if (line[0] == ' ' || !strncmp(line, " ", strlen(line)) || line == '\0')
		ft_error("\n* Resolution NOT FOUND *\n\nTRY : R 1000 1000\nerror01");
	d = ft_split(line, ' ');
	while (d[i])
		i++;
	if (i > 3)
	{
		ft_error("\n* coordinates of resolutions are INVALID\
		*\n\nTRY : R 1000 1000\nerror02");
	}
	j = 0;
	i = 0;
	while (d[++i])
		invalid_resolution(i, j, d);
	get_r(d);
	free(line);
	free_double_p(d);
}

void			read_no_path(int fd, char *line)
{
	int		i;
	int		ret;
	char	**d;

	i = 0;
	ret = get_next_line(fd, &line);
	if (line[0] == ' ' || !strncmp(line, " ", strlen(line)) || line == '\0')
		ft_error("\n* NORD TEXTURE NOT FOUND *\n\n(no space or return of\
		line must be before)\nTRY : NO ./PATH \nerror04");
	d = ft_split(line, ' ');
	i = 0;
	while (d[i])
		i++;
	if (i <= 1)
		ft_error("\n* NO PATH OF NORD TEXTURE *\n\nTRY : NO ./PATH\nerror05");
	if (i > 2)
		ft_error("\n* INVALID CORDINATE NUMBER OF NORD TEXTURE *\n\nTRY : NO\
		./PATH\nerror06");
	if (!strcmp(d[0], "NO"))
		g_no_chemin = ft_strdup(d[1]);
	else
		ft_error("\n* PATH not Found *\n* INVALID FILE FORMAT *\nTRY : NO\
		./PATH\nerror07");
	free(line);
	free_double_p(d);
}

void			read_so_path(int fd, char *line)
{
	int		i;
	int		ret;
	char	**d;

	d = NULL;
	ret = get_next_line(fd, &line);
	if (line[0] == ' ' || !strncmp(line, " ", strlen(line)) || line == '\0')
		ft_error("\n* SOUTH TEXTURE NOT FOUND *\n\n(no space or return of line\
		must be before)\nTRY : SO ./PATH \nerror14");
	d = ft_split(line, ' ');
	i = 0;
	while (d[i])
		i++;
	if (i <= 1)
		ft_error("\n* NO PATH OF SOUTH TEXTURE *\n\nTRY : SO ./PATH\nerror15");
	if (i > 2)
		ft_error("\n* INVALID CORDINATE NUMBER OF SOUTH TEXTURE *\n\nTRY : SO\
		./PATH\nerror16");
	if (!strcmp(d[0], "SO"))
		g_so_chemin = ft_strdup(d[1]);
	else
		ft_error("\n* PATH not Found *\n* INVALID FILE FORMAT *\nTRY : SO\
		./PATH\nerror17");
	free(line);
	free_double_p(d);
}

void			read_we_path(int fd, char *line)
{
	int		ret;
	int		i;
	char	**d;

	i = 0;
	ret = get_next_line(fd, &line);
	if (line[0] == ' ' || !strncmp(line, " ", strlen(line)) || line == '\0')
		ft_error("\n* OUEST TEXTURE NOT FOUND *\n\n(no space or return of\
		line must be before)\nTRY : WE ./PATH \nerror24");
	d = ft_split(line, ' ');
	i = 0;
	while (d[i])
		i++;
	if (i <= 1)
		ft_error("\n* NO PATH OF OUEST TEXTURE *\n\nTRY : WE ./PATH\nerror25");
	if (i > 2)
		ft_error("\n* INVALID CORDINATE NUMBER OF OUEST TEXTURE *\n\nTRY :\
		WE ./PATH\nerror26");
	if (!strcmp(d[0], "WE"))
		g_we_chemin = ft_strdup(d[1]);
	else
		ft_error("\n* PATH not Found *\n* INVALID FILE FORMAT *\nTRY :\
		WE ./PATH\nerror27");
	free(line);
	free_double_p(d);
}

void			read_ea_path(int fd, char *line)
{
	int		i;
	int		ret;
	char	**d;

	i = 0;
	ret = get_next_line(fd, &line);
	if (line[0] == ' ' || !strncmp(line, " ", strlen(line)) || line == '\0')
		ft_error("\n* EAST TEXTURE NOT FOUND *\n\n(no space or return of\
		line must be before)\nTRY : EA ./PATH \nerror34");
	d = ft_split(line, ' ');
	i = 0;
	while (d[i])
		i++;
	if (i <= 1)
		ft_error("\n* NO PATH OF EAST TEXTURE *\n\nTRY : EA ./PATH\nerror35");
	if (i > 2)
		ft_error("\n* INVALID CORDINATE NUMBER OF EAST TEXTURE *\n\nTRY : EA\
		./PATH\nerror36");
	if (!strcmp(d[0], "EA"))
		g_ea_chemin = ft_strdup(d[1]);
	else
		ft_error("\n* PATH not Found *\n* INVALID FILE FORMAT *\nTRY : EA\
		./PATH\nerror37");
	free(line);
	free_double_p(d);
}
