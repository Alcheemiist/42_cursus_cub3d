/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 04:05:13 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/24 04:05:16 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				ft_hasspace(int m_index)
{
	if (g_t[m_index][0] != ' ')
		return (1);
	return (0);
}

float			normalizeangle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

void			is_there_no_wallt(char *trim, int ii)
{
	int i;

	i = -1;
	while (trim[++i] != '\0')
	{
		if (trim[i] != '1')
		{
			ft_free_map(ii, "ff");
			ft_error("MAP is INVALID\nERROR1");
		}
	}
}

void			is_there_no_wall_two(char *trim, int ii)
{
	if (trim[0] != '1' || trim[ft_strlen(trim) - 1] != '1')
	{
		ft_free_map(ii, "ff");
		ft_error("MAP is INVALID\nERROR1");
	}
}

void			is_there_no_wall_three(char *trim, int i, int ii)
{
	if (trim[i] != '1')
	{
		free(trim);
		ft_free_map(ii, "ff");
		ft_error("MAP is INVALID\nERROR1");
	}
}
