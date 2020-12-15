/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:33:01 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:33:04 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *k;

	k = (unsigned char *)s;
	while (n--)
	{
		if (*k == (unsigned char)c)
			return (k);
		k++;
	}
	return (0);
}
