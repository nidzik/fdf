/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 12:54:22 by romontei          #+#    #+#             */
/*   Updated: 2014/12/16 12:47:19 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

void		file(int ac, char **av, int i)
{
	struct stat		type;

	while (i < ac && ac > 1)
	{
		lstat(av[i], &type);
		if ((S_ISREG(type.st_mode)) == 1)
			ft_putendl(av[i]);
		else if ((S_ISDIR(type.st_mode)) != 1)
		{
			ft_putstr_fd("ls: ", 2);
			ft_putstr_fd(av[i], 2);
			ft_putendl_fd(": No such file or directory", 2);
		}
		i++;
	}
}

void		dir(int ac, char **av, int i)
{
	struct dirent	*stdir;
	DIR				*dir;

	while (i < ac || ac == 1)
	{
		if (!(dir = opendir(av[i])))
			return;
		dir = opendir (av[i]);
		
		if (ac > 2 && dir != NULL)
		{
			ft_putstr(av[i]);
			ft_putendl(":");
		}
			printf("cc");fflush(stdout);			
			/* if (dir->d_type == 8) */
/* 			{ */
/* 				printf("cc"); */
/* 				return ; */
/* 			} */
		while ((stdir = readdir(dir)) != NULL)
		{
				printf("cc");fflush(stdout);			
			return;
		
			if (stdir->d_name[0] != '.')
				ft_putendl((stdir->d_name));
		}
		if (ac == 1)
			break ;
		i++;
		if ((i <= (ac - 1)) && ac > 2)
			ft_putchar('\n');

	}
		closedir(dir);
}

int			main(int ac, char **av)
{
	int				i;

	i = 1;
	file(ac, av, i);
	if (ac == 1)
		av[1] = ".";
	if ((i <= (ac - 1)) && ac > 2)
		ft_putchar('\n');
	dir(ac, av, i);
	return (0);
}
