/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 12:00:09 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/22 12:20:23 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEBUG_H
# define FT_DEBUG_H

void	ft_printvar(char s[3][50], void *ptr, int line);

# define D(T, A) ft_printvar((char[][50]){#T, #A, __FILE__}, (T*)&A, __LINE__)
# define PEACE(A1, A2) A1 A2; (void)A2

int		qprintf(const char *format, ...);

#endif
