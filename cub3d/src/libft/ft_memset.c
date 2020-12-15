/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:33:39 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:33:44 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*k;

	k = (unsigned char*)b;
	if (len)
	{
		while (len--)
		{
			*k++ = c;
		}
	}
	return (b);
}
