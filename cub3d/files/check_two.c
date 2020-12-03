/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 02:54:15 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/24 02:54:18 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_check_for_error(char *s, int m_index)
{
	int i;
	int m_index_len;

	i = 1;
	m_index_len = ft_strlen(g_t[m_index]);
	while (s[i] != '\0' && ft_hasspace(m_index))
	{
		if (s[i] == ' ' && m_index < g_high)
		{
			if (g_t[m_index - 1][i] == '0' || g_t[m_index + 1][i] == '0'
			|| g_t[m_index][i - 1] == ' ' || g_t[m_index][i + 1] == ' ')
				return (-1);
		}
		if (s[i] == '0')
		{
			if (g_t[m_index - 1][i] == ' ' || g_t[m_index + 1][i] == ' ' ||
			g_t[m_index][i - 1] == ' ' || g_t[m_index][i + 1] == ' ')
				return (-1);
		}
		i++;
	}
	return (1);
}

int			is_valid(char c)
{
	if (c == '1' || c == '0' || c == '2' || c == 'N' ||\
	c == 'S' || c == 'E' || c == 'W' || c == ' ')
		return (TRUE);
	else
		return (FALSE);
}

int			check_for_invalid_char(char *s)
{
	int i;

	i = 0;
	while (s[i])
		if (is_valid(s[i++]) == FALSE)
			return (0);
	return (1);
}

char		*ft_trim_check(char *s)
{
	char	*trim;
	char	*ret;

	trim = ft_strtrim(s, " ");
	if (check_for_invalid_char(trim) != 1)
	{
		free(s);
		free(trim);
		ft_error("\n* THERE IS A CARACTERE INVALID IN THE MAP *\n\n\t\
		CARACTERE VALID ARE :\n\n\t0 | 1 | 2 | S | W | E | N \n\nERROR606");
	}
	ret = ft_strdup(trim);
	free(trim);
	return (ret);
}

int			ft_check_valid(char *s, int m_index)
{
	int			i;
	char		*trim;
	static int	j;

	trim = ft_trim_check(s);
	i = -1;
	if (strlen(trim) == 0)
	{
		j++;
		free(trim);
		return (1);
	}
	if (m_index == j)
		is_there_no_wallt(trim, m_index);
	else if (m_index > 0 && m_index <= (int)strlen(s) - 1)
	{
		is_there_no_wall_two(trim, m_index);
		if (ft_check_for_error(trim, m_index) != 1)
			ft_error(ft_strjoin("MAP INVALID\n line =", ft_itoa(m_index)));
	}
	else if (m_index == (int)strlen(s))
		while (trim[++i] != '\0')
			is_there_no_wall_three(trim, i, m_index);
	free(trim);
	return (1);
}
