/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:39:43 by lilefebv          #+#    #+#             */
/*   Updated: 2026/02/28 12:37:16 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include <stdlib.h>

int init_hashmap(hashmap_t *hashmap)
{
	uint32_t	i;

	// hashmap->size = HASHMAP_SIZE;
	hashmap->rows = malloc(HASHMAP_SIZE * sizeof(t_row));
	if (!hashmap->rows)
		return (-1);
	i = 0;
	while (i < HASHMAP_SIZE)
	{
		*((unsigned __int128*)&hashmap->rows[i]) = ~((unsigned __int128)0);
		*((unsigned __int128*)&hashmap->rows[i] + 1) = ~((unsigned __int128)0);
		*((unsigned __int128*)&hashmap->rows[i] + 2) = ~((unsigned __int128)0);
		*((unsigned __int128*)&hashmap->rows[i] + 3) = ~((unsigned __int128)0);
		i++;
	}
	return (0);
}

void destroy_hashmap(hashmap_t *hashmap)
{
	// int	i;

	free(hashmap->rows);
	// i = 0;
	// while (i < 2048)
	// 	free(hashmap->tabs[i++]);
}

void insert(hashmap_t *hashmap, uint32_t value)
{
	uint32_t index = HASH_RAPIDE(value) % HASHMAP_SIZE;
	
	while (1) // Un probleme : le cas ou on a plus de place du tout donc a voir pour une limite quand meme
	{	
		int i = 0;
		
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

uint32_t lookup(hashmap_t *hashmap, char *key)
{
	uint32_t index = HASH_RAPIDE_KEY(key) % HASHMAP_SIZE;

	while (1) // Un probleme : le cas ou on est full full et qu'o connait pas la key on boucle a l'infinie
	{
		int i = 0;
		while (*(&hashmap->rows[index].index1 + i) != UINT32_MAX && i < 16)
		{
			if (sscmpstr(*(&hashmap->rows[index].index1 + i), key) == 0)
				return *(&hashmap->rows[index].index1 + i);
			i++;
		}

		if (i < 16)
			return UINT32_MAX;

		index = HASH_SEED_KEY(value, index);
	}
}