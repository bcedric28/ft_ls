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

int number_of_digit(int i)
{
	int digit;

	digit = 0;
	while (i != 0)
	{
		i /= 10;
		++digit;
	}
	return (digit);
}

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



int main (int argc, char **argv)
{
	int i;
	char *c;
	int j = 0;
	List mylist = new_list();

	i = 1;
	while (i < argc)
	{
		mylist = push_back(mylist, argv[i]);
		i++;
	}
	j = list_size(mylist);
	i = 0;
	c = ft_itoa(j);
	while (c[i] != '\0')
	{
		ft_putchar(c[i]);
		i++;
	}
	printf("I: %d\n", i);
	print_list(mylist);
	printf("\n-----------------\n");
	swap_list(mylist, 3, 5);
	print_list(mylist);

	i = 1;
	check_arguments_b0(argv, argc);
	i = check_option(argv, argc);
	sort_argv(i, argc, argv);
	check_directory(i, argc, argv);
//	g_debug();
	return (0);
}
