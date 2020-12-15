/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:33:27 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:33:31 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (!(s || d))
		return (NULL);
	if (s < d)
	{
		while (++i <= len)
			d[len - i] = s[len - i];
	}
	else
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	return (dst);
}
