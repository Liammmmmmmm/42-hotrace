/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnv1a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:43:20 by bfitte            #+#    #+#             */
/*   Updated: 2026/02/28 11:15:10 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint64_t	fnv(char *str)
{
	uint64_t	hash;
	uint64_t	prime_number;
	int			i;

	i = 0;
	hash = 14695981039346656037ULL;
	prime_number = 1099511628211ULL;
	while (str[i])
	{
		hash = hash ^ str[i];
		hash *= prime_number;
		i++;
	}
	return hash;
}
