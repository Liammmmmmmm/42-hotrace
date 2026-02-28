/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:39:43 by lilefebv          #+#    #+#             */
/*   Updated: 2026/02/28 18:14:48 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include <stdlib.h>

int	init_hashmap(t_hashmap *hashmap)
{
	size_t	i;

	hashmap->rows = malloc(HASHMAP_SIZE * sizeof(t_row));
	if (!hashmap->rows)
		return (-1);
	i = 0;
	while (i < HASHMAP_SIZE * sizeof(t_row))
	{
		if (HASHMAP_SIZE * sizeof(t_row) - i >= 8)
		{
			((size_t *)hashmap->rows)[i >> 3] = 0;
			i += 8;
		}
		else
		{
			((size_t *)hashmap->rows)[i] = 0;
			i++;
		}
	}
	return (0);
}

void	destroy_hashmap(t_hashmap *hashmap)
{
	free(hashmap->rows);
}

void	insert(t_hashmap *hashmap, char *key)
{
	char	*index;

	index = (char *)(*(size_t *)key % HASHMAP_SIZE);
	while (1)
	{
		int	i;

		i = 0;
		while (*(&hashmap->rows[index].index1 + i) != UINT32_MAX && i < 16)
			i++;
		if (i < 16)
		{
			*(&hashmap->rows[index].index1 + i) = value;
			return ;
		}
		index = HASH_SEED(value, index);
	}
}

uint32_t	lookup(t_hashmap *hashmap, char *key)
{
	uint32_t	index;
	
	index = HASH_RAPIDE_KEY(key) % HASHMAP_SIZE;
	while (1) // Un probleme : le cas ou on est full full et qu'o connait pas la key on boucle a l'infinie
	{
		int i;

		i = 0;
		while (*(&hashmap->rows[index].index1 + i) != UINT32_MAX && i < 16)
		{
			if (sscmpstr(*(&hashmap->rows[index].index1 + i), key) == 0)
				return (*(&hashmap->rows[index].index1 + i));
			i++;
		}
		if (i < 16)
			return (UINT32_MAX);
		index = HASH_SEED_KEY(value, index);
	}
}
