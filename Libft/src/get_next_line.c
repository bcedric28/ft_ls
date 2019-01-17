
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 12:56:46 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/28 19:36:55 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_read(char **tab, char *buf, int fd)
{
	char		*tmp;
	int			ret;

	while (!(ft_strchr(*tab, DEFINE_END)))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (NULL);
		if (ret)
		{
			buf[ret] = '\0';
			tmp = *tab;
			if (!(*tab = ft_strjoin(*tab, buf)))
				return (NULL);
			free(tmp);
		}
		else
			break ;
	}
	free(buf);
	return (*tab);
}

int				ft_line(char **tab, char **line)
{
	char		*buf;
	char		*tmp;

	buf = ft_strchr(*tab, DEFINE_END);
	tmp = NULL;
	if (buf)
	{
		if (!(*line = ft_strndup(*tab, (buf - *tab))))
			return (0);
		tmp = *tab;
		if (!(*tab = ft_strdup(buf + 1)))
			return (0);
		free(tmp);
	}
	else if (!(*line = ft_strdup(*tab)))
		return (0);
	if (!tmp)
	{
		free(*tab);
		*tab = NULL;
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*tab[_SC_OPEN_MAX];
	char		*buf;
	
	if (fd > _SC_OPEN_MAX || fd < 0 || !line || BUFF_SIZE <= 0 ||
		!(buf = ft_strnew(BUFF_SIZE + 1))
		|| (tab[fd] == NULL && !(tab[fd] = ft_strnew(0))))
		return (-1);
	if (!(ft_read(&tab[fd], buf, fd)))
		return (-1);
	if (*tab[fd])
	{
		if (!(ft_line(&tab[fd], line)))
			return (-1);
		return (1);
	}
	return (0);
}
