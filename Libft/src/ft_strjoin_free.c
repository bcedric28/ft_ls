/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:51:30 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/07 13:51:31 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int i)
{
	char	*new;
	int		k;
	int		l;
	char *s1_bis;
	char *s2_bis;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = NULL;
	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (new == NULL)
		return (NULL);
	k = 0;
	while (s1[k])
	{
		new[k] = s1[k];
		k++;
	}
	l = 0;
	while (s2[l])
	{
		new[k] = s2[l];
		l++;
		k++;
	}
	s1_bis = s1;
	s2_bis = s2;
	if (i == 0)
		ft_strdel(&s1);
	if (i == 1)
		ft_strdel(&s2);
	if (i == 2)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (new);
}