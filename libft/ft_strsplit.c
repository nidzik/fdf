/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 12:33:09 by nidzik            #+#    #+#             */
/*   Updated: 2014/12/17 13:50:43 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_mali(int i, int j, int k, char **tab)
{
	tab[i++][j] = '\0';
	j = 0;
	tab[i] = (char *)malloc(sizeof(char) * k);

	return (i);
}

int		ft_malj(int i, int j, int k, char **tab)
{
	tab[i++][j] = '\0';
	ft_putnbr(1);
	printf("?%s?\n",tab[i-1]);fflush(stdout);
	j = 0;
	ft_putnbr(2);
	tab[i] = (char *)malloc(sizeof(char) * k);
	ft_putnbr(3);
	return (i);
}


char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		cpt;
	int		k;

	k = ft_strlen(s);
	i = 0;
	j = 0;
	cpt = 0;
	tab = (char **)malloc(sizeof(char *) * k + 1);
	tab[0] = (char *)malloc(sizeof(char) * k + 1);
	while (s[cpt])
	{
		if (s[cpt] == c && j != 0)
			i = ft_malj(i,j,k,tab);
/*		{
			tab[i++][j] = '\0';
			j = 0;
			tab[i] = (char *)malloc(sizeof(char) * k);
			}*/
		else if (s[cpt] != c)
		{
			tab[i][j] = s[cpt];
			j++;
			if (s[cpt + 1] == '\0')
				i = ft_mali(i, j, k, tab);
		}
		cpt++;
	}
	tab[i] = NULL;
	return (tab);
}
