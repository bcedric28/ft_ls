/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:44:01 by bcedric           #+#    #+#             */
/*   Updated: 2019/02/08 12:14:51 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem		*create_child_list(char *path, int parent)
{
	struct dirent	*dent;
	struct stat		f_info;
	DIR				*dir;
	char			*f_path;
	t_elem			*child;

	child = new_list();
	dir = opendir(path);
	if (dir == NULL || lstat(path, &f_info) != 0)
		exit(EXIT_FAILURE);
	if (S_ISLNK(f_info.st_mode) && parent == 0)
	{
		closedir(dir);
		return (child);
	}
	while ((dent = readdir(dir)) != NULL)
	{
		f_path = ft_strjoin_free(path, "/", 4);
		f_path = ft_strjoin_free(f_path, dent->d_name, 0);
		if (lstat(f_path, &f_info) == 0)
			child = push_back(child, new_elem(dent->d_name, f_path, f_info, 0));
	}
	closedir(dir);
	return (child);
}

void		open_and_create(char *path, t_elem *child, int i, t_elem *parent)
{
	DIR			*dir;

	dir = opendir(path);
	if (dir != NULL)
	{
		child = create_child_list(path, 0);
		if (child)
		{
			child = check_sort_list_ascci(child);
			affichage(child, path, i);
			if (g_bit & OPTION_R)
				parent_to_childe(child, path, i);
			free_li(child);
		}
		else if (parent->parent == 1 || parent->parent == 2)
			affichage(parent, path, i);
		closedir(dir);
	}
	else if (check_perm(path) == 0 && dir == NULL)
		ft_error3(path, parent);
}

char		*create_path(char *path, t_elem *parent)
{
	if (path != NULL)
	{
		if (ft_strcmp(path, "/") != 0)
			path = ft_strjoin_free(path, "/", 0);
		path = ft_strjoin_free(path, parent->name, 0);
	}
	else
	{
		if (ft_strcmp(parent->name, "./") == 0 && (parent->parent == 2))
			path = ft_strdup(".");
		else if (ft_strcmp(parent->name, "../") == 0 &&
			(parent->parent == 2))
			path = ft_strdup("..");
		else
			path = ft_strdup(parent->name);
	}
	return (path);
}

void		parent_to_childe(t_elem *parent, char *path2, int i)
{
	t_elem		*child;
	char		*path;

	child = new_list();
	path = ft_strdup(path2);
	while (parent != NULL)
	{
		if (ft_strcmp(parent->name, ".") && ft_strcmp(parent->name, ".."))
		{
			path = create_path(path, parent);
			open_and_create(path, child, i++, parent);
		}
		if (path)
			ft_strdel(&path);
		if (path2 && parent->next)
			path = ft_strdup(path2);
		parent = parent->next;
	}
	free_li(parent);
}

void		no_arguments(t_elem *mylist)
{
	char		*temp;

	affichage(mylist, "", 0);
	if (g_bit & OPTION_R)
	{
		temp = ft_strdup(".");
		parent_to_childe(mylist, temp, 0);
		ft_strdel(&temp);
	}
}
