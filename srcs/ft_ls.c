/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:44:01 by bcedric           #+#    #+#             */
/*   Updated: 2019/02/08 12:14:51 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char g_bit = 0;

int			check_perm(char *path)
{
	struct stat fileinfo;

	lstat(path, &fileinfo);
	if (!S_ISDIR(fileinfo.st_mode))
		return (1);
	return (0);
}

t_elem	*create_child_list(char *path, int parent)
{
	struct dirent	*dent;
	struct stat		f_info;
	DIR				*dir;
	char			*f_path;
	t_elem		*child;

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

void		affichage(t_elem *li, char *path, int i)
{
	t_elem	*begin;
	int			total[3];
	char		*result;

	if (i != 0)
		printf("\n%s:\n", path); //printf !!
	if (g_bit & OPTION_L && (is_empty(li) == 1) && li->parent == 0)
	{
		total[0] = total_block(li);
		ft_putstr("total ");
		result = ft_itoa(total[0]);
		ft_putstr(result);
		free(result);
		ft_putendl("");
	}
	file_minor_and_major(li, total);
	begin = data_noodle(li);
	while (li != NULL)
	{
		if (g_bit & OPTION_L)
			main_l(li, begin, total);
		else
			ft_putendl(li->name);
		li = li->next;
	}
}

void		parent_to_childe(t_elem *parent, char *path2, int i)
{
	DIR			*dir;
	t_elem	*child;
	int			alloc;
	char		*path;
	char		*path_backup;

	child = new_list();
	if (path2 != NULL)
	{
		path = ft_strdup(path2);
		path_backup = ft_strdup(path2);
		alloc = 1;
	}
	else
	{
		path = NULL;
		path_backup = NULL;
		alloc = 0;
	}
	while (parent != NULL)
	{
		if (ft_strcmp(parent->name, ".") && ft_strcmp(parent->name, ".."))
		{
			alloc = 1;
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
				else if (ft_strcmp(parent->name, "../") == 0 && (parent->parent == 2))
					path = ft_strdup("..");
				else
					path = ft_strdup(parent->name);
			}
			dir = opendir(path);
			if (dir != NULL)
			{
				child = create_child_list(path, 0);
				if (child)
				{
					child = check_sort_list_ascci(child);
					affichage(child, path, i++);
					if (g_bit & OPTION_R)
						parent_to_childe(child, path, i);
					free_li(child);
				}
				else if (parent->parent == 1 || parent->parent == 2)
					affichage(parent, path, i++);
				closedir(dir);
			}
			else if (check_perm(path) == 0 && dir == NULL)
				(parent->next == NULL) ? ft_error3(path, 0, i, parent) : ft_error3(path, 1, i, parent);
		}
		if (alloc)
			ft_strdel(&path);
		if (path_backup && parent->next)
			path = ft_strdup(path_backup);
		parent = parent->next;
	}
	if (path_backup)
		free(path_backup);
	free_li(parent);
}

int			main(int argc, char **argv)
{
	int			i;
	char		*temp;
	t_elem	*mylist;

	mylist = new_list();
	check_arguments_b0(argv, argc);
	i = check_option(argv, argc);
	sort_argv(i, argc, argv);
	mylist = check_directory(i, argc, argv, mylist);
	if (!is_empty(mylist))
		return (0);
	mylist = check_sort_list_ascci(mylist);
	if (i != argc)
	{
		mylist = print_and_free_only_file(mylist);
		if (list_size(mylist) != 0)
			parent_to_childe(mylist, NULL, (list_size(mylist)));
	}
	else
	{
		if (g_bit & OPTION_R)
		{
			affichage(mylist, "", 0);
			temp = ft_strdup(".");
			parent_to_childe(mylist, temp, 1);
			ft_strdel(&temp);
		}
		else
			affichage(mylist, "", 0);
	}
	if (mylist)
		free_li(mylist);
	return (0);
}
