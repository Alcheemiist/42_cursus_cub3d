/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:28:04 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:28:07 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		checkforin(int c, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_lenfrom(int c, char *s)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			len++;
		i++;
	}
	return (len);
}

int		ft_lentwop(char **s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int		validfile(char *file, char *ext)
{
	char	**spfile;
	int		i;
	int		len;

	spfile = ft_split(file, '.');
	len = 0;
	i = -1;
	while (spfile[len])
		len++;
	if (len >= 2)
	{
		while (spfile[len - 1][++i])
			spfile[len - 1][i] = ft_tolower(spfile[len - 1][i]);
		if (ft_strncmp(spfile[len - 1], ext, 4) == 0)
			return (retfreetwo(spfile, 1));
	}
	return (retfreetwo(spfile,
	ft_puterror(ft_strjoin("Your file extention must be : ", ext))));
}
