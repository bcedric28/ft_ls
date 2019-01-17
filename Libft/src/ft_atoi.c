/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:58:54 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/05 12:12:58 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi2(const char *str, int sign, long number)
{
	int		i;
	long	overflow;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		overflow = number;
		number *= 10;
		number += (str[i] - '0');
		if (overflow && (number ^ overflow) < 0)
			return ((sign == 1) ? -1 : 0);
		i++;
	}
	return ((int)number * sign);
}

int			ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long			number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == ' ')
			i++;
		else if (str[i] == '-' || str[i] == '+')
		{
			if (!ft_isdigit(str[i + 1]))
				return (0);
			else if (str[i] == '-')
				sign = -1;
			i++;
		}
		else
			break ;
	}
	return (ft_atoi2(&str[i], sign, number));
}
