/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_read_mapandpaths_four.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 04:38:51 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/24 04:38:53 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			not_found(int i)
{
	if (i <= 1)
	{
		ft_error("\n* FLOOR COLORS CORDINATE  NOT FOUND *\n\nTRY : F 0,102,204\
		\nerrorF3");
	}
	if (i > 2)
	{
		ft_error("\n* INVALID CORDINATE COLORS OF FLOOR *\n\nTRY : F 0,102,204\
		\nerrorF4");
	}
}

char			**not_numerique(char **d, int j)
{
	int		i;

	i = 0;
	if (j-- != 2)
		ft_error("\n* INVALID CORDINATE COLORS OF FLOOR *\n\n(you should\
		seperate the numbers by ',' || you should enter just 3 numerique\
		cordinate)\nTRY : F 0,102,204\nerrorF5");
	d = ft_split(d[1], ',');
	while (d[++i])
		while (d[i][++j])
			if ((d[i][j] < '0') || (d[i][j] > '9'))
				ft_error("\n* INVALID CORDINATE COLORS OF FLOOR *\n\n(they\
				should be numerique)\nTRY : F 0,102,204\nerrorF6");
	i = -1;
	while (++i < 3)
		if (ft_atoi(d[i]) > 255 || ft_atoi(d[i]) < 0)
			ft_error("\n* INVALID CORDINATE COLORS OF FLOOR *\n\n(the values\
			should be beetwen { 0 <= x <= 255 } )\nTRY : F 0,102,204\n\
			errorF7");
	g_sol_couleur = rgb_to_int(ft_atoi((d[0])),\
	ft_atoi((d[1])), ft_atoi((d[2])));
	free_double_p(d);
	return (d);
}

void			cheak_line(char *line)
{
	if (line[0] == ' ' || !strncmp(line, " ", strlen(line)) || line == '\0')
		ft_error("\n* FLOOR COLORS CORDINATE  NOT FOUND *\n\n(no space or \
		return of line must be before)\n(no space must be before F ) \nTRY \
		: F 0,102,204\nerrorF1");
}

void			read_c_couleur_seconde(char **d)
{
	int		i;
	int		j;
	char	**s;

	i = -1;
	j = 0;
	while (d[1][++i])
		if (d[1][i] == ',')
			j++;
	if (j != 2)
		ft_error("\n* INVALID CORDINATE COLORS OF PLAFOND *\n\n(you\
		should seperate the numbers by ',' || you should enter just\
		3 numerique cordinate)\nTRY : C 0,102,204\nerrorC5");
	s = ft_split(d[1], ',');
	invalid_c(s, j);
	i = -1;
	while (++i < 3)
		if (ft_atoi(s[i]) > 255 || ft_atoi(s[i]) < 0)
			ft_error("\n* INVALID CORDINATE COLORS OF PLAFOND *\n\n(the values\
			should be beetwen { 0 <= x <= 255 } )\nTRY : F 0,102,204\nerrorC7");
	g_plafond_couleur = rgb_to_int(ft_atoi((s[0])),\
	ft_atoi((s[1])), ft_atoi((s[2])));
	free_double_p(s);
}
