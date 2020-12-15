/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:34:19 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:34:22 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int help;

	help = n;
	if (n < 0)
	{
		help = help * (-1);
		ft_putchar_fd('-', fd);
	}
	if (help >= 10)
	{
		ft_putnbr_fd(help / 10, fd);
	}
	ft_putchar_fd(help % 10 + 48, fd);
}
