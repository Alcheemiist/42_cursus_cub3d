/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 07:21:57 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/10/21 04:38:38 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	void *new;

	new = NULL;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	new = malloc(count * size);
	if (!new)
		return (NULL);
	memset(new, 0, count * size);
	return (new);
}
