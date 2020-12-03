/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_functions_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 03:27:11 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/24 03:27:16 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			texture_num(int i)
{
	if (s_rays[i].israyfacingup && !s_rays[i].washitvertical)
		return (0);
	if (s_rays[i].israyfacingdown && !s_rays[i].washitvertical)
		return (1);
	if (s_rays[i].israyfacingright && s_rays[i].washitvertical)
		return (3);
	if (s_rays[i].israyfacingleft && s_rays[i].washitvertical)
		return (2);
	return (0);
}

void		check_for_file(t_string file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		puts(file_name);
		printf("INVALID_FILE_NAME, FAIL\n");
		exit(1);
	}
}

t_image		load_image(int i, t_string path)
{
	printf("\033[0;35m");
	printf("%s", path);
	printf("\033[1;32m");
	printf("\t\t -> Read successfully\n");
	check_for_file(path);
	g_textures[i].img = mlx_xpm_file_to_image(g_mlx_ptr, path,\
	&g_textures[i].width, &g_textures[i].height);
	g_textures[i].data = (int *)mlx_get_data_addr(g_textures[i].img,
	&g_textures[i].bits_per_pixel,
	&g_textures[i].bits_per_pixel, &g_textures[i].endian);
	return (g_textures[i]);
}

void		load_texture(t_string line, int index)
{
	t_string	path;

	path = ft_strjoin(line, ".xpm");
	load_image(index, path);
	free(path);
}

void		load_textures_setup(void)
{
	int		i;
	char	**str;

	i = -1;
	str = malloc(sizeof(char *) * 10);
	str[0] = ft_strdup(g_no_chemin);
	str[1] = ft_strdup(g_so_chemin);
	str[2] = ft_strdup(g_we_chemin);
	str[3] = ft_strdup(g_ea_chemin);
	str[4] = ft_strdup(g_s_chemin);
	while (++i <= 4)
		load_texture(str[i], i);
	free(str[0]);
	free(str[1]);
	free(str[2]);
	free(str[3]);
	free(str[4]);
	free(str);
	free(g_no_chemin);
	free(g_so_chemin);
	free(g_we_chemin);
	free(g_ea_chemin);
	free(g_s_chemin);
}
