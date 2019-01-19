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
		if (((g_bit & 4) && !(g_bit & 16)) ? 
		ft_strcmp(tab[i], tab[i + 1]) < 0 :
		ft_strcmp(tab[i], tab[i + 1]) > 0)
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
	printf("%s\n", ctime(&mylist->fileinfo.st_mtime));
	printf("%ld\n", mylist->fileinfo.st_mtime);
	printf("%s\n", ctime(&mylist->next->fileinfo.st_mtime));

	if (mylist->fileinfo.st_mtime < mylist->next->fileinfo.st_mtime)
		printf("coin\n");
	while (mylist != NULL)
	{
		back_front(mylist);
		mylist = mylist->next;
	}
	print_list(mylist);
	//g_debug();
	return (0);
}
