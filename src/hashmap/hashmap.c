/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:54:07 by ethebaul          #+#    #+#             */
/*   Updated: 2026/03/01 15:36:09 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include "stream.h"
#include "utils.h"
#include "hashmap.h"
#include "vector.h"

#include <unistd.h>
#include <stdlib.h>

int	init_hashmap(t_hashmap *hashmap)
{
	t_32b	i;

	hashmap->rows = malloc(HASHMAP_SIZE * sizeof(t_row));
	if (!hashmap->rows)
		return (-1);
	i = 0;
	while (i < HASHMAP_SIZE)
	{
		*((unsigned __int128*)(&hashmap->rows[i])) = ~((unsigned __int128)0);
		*((unsigned __int128*)(&hashmap->rows[i]) + 1) =
		~((unsigned __int128)0);
		*((unsigned __int128*)(&hashmap->rows[i]) + 2) =
		~((unsigned __int128)0);
		*((unsigned __int128*)(&hashmap->rows[i]) + 3) =
		~((unsigned __int128)0);
		i++;
	}
	return (0);
}

void	destroy_hashmap(t_hashmap *hashmap)
{
	free(hashmap->rows);
}

static inline t_32b	hash_u32(t_32b x)
{
	x ^= x >> 16;
	x *= 0x7feb352d;
	x ^= x >> 15;
	x *= 0x846ca68b;
	x ^= x >> 16;
	return (x);
}

t_32b	lookup(t_hashmap *hashmap, t_vector *vec, t_32b value)
{
	t_32b	index;
	int		i;

	index = djb2(vec, value) % HASHMAP_SIZE;
	while (1)
	{
		i = 0;
		while (hashmap->rows[index].index[i] != UINT_MAX && i < 16)
		{
			if (ft_strcmp(vec->data + hashmap->rows[index].index[i],
					vec->data + value) == 0)
				return (hashmap->rows[index].index[i]);
			i++;
		}
		if (i < 16)
			return (UINT_MAX);
		index = hash_u32(index);
	}
}

void	insert(t_hashmap *hashmap, t_vector *vec, t_32b value)
{
	t_32b	index;
	int		i;

	index = djb2(vec, value) % HASHMAP_SIZE;
	while (1)
	{
		i = 0;
		while (hashmap->rows[index].index[i] != UINT_MAX && i < 16)
			i++;
		if (i < 16)
		{
			hashmap->rows[index].index[i] = value;
			return ;
		}
		index = hash_u32(index);
	}
}
