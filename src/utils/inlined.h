/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inlined.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:01:58 by lilefebv          #+#    #+#             */
/*   Updated: 2026/03/01 14:52:21 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INLINED_H
# define INLINED_H

#include <stddef.h>
#include <unistd.h>
#include <stdint.h>

static inline size_t	ft_strlen(const char *s)
{
	const char	*start = s;
	uintptr_t	*ptr;

	ptr = (uintptr_t *) s;
	while (!((*ptr - 0x0101010101010101ULL) & ~*ptr & 0x8080808080808080ULL))
		ptr++;
	s = (char *) ptr;
	while (*s)
		s++;
	return (s - start);
}

static inline void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

static inline int ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*p1 = (const unsigned char *)s1;
	const unsigned char	*p2 = (const unsigned char *)s2;
	uint64_t			w1;
	uint64_t			w2;

	while (1)
	{
		w1 = *(const uint64_t *)p1;
		w2 = *(const uint64_t *)p2;
		if (w1 ^ w2
			|| ((w1 - 0x0101010101010101ULL) & ~w1 & 0x8080808080808080ULL))
		{
			while (*p1 && *p1 == *p2)
			{
				p1++;
				p2++;
			}
			return (int)*p1 - (int)*p2;
		}
		p1 += 8;
		p2 += 8;
	}
}

#endif