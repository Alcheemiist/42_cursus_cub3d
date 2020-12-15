/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:28:15 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:28:19 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_help(char *s)
{
	int i;
	int n;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	n = ft_atoi(s);
	if (n < 0 || n > 255)
		return (0);
	return (1);
}

int	ft_isnumber(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	retfree(char *tmp1, char *tmp2, int ret)
{
	if (tmp1)
	{
		free(tmp1);
		tmp1 = NULL;
	}
	if (tmp2)
	{
		free(tmp2);
		tmp2 = NULL;
	}
	return (ret);
}

int	retfreetwo(char **tmp1, int ret)
{
	int i;

	i = 0;
	if (tmp1)
	{
		while (tmp1[i])
		{
			free(tmp1[i]);
			tmp1[i] = NULL;
			i++;
		}
		free(tmp1);
		tmp1 = NULL;
	}
	return (ret);
}
