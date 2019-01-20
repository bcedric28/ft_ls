/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:44:01 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/17 15:32:36 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char g_bit = 0;

/*void g_debug()
{
	printf("----OPTION-----\n");
	if (g_bit & 1)
		ft_putendl("a");
	if (g_bit & 2)
		printf("l\n");
	if (g_bit & 4)
		printf("r\n");
	if (g_bit & 8)
		printf("R\n");
	if (g_bit & 16)
		printf("t\n");
	if (g_bit & 32)
		printf("--\n");
}*/

void sort_argv(int i, int argc, char **tab)
{
	char *temp;
	int j;

	j = i;
	while (i < argc && tab[i + 1] != '\0')
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = j;
		}
		else
			i++;
	}
}

List check_sort_list(List li)
{
	char *temp;
	struct stat file;
	ListElement *j;

	j = li;
	if(g_bit & 16)
	{
		while (li->next != NULL)
		{
			if (li->fileinfo.st_mtime < li->next->fileinfo.st_mtime)
			{
				temp = li->name;
				file = li->fileinfo;
				li->name = li->next->name;
				li->fileinfo = li->next->fileinfo;
				li->next->name = temp;
				li->next->fileinfo = file;
				li = j;
			}
			else
				li = li->next;
		}
	}
	li = j;
	if (g_bit & 4)
	{
		List new_ord = new_list();
		while(li != NULL)
		{	
			new_ord = push_front(new_ord, li->name, li->fileinfo);
			li = back_front(li);
		}
		return(new_ord);
	}
	return (li);
}

List create_child_list(List li)
{
	struct dirent *dent;
	struct stat fileinfo;
	List child = new_list();
	DIR *dir;

	//printf("path = %s%s\n", parent, li->name);
	//printf("join = %s\n", ft_strjoin(parent, li->name));

	dir = opendir(li->name);	
	//if (dir == NULL)
	//	return(child);
	while((dent = readdir(dir)) != NULL)
	{
		stat(dent->d_name, &fileinfo);
		child = push_back(child, dent->d_name, fileinfo);
	}
	// free(dent);
	//free(fileinfo);
	return(child);
}

void parent_to_childe(List parent)
{
	DIR *dir;
	List child = new_list();

	print_list(parent);
	while(parent->next != NULL)
	{
		if ((ft_strcmp(parent->name, ".") != 0) && (ft_strcmp(parent->name, "..") != 0))
		{

			dir = opendir(parent->name);
			printf("DIR :%s\n", parent->name);
			if (dir == NULL)
			{
				printf("Saliu\n");
				parent = parent->next;
			}
			else
			{
				printf("COUCOU\n");
				child = create_child_list(parent);
				print_list(child);
				parent_to_childe(child);
			}
		}
		parent = parent->next;
	}
}

/*void parent_to_child(List parent, char *old_parent)
{
	List child = new_list();
	char *temp;
	while(parent->next != NULL)
	{
		temp = parent->name;
		if ((ft_strcmp(parent->name,".") != 0) && (ft_strcmp(parent->name,"..") != 0))
		{
			child = create_child_list(parent, old_parent);
			// print_list(child);
			if (g_bit & 8 && child)
			{
				parent->name = ft_strjoin(parent->name, "/");
				old_parent = ft_strjoin(old_parent, parent->name);
				//printf("path = %s%s\n", old_parent, child->name);

				parent_to_child(child, old_parent);
			}
		}
		free(child);
		printf("1) %s\n", parent->next->name);
		parent = parent->next;
	}
}*/

int main (int argc, char **argv)
{
	int i;
	List mylist = new_list();

	i = 1;
	check_arguments_b0(argv, argc);
	i = check_option(argv, argc);
	sort_argv(i, argc, argv);
	mylist = check_directory(i, argc, argv, mylist);
	mylist = check_sort_list(mylist);
	print_list(mylist);	
	parent_to_childe(mylist);
	if (!(g_bit & 128))
	{

	}
	while (mylist != NULL)
	{
		back_front(mylist);
		mylist = mylist->next;
	}
	//g_debug();
	return (0);
}
