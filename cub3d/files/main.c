/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 02:12:48 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/22 03:14:16 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	config_init(void)
{
	int width;
	int l;

	if ((g_resolution_x % 2))
		g_resolution_x--;
	if (g_resolution_x > MAX_WIDTH)
		g_resolution_x = MAX_WIDTH;
	else if (g_resolution_x < MIN_WIDTH)
		g_resolution_x = MIN_WIDTH;
	if (g_resolution_y > MAX_HIGHT)
		g_resolution_y = MAX_HIGHT;
	else if (g_resolution_y < MIN_HIGHT)
		g_resolution_y = MIN_HIGHT;
	width = (g_resolution_x > g_resolution_y) ? g_resolution_x : g_resolution_y;
	l = (g_wight > g_high) ? g_wight : g_high;
	g_tile_size = (int)(width / l);
	g_ray = (float *)malloc(sizeof(float *) * g_resolution_x);
	g_num_rays = g_resolution_x;
	init_player();
}

int		loop_game(int key)
{
	if (key == KEY_ESC)
		ft_exit();
	clearcolorbuffer(0x303010);
	key_pressed(key);
	action_player(0, 0, 0, key);
	castallrays();
	generate3dprojection();
	draw_textures();
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_img.img, 0, 0);
	return (0);
}

void	init_direction_player(void)
{
	if (g_deriction == 'N')
		s_player.rotationangle = (90 + 180) * M_PI / 180;
	else if (g_deriction == 'S')
		s_player.rotationangle = 90 * M_PI / 180;
	else if (g_deriction == 'E')
		s_player.rotationangle = 0 * M_PI / 180;
	else if (g_deriction == 'W')
		s_player.rotationangle = 180 * M_PI / 180;
}

int		setup_the_game(int argc)
{
	load_textures_setup();
	g_img.img = mlx_new_image(g_mlx_ptr, g_resolution_x, g_resolution_y);
	g_p = (int *)mlx_get_data_addr(g_img.img, &g_img.bits_per_pixel,
	&g_img.size_line, &g_img.endian);
	init_direction_player();
	draw_mini_map();
	draw_the_player((void *)0, (void *)0);
	castallrays();
	generate3dprojection();
	draw_mini_map();
	draw_the_player((void *)0, (void *)0);
	draw_textures();
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_img.img, 0, 0);
	if (argc == 3)
	{
		bmp_file();
		printf("\033[0;34mscreenshot is taken successfully\033[0");
		exit(0);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	void *param;

	param = NULL;
	check_argument_errors(argc, argv);
	if (!(read_map(argv)))
		ft_error("INVALID MAP | EROOR");
	ft_check_maze();
	config_init();
	if (!(g_mlx_ptr = mlx_init()))
		ft_error("error mlx_init");
	g_win_ptr = mlx_new_window(g_mlx_ptr, g_resolution_x,\
	g_resolution_y, "Cub3d");
	setup_the_game(argc);
	mlx_hook(g_win_ptr, PRESS, 0, loop_game, param);
	mlx_hook(g_win_ptr, 3, 0, keyrelease, param);
	mlx_loop(g_mlx_ptr);
	return (0);
}
