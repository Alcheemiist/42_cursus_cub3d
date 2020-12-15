/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:30:09 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:30:14 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# define BUFFER_SIZE 128

int				get_next_line(const int fd, char **line);
char			*ft_stjoin(char const *s1, char const *s2);
void			*ft_caloc(size_t count, size_t size);
char			*ft_strcpy(char *dest, char *src);
char			*ft_stchr(const char *s, int c);
char			*ft_stdup(const char *s1);
int				help2(char **save, char *buff, int fd, char **line);
void			help3(char *buff, char **line);
char			*help(char *save, char **line);

#endif
