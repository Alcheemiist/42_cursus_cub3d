/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:37:08 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:37:12 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned long start, size_t len)
{
	int				k;
	int				i;
	int				j;
	char			*tab;

	if (!s)
		return (NULL);
	if (s[0] == '\0' || start > ft_strlen(s))
	{
		if (!(tab = malloc(1 * sizeof(char))))
			return (0);
		tab[0] = '\0';
		return (tab);
	}
	i = 0;
	j = len + start;
	k = start;
	if (!(tab = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (s[start] != '\0' && k++ < j)
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}
