/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 12:03:21 by lilefebv          #+#    #+#             */
/*   Updated: 2026/03/01 12:40:55 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdint.h>

void	ft_charcpy(char *d, const char *s, size_t n)
{
	const size_t	chunks = n / 8;
	const size_t	rem = n % 8;
	const uint64_t	*s64 = (const uint64_t *)s;
	uint64_t		*d64;
	size_t			i;

	d64 = (uint64_t *)d;
	i = 0;
	while (i < chunks)
	{
		d64[i] = s64[i];
		++i;
	}
	d = (char *)(d64 + chunks);
	s = (const char *)(s64 + chunks);
	i = 0;
	while (i < rem)
	{
		d[i] = s[i];
		++i;
	}
}

// void	*ft_calloc(size_t size, size_t nb)
// {
// 	void	*tmp;
// 	int		i;

// 	i = 0;
// 	tmp = malloc(size * nb);
// 	if (!tmp)
// 		return (NULL);
// 	while (i < nb)
// 		tmp[i] = 0;
// 	return (tmp);
// }