/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 08:27:12 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/14 18:51:45 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include <grp.h>
int main(int argc, char **argv)
{
	DIR *dir;
	struct dirent *dent;
	struct stat fileinfo;
	struct passwd *pw;
	struct group *gid;
	if (argc == 1)
	{
		dir = opendir(".");
		while((dent=readdir(dir)) != NULL)
		{
			printf("-------------------\n");
			if(!stat(dent->d_name,&fileinfo))
			{
					pw = getpwuid(fileinfo.st_uid);
					gid = getgrgid(fileinfo.st_gid);
					printf("login name:   %s\n", pw->pw_name);
					printf(" name:   %s\n", gid->gr_name);
					printf("File Permissions: \t");
					printf( (S_ISDIR(fileinfo.st_mode)) ? "d" : "-");
					printf( (fileinfo.st_mode & S_IRUSR) ? "r" : "-");
					printf( (fileinfo.st_mode & S_IWUSR) ? "w" : "-");
					printf( (fileinfo.st_mode & S_IXUSR) ? "x" : "-");
					printf( (fileinfo.st_mode & S_IRGRP) ? "r" : "-");
					printf( (fileinfo.st_mode & S_IWGRP) ? "w" : "-");
					printf( (fileinfo.st_mode & S_IXGRP) ? "x" : "-");
					printf( (fileinfo.st_mode & S_IROTH) ? "r" : "-");
					printf( (fileinfo.st_mode & S_IWOTH) ? "w" : "-");
					printf( (fileinfo.st_mode & S_IXOTH) ? "x" : "-");
					printf("\n");
					printf("File Link:    %d\n", fileinfo.st_nlink);
					printf("FILE Name:      %s\n",dent->d_name);
					printf("FILE Size:      %d bytes\n",fileinfo.st_size);
					printf("FILE Access:      %s\n",ctime(&fileinfo.st_atime));
					printf("FILE Modify:      %s\n",ctime(&fileinfo.st_mtime));
					printf("FILE Access:      %s\n",&fileinfo.st_atime);

			}
		}
	}
	else
	{
		dir = opendir(argv[1]);
		if (dir == NULL)
		{
			printf ("Error");
			return (1);
		}
		while((dent=readdir(dir)) != NULL)
			printf("[%s]\n", dent->d_name);
		closedir (dir);
	}
	return 0;
}
