/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:27:10 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:27:16 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_puterror(char *error)
{
	char *e;

	e = "\033[1;31m Error\n >> \033[0;31m";
	write(1, e, ft_strlen(e));
	write(1, error, ft_strlen(error));
	write(1, "\n", 1);
	return (quit());
}

int	quit(void)
{
	exit(1);
	return (-1);
}
