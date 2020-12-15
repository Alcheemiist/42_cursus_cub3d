/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:36:19 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:36:23 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned const char	*k;
	unsigned const char	*j;

	i = 0;
	k = (unsigned const char *)s1;
	j = (unsigned const char *)s2;
	if (n == 0)
		return (0);
	while ((k[i] != '\0' || j[i] != '\0') && i < n)
	{
		if (k[i] != j[i])
			return (k[i] - j[i]);
		i++;
	}
	return (0);
}
