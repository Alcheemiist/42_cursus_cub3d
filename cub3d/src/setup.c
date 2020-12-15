/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:27:39 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:27:42 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**param(char **prm)
{
	int		len;
	char	**col;

	len = ft_lentwop(prm);
	if (len >= 2)
	{
		ft_path(prm[1], 27, ' ', 0);
		if (((!ft_strncmp(prm[0], "NO", 3) || !ft_strncmp(prm[0], "SO", 3)
			|| !ft_strncmp(prm[0], "WE", 3) || !ft_strncmp(prm[0], "EA", 3)
			|| !ft_strncmp(prm[0], "S", 2)) && len == 2)
			|| (!ft_strncmp(prm[0], "R", 2) && len == 3))
			return (prm);
		if (!ft_strncmp(prm[0], "F", 2) || !ft_strncmp(prm[0], "C", 2))
		{
			col = ft_split(prm[1], ',');
			len = (len == 2) ? ft_lentwop(col) : 0;
			retfreetwo(col, 0);
			if (len == 3 && ft_lenfrom(',', prm[1]) == 2)
				return (prm);
			else
				ft_puterror("Number of color parametre invalid !");
		}
	}
	ft_puterror("Number of parametres invalid  !");
	return (NULL);
}

int		setup(char *file)
{
	int		fd;
	int		i;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0 || !validfile(file, "cub"))
		return (ft_puterror(ft_strjoin("No such file with name: ", file)));
	while ((i = get_next_line(fd, &line)) >= 0)
	{
		g_freetmp = line;
		line = ft_strtrim(line, " \t");
		free(g_freetmp);
		if (line[0] == 'R')
			i = ft_set_resolution(param(ft_split(line, ' ')));
		else if (checkforin(line[0], "NSWE"))
			i = texture(param(ft_split(ft_path(line, ' ', 27, 1), ' ')));
		else if (line[0] == 'F' || line[0] == 'C')
			i = ft_set_colors(line[0], param(ft_split(clear_color(line), ' ')));
		else if (line[0] == '1')
			i = ft_set_map(file, fd, line);
		else if (line[0])
			return (ft_puterror("caractere invalid!!"));
		if (retfree(line, NULL, i) <= 0)
			break ;
	}
	return ((i == -1) ? -1 : 1);
}
