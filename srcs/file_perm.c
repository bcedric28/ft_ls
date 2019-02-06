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

/*
** (Seulement si le -l est actif)
**affichage_file_perm: je cree une string qui contiendra
**	les differente information a propos de type de fichier
**	ou dossier auquel on est confronte ainsi que toute les
**	permission (user, group) grace a cette fonction j'appelle
**	"affichage_type" et "file_perm1". Puis j'affiche ma string
*/

int 	check_perm(char *path)
{
	struct stat fileinfo;

	lstat(path, &fileinfo);
	if (S_ISREG(fileinfo.st_mode) || S_ISCHR(fileinfo.st_mode))
		return (1);
	if (!(fileinfo.st_mode & S_IRGRP) && !(fileinfo.st_mode & S_IROTH))
		return (0);
	else 
		return (1);
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
	else if (S_ISLNK(li->fileinfo.st_mode))
		ft_putchar('l');
	else if (S_ISDIR(li->fileinfo.st_mode))
		ft_putchar('d');
	else if (S_ISCHR(li->fileinfo.st_mode))
		ft_putchar('c');
	else if (S_ISBLK(li->fileinfo.st_mode))
		ft_putchar('b');
	else if (S_ISFIFO(li->fileinfo.st_mode))
		ft_putchar('p');
	else if(S_ISSOCK(li->fileinfo.st_mode))
		ft_putchar('s');
}

void	affichage_file_perm(List li)
{
	char *str;
	int i;

	i = 0;
	str = ft_strnew(8);
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
	free(str);
}
