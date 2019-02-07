/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_perm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:59:50 by bcedric           #+#    #+#             */
/*   Updated: 2019/02/07 16:38:19 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Ce fichier contient les fonction qui me permettent, dans un premier temp,
**de definir le type de fichier auquel j'ai a faire. Ensuite la fonction
**Kernel_of_file_perm va appeler une autre fonction ce trouvant dans
**suite_affichage_permission qui me permettra d'afficher les permissions.
**Et pour finir la fonction affichage_xattr_acl me permettra d'afficher
**les acl et les attribut etendu. Le tableau int "total" me permet de definir
**si oui ou non je devrais afficher plus d'espace pour identer
*/

void	affichage_type(t_list_element *li)
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
	else if (S_ISSOCK(li->fileinfo.st_mode))
		ft_putchar('s');
}

void	affichage_xattr_acl(t_list_element *li, int *total)
{
	char	buf[101];
	acl_t	acl;

	total[2] = 0;
	if (listxattr(li->full_path, buf, 101, XATTR_NOFOLLOW) > 0)
	{
		total[2] = 1;
		ft_putstr("@");
	}
	else
	{
		if ((acl = acl_get_file(li->full_path, ACL_TYPE_EXTENDED)) != NULL)
		{
			total[2] = 1;
			ft_putstr("+");
		}
	}
}

void	kernel_of_file_perm(t_list_element *li)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(8);
	affichage_type(li);
	while (i <= 8)
	{
		str[i] = affichage_perm(i, li);
		i++;
	}
	str[9] = '\0';
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	free(str);
}
