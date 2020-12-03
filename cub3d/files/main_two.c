/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:59:12 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/24 16:59:18 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			check_check_argument_errors(int i, char **argv)
{
	char	**d;
	int		j;

	d = NULL;
	if (!strchr(argv[1], '.'))
		ft_error("\n* Invalid File Format *\t\n\n\
		Try : < yourfilename + '.cub' >\nerror2");
	d = ft_split(argv[1], '.');
	i = 0;
	while (d[i])
		i++;
	if (i == 1)
		ft_error("\n* Invalid File Format *\t\n\n\
		Try : < yourfilename + '.cub' >\nerror3");
	j = 0;
	while (d[1][j])
		j++;
	if (j < 3 || j > 3)
		ft_error("\n* Invalid File Format *\t\n\n\
			Try : < yourfilename + '.cub' >\nerror44");
	if (i == 2)
		if (strncmp(d[1], "cub", strlen(d[1])))
			ft_error("\n* Invalid File Format *\t\n\n\
			Try : < yourfilename + '.cub' >\nerror4");
	free_double_p(d);
}

void			check_argument_errors(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc < 2)
		ft_error("\n* FILE MAP NOT FOUND * \n\n\
		Try : < yourfilename + '.cub' >\nerror0");
	else if (argc > 2)
	{
		if (argc == 3)
			check_save(argv[2]);
		else
			ft_error("\n* Number of argument incorrect *\n\n\
		Try : < yourfilename + '.cub' >\nerror1");
	}
	else if (argc == 2)
	{
		check_check_argument_errors(i, argv);
	}
}

void			init_player(void)
{
	int i;

	i = 0;
	s_player.x = 0;
	s_player.y = 0;
	s_player.width = 1;
	s_player.height = 1;
	s_player.turndirection = 0;
	s_player.walkdirection = 0;
	s_player.rotationangle = PI / 2;
	s_player.walkspeed = 10;
	s_player.turnspeed = 5 * (PI / 180);
	while (i < g_number_of_sprites)
	{
		g_sprites[i].x = (g_sprites[i].x) * g_tile_size;
		g_sprites[i].y = (g_sprites[i].y) * g_tile_size;
		i++;
	}
}

float			ft_distancebetweenpoints(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}
