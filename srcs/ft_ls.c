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
	ListElement *before;

	j = li;
	before = li;
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
	print_list(li);
	if (g_bit & 4)
	{
		List new_ord = new_list();
		while(li != NULL)
		{	
			new_ord = push_front(new_ord, li->name, li->fileinfo);
			li = back_front(li);
		}
		printf("coucou\n");
		print_list(before);
		return(new_ord);
	}
	return (li);
}

int main (int argc, char **argv)
{
	int i;
	List mylist = new_list();

	i = 1;
	check_arguments_b0(argv, argc);
	i = check_option(argv, argc);
	sort_argv(i, argc, argv);
	mylist = check_directory(i, argc, argv, mylist);
	print_list(mylist);
	mylist = check_sort_list(mylist);
	/*if (mylist->fileinfo.st_mtime < mylist->next->fileinfo.st_mtime)
		printf("coin\n");*/
	printf("Time :%s\n", ctime(&mylist->fileinfo.st_mtime));
	printf("Time 2 :%s\n", ctime(&mylist->next->fileinfo.st_mtime));
	while (mylist != NULL)
	{
		back_front(mylist);
		mylist = mylist->next;
	}
	print_list(mylist);
	//g_debug();
	return (0);
}
