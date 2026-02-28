/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:43:20 by bfitte            #+#    #+#             */
/*   Updated: 2026/02/28 11:53:11 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "../types.h"

uint64_t	fnv(t_stringv str)
{
	uint64_t	hash;
	uint64_t	prime_number;
	size_t			i;

	i = 0;
	hash = 14695981039346656037ULL;
	prime_number = 1099511628211ULL;
	while (i < str.size)
	{
		hash = hash ^ str.ptr[i];
		hash *= prime_number;
		i++;
	}
	return hash;
}

