/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:43:03 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/12 13:43:05 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define  OPTION_a 1
# define  OPTION_l 2
# define  OPTION_r 4
# define  OPTION_R 8
# define  OPTION_t 16
# define  OPTION_STOP 32
# define  OPTION_END 64

#include "../Libft/includes/libft.h"
#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include <grp.h>

extern char g_bit;

/* Definition de la liste chainee */

typedef struct ListElement
{
	char *name;
	struct stat fileinfo;
	struct ListElement *next;
}ListElement, *List;

/* Fonction de checker de error et de tri de argv */

void	ft_error(char c, int i);
void 	ft_error2(char *s);
//int		dirtrue(char *s1);
void	option(char *s1);
List	check_directory(int i, int argc, char **argv, List li);
int		check_option(char **s1, int argc);
void	check_arguments_b0(char **s1, int argc);

/* Prototype de liste */

List new_list(void);
int is_empty(List li);
int list_size(List li);
void print_list(List li);
List push_back(List li, char *s, struct stat file);
List push_front(List li, char *s, struct stat file);
List back_up(List li);
List back_front(List li);
int	 swap_list(List li, int i, int j);
List create_child_list(char *path);
List 	add_list(List li, List begin, char *s);
List back_list(List li, List begin);

#endif
