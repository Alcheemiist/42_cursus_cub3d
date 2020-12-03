/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 03:13:43 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/22 03:13:47 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				check_one(char *s, int m_index)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '0')
		{
			if (g_t[m_index + 1][i] == ' ' ||
			g_t[m_index - 1][i] == ' ')
				return (-1);
		}
		i++;
	}
	return (0);
}

int				ft_check_final(char *s, int m_index)
{
	int i;

	if (check_one(s, m_index) == -1)
		return (-1);
	i = 0;
	while (g_t[m_index][i] != '\0')
	{
		if (g_t[m_index][i] == '0')
		{
			if (m_index == (g_high - 1))
			{
				if (g_t[m_index][i] == '0')
					return (-1);
			}
			if (g_t[m_index + 1][i] == ' ' || g_t[m_index - 1][i] == ' '\
			|| g_t[m_index][i + 1] == ' ' || g_t[m_index][i - 1] == ' ')
				return (-1);
			if (m_index < g_high && (g_t[m_index + 1][i] == '\0' ||\
			g_t[m_index + 1][i] == '\0'))
				ft_error("INVALID MAP\nerror405");
		}
		i++;
	}
	return (1);
}

void			ft_free_map(int n, char *error_msg)
{
	int i;

	i = 0;
	while (i < n && g_t[i] != '\0')
		i++;
	printf("\033[0;32m [!] %s \033[0m!\n", error_msg);
}

int				ft_check_maze(void)
{
	int i;

	i = 0;
	while (i < g_high)
	{
		if (ft_check_valid(g_t[i], i) != 1)
		{
			ft_free_map(i, "ff");
			ft_error("MAP is INVALID\nERROR1");
		}
		if (ft_check_final(g_t[i], i) != 1)
		{
			ft_free_map(i, "ff");
			ft_error("MAP is INVALID\nERROR2");
		}
		i++;
	}
	printf("\n\033[0;32m *** Map is Valid loading ...\033[0m!\n");
	return (1);
}

t_vector		new_vector(float x, float y)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}
