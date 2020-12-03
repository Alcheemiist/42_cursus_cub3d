/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:36:03 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/10/21 03:46:23 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int				i;
	long long int	res;
	long long int	sign;

	res = 0;
	i = 0;
	sign = 1;
	while ((str[i] == 32) || (str[i] == 10) || (str[i] == 9) ||
			(str[i] == 12) || (str[i] == 13) || (str[i] == 11))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		res = (res * 10) + ((long long int)(str[i] - '0'));
		if (res > 2147483648 && sign == -1)
			return (0);
		if (res > 2147483647 && sign == 1)
			return (-1);
		i++;
	}
	return (res * sign);
}
