/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 11:13:10 by nidzik            #+#    #+#             */
/*   Updated: 2014/12/17 12:43:19 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*news;
	int		i;

	news = (char *)malloc(sizeof(char) * ft_strlen(s));
	while (s[i])
	{
		news[i] = (*f)(s[i]);
		i++;
	}
	return (news);
}
