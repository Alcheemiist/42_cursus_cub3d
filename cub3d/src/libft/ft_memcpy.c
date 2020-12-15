/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:38:09 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:38:13 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned const char *)src;
	if (s == d)
		return (d);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
