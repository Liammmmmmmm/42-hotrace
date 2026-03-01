/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:54:07 by ethebaul          #+#    #+#             */
/*   Updated: 2026/03/01 12:43:2020 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include "stream.h"
#include "utils.h"
#include "hashmap.h"

#include <unistd.h>
#include <stdlib.h>
// void	djb2(t_64stream *hashstream, t_8stream *input, size_t index)
// {
// 	size_t	*bucket;
// 	size_t	hash;
// 	size_t	i;
// 	char	*c;

// 	hash = 5381;
// 	c = access8stream(input, index);
// 	i = index;
// 	while (*c)
// 	{
// 		hash = ((hash << 5) + hash) + (unsigned char)*c;
// 		i++;
// 		c = access8stream(input, i);
// 	}
// 	bucket = accesscreat64stream(hashstream, hash & BUF64SIZE);
// 	if (!bucket)
// 		return ;
// 	else
// 		*bucket = index;
// }

// int	init_hashmap(t_64stream *hashstream, t_8stream *inputstream)
// {
// 	size_t	word;
// 	size_t	len;
// 	size_t	i;
// 	char	*c;

// 	i = 0;
// 	word = ULONG_MAX;
// 	len = len8stream(inputstream);
// 	while (i < len)
// 	{
// 		c = access8stream(inputstream, i);
// 		if (c == NULL)
// 			return (-1);
// 		if (*c == '\n')
// 		{
// 			*c = '\0';
// 			if (word != ULONG_MAX)
// 				djb2(hashstream, inputstream, word);
// 			word = ULONG_MAX;
// 		}
// 		else if (word == ULONG_MAX)
// 			word = i;
// 		++i;
// 	}
// 	return (0);
// }

// void print_stream_word(t_8stream *inputstream, size_t index)
// {
// 	char	*c;

// 	c = access8stream(inputstream, index);
// 	while (c && *c)
// 	{
// 		write(1, c, 1);
// 		index++;
// 		c = access8stream(inputstream, index);
// 	}
// }

// void print_stream_value(t_8stream *inputstream, size_t index)
// {
// 	char	*c;

// 	c = access8stream(inputstream, index);
// 	while (c && *c)
// 	{
// 		index++;
// 		c = access8stream(inputstream, index);
// 	}
// 	index++;
// 	print_stream_word(inputstream, index);
// }

// size_t	djb2(t_8stream *input, size_t index)
// {
// 	// size_t	*bucket;
// 	size_t	hash;
// 	size_t	i;
// 	char	*c;

// 	hash = 5381;
// 	c = access8stream(input, index);
// 	i = index;
// 	while (*c)
// 	{
// 		hash = ((hash << 5) + hash) + (unsigned char)*c;
// 		i++;
// 		c = access8stream(input, i);
// 	}
// 	return hash;
// 	// bucket = accesscreat64stream(hashstream, hash & BUF64SIZE);
// 	// if (!bucket)
// 		// return ;
// 	// else
// 		// *bucket = index;
// }

// size_t fill_values(t_hashmap *hashmap, t_8stream *inputstream)
// {
// 	size_t	word;
// 	size_t	len;
// 	size_t	i;
// 	char	*c;

// 	int is_key = 1;
// 	i = 0;
// 	word = ULONG_MAX;
// 	len = len8stream(inputstream);
// 	while (i < len)
// 	{
// 		c = access8stream(inputstream, i);
// 		if (c == NULL)
// 			return (ULONG_MAX);
// 		// printf("char %c\n", *c);
// 		if (*c == '\n')
// 		{
// 			*c = '\0';
// 			if (is_key)
// 			{
// 				if (word != ULONG_MAX)
// 					insert(hashmap, inputstream, word);
// 				else
// 					return i + 1;
// 				is_key = 0;
// 			}
// 			else
// 			{
// 				is_key = 1;
// 			}
// 			word = ULONG_MAX;
// 		}
// 		else if (word == ULONG_MAX)
// 			word = i;
// 		++i;
// 	}
// 	return (0);
// }

// void find_values(t_hashmap *hashmap, t_8stream *inputstream, size_t start)
// {
// 	size_t	word;
// 	size_t	len;
// 	size_t	i;
// 	char	*c;

// 	i = start;
// 	word = ULONG_MAX;
// 	len = len8stream(inputstream);
// 	while (i < len)
// 	{
// 		c = access8stream(inputstream, i);
// 		if (c == NULL)
// 			return ;
// 		if (*c == '\n')
// 		{
// 			*c = '\0';
// 			if (word != ULONG_MAX)
// 			{
// 				t_32b index = lookup(hashmap, inputstream, word);
// 				if (index == UINT_MAX)
// 					write(1, "keyword-searched: Not found.\n", 29);
// 				else
// 				{
// 					print_stream_value(inputstream, index);
// 					write(1, "\n", 1);
// 				}
// 			}
// 			word = ULONG_MAX;
// 		}
// 		else if (word == ULONG_MAX)
// 			word = i;
// 		++i;
// 	}
// }

int init_hashmap(t_hashmap *hashmap)
{
	t_32b	i;

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

void destroy_hashmap(t_hashmap *hashmap)
{
	free(hashmap->rows);
}

static inline t_32b hash_u32(t_32b x)
{
    x ^= x >> 16;
    x *= 0x7feb352d;
    x ^= x >> 15;
    x *= 0x846ca68b;
    x ^= x >> 16;
    return x;
}

// void insert(t_hashmap *hashmap, t_8stream *input, t_32b value)
// {
// 	// static int nbinserted = 0;

// 	// if (nbinserted % 10000 == 0) printf("Inserted %d values\n", nbinserted);
// 	// nbinserted++;

// 	t_32b index = djb2(input, value) % HASHMAP_SIZE;

// 	// printf("Insert:\n");
// 	// print_stream_word(input, value);
// 	// write(1, "\n", 1);
// 	// printf("Fin insert\n");
	
// 	while (1) // Un probleme : le cas ou on a plus de place du tout donc a voir pour une limite quand meme
// 	{	
// 		int i = 0;

		
// 		while (hashmap->rows[index].index[i] != UINT_MAX && i < 16)
// 		{
// 			// printf("%u %p\n", hashmap->rows[index].index[i], (&hashmap->rows[index].index1 + i));
// 			i++;
// 		}

// 		if (i < 16)
// 		{
// 			hashmap->rows[index].index[i] = value;
// 			return ;
// 		}

// 		index = hash_u32(index);
// 	}
// }

// int sscmp(t_8stream *input, t_32b v1, t_32b v2)
// {
// 	char	*c1;
// 	char	*c2;

// 	while (1)
// 	{
// 		c1 = access8stream(input, v1);
// 		c2 = access8stream(input, v2);
// 		if (!c1 || !c2)
// 			return -1;
// 		if (*c1 != *c2)
// 			return -1;
// 		if (*c1 == '\0')
// 			break ;
// 		v1++;
// 		v2++;
// 	}
// 	return 0;
// }

// t_32b lookup(t_hashmap *hashmap, t_8stream *input, t_32b value)
// {
// 	t_32b index = djb2(input, value) % HASHMAP_SIZE;

// 	// printf("Lookup key %u:\n", value);
// 	// print_stream_word(input, value);
// 	// write(1, "\n", 1);
// 	// printf("Fin lookup\n");

// 	while (1) // Un probleme : le cas ou on est full full et qu'o connait pas la key on boucle a l'infinie
// 	{
// 		int i = 0;
// 		while (hashmap->rows[index].index[i] != UINT_MAX && i < 16)
// 		{
// 			if (sscmp(input, hashmap->rows[index].index[i], value) == 0)
// 				return hashmap->rows[index].index[i];
// 			i++;
// 		}

// 		if (i < 16)
// 			return UINT_MAX;

// 		index = hash_u32(index);
// 	}
// }
#include "vector.h"

size_t	djb2(t_vector *vec, size_t index)
{
	size_t	hash;
	size_t	i;

	hash = 5381;
	i = index;
	while (vec->data[i])
	{
		hash = ((hash << 5) + hash) + (unsigned char)vec->data[i];
		i++;
	}
	return hash;
	// bucket = accesscreat64stream(hashstream, hash & BUF64SIZE);
	// if (!bucket)
		// return ;
	// else
		// *bucket = index;
}

void insert(t_hashmap *hashmap, t_vector *vec, t_32b value)
{
	// static int nbinserted = 0;

	// if (nbinserted % 10000 == 0) printf("Inserted %d values\n", nbinserted);
	// nbinserted++;

	t_32b index = djb2(vec, value) % HASHMAP_SIZE;

	// printf("Insert:\n");
	// print_stream_word(input, value);
	// write(1, "\n", 1);
	// printf("Fin insert\n");
	
	while (1) // Un probleme : le cas ou on a plus de place du tout donc a voir pour une limite quand meme
	{	
		int i = 0;

		
		while (hashmap->rows[index].index[i] != UINT_MAX && i < 16)
		{
			// printf("%u %p\n", hashmap->rows[index].index[i], (&hashmap->rows[index].index1 + i));
			i++;
		}

		if (i < 16)
		{
			hashmap->rows[index].index[i] = value;
			return ;
		}

		index = hash_u32(index);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

t_32b lookup(t_hashmap *hashmap, t_vector *vec, t_32b value)
{
	t_32b index = djb2(vec, value) % HASHMAP_SIZE;

	// printf("Lookup key %u:\n", value);
	// print_stream_word(input, value);
	// write(1, "\n", 1);
	// printf("Fin lookup\n");

	while (1) // Un probleme : le cas ou on est full full et qu'o connait pas la key on boucle a l'infinie
	{
		int i = 0;
		while (hashmap->rows[index].index[i] != UINT_MAX && i < 16)
		{
			if (ft_strcmp(vec->data + hashmap->rows[index].index[i], vec->data + value) == 0)
				return hashmap->rows[index].index[i];
			i++;
		}

		if (i < 16)
			return UINT_MAX;

		index = hash_u32(index);
	}
}
