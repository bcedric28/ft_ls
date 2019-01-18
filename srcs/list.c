/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 07:45:37 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/18 07:45:38 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

List new_list(void)
{
	return (NULL);
}

/* ------------------------------------- */

int is_empty(List li)
{
	if (li == NULL)
		return (0);
	return (1);
}

/* ------------------------------------- */

int list_size(List li)
{
	int size;

	size = 0;

	if (!(is_empty(li)))
		return (size);
	while (li != NULL)
	{
		++size;
		li = li->next;
	}
	return (size);
}

/* ------------------------------------- */

void print_list(List li)
{
	int i;

	if (!(is_empty(li)))
	{
		ft_putendl("Rien a afficher");
		return ;
	}
	while (li != NULL)
	{
		i = 0;
		while(li->c[i] != '\0')
		{
			ft_putchar(li->c[i]);
			i++;
		}
		li = li->next;
		ft_putendl("");
	}
	ft_putendl("");
}

/* ------------------------------------- */

List push_back(List li, char *s)
{
	ListElement *element;
	ListElement	*temp;

	if (!(element = malloc(sizeof(*element))))
	{
		exit(EXIT_FAILURE);
	}
	element->c = s;
	element->next = NULL;
	if(!(is_empty(li)))
		return (element);
	temp = li;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = element;
	return li;
}

/* ------------------------------------- */

List push_front(List li, char *s)
{
	ListElement *element;

	if (!(element = malloc(sizeof(*element))))
	{
		exit(EXIT_FAILURE);
	}
	element->c = s;

	if(!(is_empty(li)))
		element->next = NULL;
	else
		element->next = li;
	return (element);
}

/* ------------------------------------- */

List back_up(List li)
{
	ListElement *temp;
	ListElement *before;

	before = li;
	temp = li;
	if (!(is_empty(li)))
		return (new_list());
	if (li->next ==  NULL)
	{
		free(li);
		li = NULL;
		return (new_list());
	}
	while(temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}
	before->next = NULL;
	free(temp);
	temp = NULL;
	return li;
}

/* ------------------------------------- */

List back_front(List li)
{
	ListElement *element;

	if (!(is_empty(li)))
		return (li);

	if (!(element = malloc(sizeof(*element))))
	{
		exit(EXIT_FAILURE);
	}
	element = li->next;
	free(li);
	li = NULL;
	return (element);
}


void swap_list(List li, int q, int n) /*3(temp), 5(after)*/
{
	int i;
	int j;
	ListElement *temp;
	ListElement *after;
	ListElement *before;
	ListElement *beforeaft;
	ListElement *aftertmp;
	ListElement *aftere;
	ListElement *sauv;

	before = li;
	temp = li;

	sauv = li;
	after = li;
	beforeaft = li;
	i = 0;
	while (i < q - 1)
	{
		i++;
		before = temp;
		temp = temp->next;
	}
	printf("TEMP %s\n", temp->c);
	printf("Before temp %s\n", before->c);
	aftertmp = temp->next;
	printf("After %s\n", aftertmp->c);
	j = 0;
	while (j < n - 1)
	{
		j++;
		beforeaft = after;
		after = after->next;
	}
	aftere = after->next;
	printf("BONJOUR %s\n", aftere->c);
	printf("BEFORE %s\n", beforeaft->c);
	int k = 1;
	while (k < q - 1)
	{
		li = li->next;
		k++;
	}
	printf("Coucou %s\n", li->c);
	li->next = beforeaft->next;
	sauv = aftertmp->next;
	k = 1;
	while (k < q)
	{
		printf("salut %s\n", li->c);
		li = li->next;
		k++;
	}
	printf("salut %s\n", li->c);
	aftertmp->next = temp->next;
	temp->next = aftere->next;
	printf("DEBEUG %s\n", li->c);
	printf("DEBEUG 1 %s\n", sauv->c);
	sleep(10);
	li->next = sauv->next;
	printf("cara %p\n", aftertmp->next);
	printf("CARA %p\n", temp->next);
	//aftertmp->next = before->next;
	printf("Coucou2 %s\n", aftertmp->c);
	//li->next = aftertmp->next;

}


