/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:28:36 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:28:41 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		check_rgb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void	help_keypress(void)
{
	t_key.up = 0;
	t_key.down = 0;
	t_key.left = 0;
	t_key.right = 0;
	t_key.fcright = 0;
	t_key.fcleft = 0;
	t_key.esc = 0;
}

char	*ft_path(char *str, char c1, char c2, short o)
{
	int		i;

	i = 0;
	while (str[i] != c1 && o)
		i++;
	while (str[i] == c1 && o)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == c1)
			str[i] = c2;
		i++;
	}
	return (str);
}

char	*clear_color(char *str)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (str[++i] != '\0')
	{
		if (str[i] != ' ')
			str[++j] = str[i];
		if (str[i] == ' ' && ft_isdigit(str[i - 1]))
			ft_puterror("RGB params must be followed by comma!");
	}
	str[++j] = '\0';
	return (str);
}
