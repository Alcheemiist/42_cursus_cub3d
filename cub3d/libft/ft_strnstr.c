/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 06:43:45 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/10/25 03:30:48 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int y;
	unsigned int i;

	if (!*to_find)
		return ((char*)str);
	y = 0;
	while (str[y] != '\0' && (size_t)y < len)
	{
		if (str[y] == to_find[0])
		{
			i = 1;
			while (to_find[i] != '\0' && str[y + i] == to_find[i] &&
					(size_t)(y + i) < len)
				i++;
			if (to_find[i] == '\0')
				return ((char*)&str[y]);
		}
		y++;
	}
	return (0);
}
