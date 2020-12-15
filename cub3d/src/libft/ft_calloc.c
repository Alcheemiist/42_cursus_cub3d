/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:31:16 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:31:19 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	if (!(s = malloc(count * size)))
		return (0);
	while (i < size * count)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
