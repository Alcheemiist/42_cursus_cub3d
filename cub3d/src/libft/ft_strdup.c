/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:35:10 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:35:13 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
		j++;
	if (!(r = (char *)malloc(sizeof(char) * (j + 1))))
		return (0);
	while (i < j)
	{
		r[i] = s1[i];
		i++;
	}
	r[j] = '\0';
	return (r);
}
