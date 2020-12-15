/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:33:16 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:33:19 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*f;
	unsigned char	*e;

	i = 0;
	f = (unsigned char *)s1;
	e = (unsigned char *)s2;
	while (n--)
	{
		if (*f != *e)
			return (*f - *e);
		f++;
		e++;
	}
	return (0);
}
