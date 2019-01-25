/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_perm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:59:50 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/25 11:59:52 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	number_of_digit(int max)
{
	int i;

	i = 0;
	if (max == 0)
		i++;
	while (max > 0)
	{
		max = max / 10;
		i++;
	}
	return (i);
}

void 	file_date(List li)
{
	int i;

	i = 0;
	li->date = ctime(&li->fileinfo.st_mtime);
	while (li->date[i])
	{
		if (li->date[i] != '\t' && li->date[i] != ' ')
			i++;
		else
			break;
	}
	while (li->date[i] && i <= 10)
	{
		ft_putchar(li->date[i]);
		i++;
	}
	ft_putendl("");
}

void	affichage_file_link(int max, List li)
{
	int i;
	int j;

	j = 2;
	i = number_of_digit(li->fileinfo.st_nlink);
	while (j > 0)
	{
		ft_putstr(" ");
		j--;
	}
	while (i < max)
	{
		ft_putstr(" ");
		i++;
	}
	ft_putstr(ft_itoa(li->fileinfo.st_nlink));
}

void	affichage_file_group(int max, List li)
{
	int i;
	int j;

	j = 2;
	i = ft_strlen(li->group);
	while (j > 0)
	{
		ft_putstr(" ");
		j--;
	}
	while (i < max)
	{
		ft_putstr(" ");
		i++;
	}
	ft_putstr(li->group);	
}

void	group_name(List li, List begin)
{
	struct group *gid;
	ListElement *temp;
	int max;
	int i;

	max = 0;
	temp = begin;
	while (begin != NULL)
	{
		gid = getgrgid(li->fileinfo.st_gid);
		li->group = gid->gr_name;
		begin = begin->next;
	}
	begin = temp;
	while (begin != NULL)
	{
		i = ft_strlen(li->group);
		if (i > max)
			max = i;
		begin = begin->next;
	}
	affichage_file_group(max, li);	
}

void	affichage_file_login(int max, List li)
{
	int i;

	i = ft_strlen(li->login);
	ft_putstr(" ");
	while (i < max)
	{
		ft_putstr(" ");
		i++;
	}
	ft_putstr(li->login);	
}

void	login_name(List li, List begin)
{
	struct passwd *pw;
	ListElement *temp;
	int max;
	int i;

	max = 0;
	temp = begin;
	while (begin != NULL)
	{
		pw = getpwuid(li->fileinfo.st_uid);
		li->login = pw->pw_name;
		begin = begin->next;
	}
	begin = temp;
	while (begin != NULL)
	{
		i = ft_strlen(li->login);
		if (i > max)
			max = i;
		begin = begin->next;
	}
	affichage_file_login(max, li);	
}

void 	count_file_link(List li, List begin)
{
	int max;

	max = 0;
	while(begin != NULL)
	{
		if (begin->fileinfo.st_nlink > max)
			max = begin->fileinfo.st_nlink;
		begin = begin->next;
	}
	max = number_of_digit(max);
	affichage_file_link(max, li);
}

void	affichage_file_size(int max, List li)
{
	int i;
	int j;

	j = 2;
	i = number_of_digit(li->fileinfo.st_size);
	while (j > 0)
	{
		ft_putstr(" ");
		j--;
	}
	while (i < max)
	{
		ft_putstr(" ");
		i++;
	}
	ft_putstr(ft_itoa(li->fileinfo.st_size));
}

void 	file_size(List li, List begin)
{
	int max;

	max = 0;
	while(begin != NULL)
	{
		if (begin->fileinfo.st_size > max)
			max = begin->fileinfo.st_size;
		begin = begin->next;
	}
	max = number_of_digit(max);
	affichage_file_size(max, li);
}

char	file_perm2(int i, List li)
{
	if (i == 0)
		return ((li->fileinfo.st_mode & S_IRUSR) ? 'r' : '-');
	if (i == 1)
		return ((li->fileinfo.st_mode & S_IWUSR) ? 'w' : '-');
	if (i == 2)
	{
		if (li->fileinfo.st_mode & S_ISUID)
			return ((li->fileinfo.st_mode & S_IXUSR) ? 's' : 'S');
		else
			return ((li->fileinfo.st_mode & S_IXUSR) ? 'x' : '-');
	}
	if (i == 3)
		return ((li->fileinfo.st_mode & S_IRGRP) ? 'r' : '-');
	if (i == 4)
		return ((li->fileinfo.st_mode & S_IWGRP) ? 'w' : '-');
	if (i == 5)
	{
		if (li->fileinfo.st_mode & S_ISGID)
			return ((li->fileinfo.st_mode & S_IXGRP) ? 's' : 'S');
		else
			return ((li->fileinfo.st_mode & S_IXGRP) ? 'x' : '-');
	}
	if (i == 6)
		 return ((li->fileinfo.st_mode & S_IROTH) ? 'r' : '-');
	if (i == 7)
		 return ((li->fileinfo.st_mode & S_IWOTH) ? 'w' : '-');
	if (i == 8)
	{
		if (li->fileinfo.st_mode & S_ISVTX)
			return ((li->fileinfo.st_mode & S_IXUSR) ? 't' : 'T');
		else
			return ((li->fileinfo.st_mode & S_IXOTH) ? 'x' : '-');
	}
	return (0);
}

void affichage_type_of_f(List li)
{
	if (S_ISREG(li->fileinfo.st_mode))
		ft_putchar('-');
	else if (S_ISDIR(li->fileinfo.st_mode))
		ft_putchar('d');
	else if (S_ISCHR(li->fileinfo.st_mode))
		ft_putchar('c');
	else if (S_ISBLK(li->fileinfo.st_mode))
		ft_putchar('b');
	else if (S_ISFIFO(li->fileinfo.st_mode))
		ft_putchar('p');
	else if (S_ISLNK(li->fileinfo.st_mode))
		ft_putchar('l');
	else if(S_ISSOCK(li->fileinfo.st_mode))
		ft_putchar('s');
}

void	affichage_file_perm(List li)
{
	char *str;
	int i;

	i = 0;
	str = ft_strnew(3);
	affichage_type_of_f(li);
	while (i <= 8)
	{
		str[i] = file_perm2(i, li);
		i++;
	}
	str[9] = '\0';
	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
