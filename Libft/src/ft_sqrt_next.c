/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:35:17 by bcedric           #+#    #+#             */
/*   Updated: 2018/11/02 17:35:19 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt_next(int nb)
{
	int i;
	int result;

	result = 0;
	i = 1;
	if (nb == 0 || nb < 0)
		return (0);
	while (result < nb)
	{
		result = i * i;
		i++;
	}
	if (result == nb)
		return (i - 1);
	else
		return (ft_sqrt_next(nb + 1));
}
