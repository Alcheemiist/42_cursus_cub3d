/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:09:20 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/24 17:09:25 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getlines(int fd, char *str)
{
	char	*temp;
	int		ret;
	char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	ret = 0;
	if (!str)
		str = ft_strdup("");
	while (ft_strchr(str, '\n') == NULL)
	{
		if ((ret = read(fd, buffer, BUFFER_SIZE)) < 0)
		{
			free(buffer);
			return (0);
		}
		buffer[ret] = '\0';
		temp = str;
		str = ft_strjoin(str, buffer);
		free(temp);
		if (ret == 0 || str[0] == '\0')
			break ;
	}
	free(buffer);
	return (str);
}

void	ft_strdel(char **s)
{
	free(*s);
	*s = NULL;
}

int		get_next_line(int fd, char **line)
{
	static char		*str;
	size_t			len;
	char			*temp;

	if (fd < 0 || !line || BUFFER_SIZE < 0)
		return (-1);
	if ((str = ft_getlines(fd, str)) == NULL)
		return (0);
	if (!(ft_strchr(str, '\n')))
	{
		if (!(*line = ft_strdup(str)))
			return (-1);
		ft_strdel(&str);
		return (0);
	}
	else
	{
		len = ft_strchr(str, '\n') - str;
		temp = str;
		*line = ft_substr(str, 0, len);
		str = ft_strdup(str + len + 1);
		free(temp);
		return (1);
	}
}
