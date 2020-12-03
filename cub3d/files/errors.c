/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 03:14:05 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/22 03:14:07 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_window(t_window *win)
{
	int				j;

	j = -1;
	while (++j < win->width)
		free(win->map[j]);
	free(win->map);
}

int		ftt_exit(t_window *win)
{
	if (win->map)
		free_window(win);
	exit(0);
}

void	erreur_message(char *str)
{
	ft_putstr_fd(str, 1);
}

void	ft_error(char *str)
{
	perror(ft_strjoin("\033[0;31m", str));
	exit(0);
}

int		ft_exit(void)
{
	free(g_mlx_ptr);
	free(g_win_ptr);
	free(g_p);
	free(g_ray);
	exit(1);
	return (0);
}
