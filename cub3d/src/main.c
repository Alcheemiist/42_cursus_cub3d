/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:26:51 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:26:55 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void		ft_init_mlx(void)
{
	t_mlx.mlx_ptr = mlx_init();
	t_mlx.win_ptr = mlx_new_window(t_mlx.mlx_ptr,
			t_mlx.resul.width, t_mlx.resul.height, "cub3D");
	t_mlx.img.img = mlx_new_image(t_mlx.mlx_ptr,
			t_mlx.resul.width, t_mlx.resul.height);
	t_mlx.img.addr = mlx_get_data_addr(t_mlx.img.img,
			&t_mlx.img.bits_per_pixel, &t_mlx.img.line_length,
			&t_mlx.img.endian);
	ft_get_texture();
	drawmap();
	mlx_hook(t_mlx.win_ptr, 2, 0, keypressed, NULL);
	mlx_hook(t_mlx.win_ptr, 3, 0, keyreleased, NULL);
	mlx_hook(t_mlx.win_ptr, 17, 0, quit, NULL);
	mlx_loop_hook(t_mlx.mlx_ptr, update, NULL);
}

static void		ft_init_col(void)
{
	t_map.colorc = -1;
	t_map.colorf = -1;
}

static short	ft_check_args(int argc, char *argv[])
{
	if (argc != 2 && argc != 3)
		ft_puterror("you have to pass at least 2 arguments");
	setup(argv[1]);
	if (argc == 3 && (ft_strncmp(argv[2], "--save", 7) == 0))
		return (1);
	if (argc == 2)
		return (1);
	else
		return (ft_puterror("Invalid inputs!"));
	return (-1);
}

int				main(int argc, char *argv[])
{
	ft_init_col();
	if (ft_check_args(argc, argv))
	{
		if (!t_sprite.file_spr)
			return (ft_puterror("Please set sprite!"));
		if (!t_mlx.resul.width || !t_mlx.resul.height)
			return (ft_puterror("Please set Resolution of screen"));
		if (!(t_sprite.wall_dst = malloc((t_mlx.resul.width + 1)
						* sizeof(float))))
		{
			return (ft_puterror("Wall Dests Not Alloced"));
		}
		t_sprite.wall_dst[t_mlx.resul.width] = '\0';
		ft_init_mlx();
		mlx_put_image_to_window(t_mlx.mlx_ptr, t_mlx.win_ptr,
			t_mlx.img.img, 0, 0);
		if (argc == 3)
			bmp_file();
		mlx_loop(t_mlx.mlx_ptr);
	}
	else
		ft_puterror("Invalid inputs!");
	return (0);
}
