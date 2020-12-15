/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:29:59 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:30:03 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*help(char *save, char **line)
{
	char *str;

	str = NULL;
	if (save)
	{
		if ((str = ft_stchr(save, '\n')))
		{
			*str = '\0';
			*line = ft_stdup(save);
			ft_strcpy(save, ++str);
		}
		else
		{
			*line = ft_stdup(save);
			save = NULL;
		}
	}
	else
		*line = ft_caloc(1, 1);
	return (str);
}

void			help3(char *buff, char **line)
{
	char *tmp;

	tmp = *line;
	*line = ft_stjoin(tmp, buff);
	free(tmp);
}

int				help2(char **save, char *buff, int fd, char **line)
{
	int			size_read;
	char		*str;

	str = help(*save, line);
	while (!str)
	{
		if ((size_read = read(fd, buff, BUFFER_SIZE)) == 0)
		{
			free(buff);
			free(*save);
			*save = 0;
			return (0);
		}
		*(buff + size_read) = '\0';
		if ((str = ft_stchr(buff, '\n')))
		{
			*str++ = '\0';
			free(*save);
			*save = ft_stdup(str);
		}
		help3(buff, line);
	}
	free(buff);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char *save;
	char		*buff;

	if ((read(fd, NULL, 0) != 0) || fd < 0 || !line)
		return (-1);
	if (BUFFER_SIZE >= 2147483647)
		return (-1);
	if (!(buff = malloc(BUFFER_SIZE + 1)))
		return (-1);
	return (help2(&save, buff, fd, line));
}
