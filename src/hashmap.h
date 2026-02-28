/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:25:12 by lilefebv          #+#    #+#             */
/*   Updated: 2026/02/28 12:27:49 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include <stdint.h>
# include "types.h"

# define HASHMAP_SIZE 1000000

// typedef union u_pos
// {
// 	uint32_t condensed;
// 	struct {
// 		uint32_t tab:11;
// 		uint32_t index:21;
// 	};
// }	t_pos;

typedef struct __attribute__((aligned(16))) s_row
{
	uint32_t index1;
	uint32_t index2;
	uint32_t index3;
	uint32_t index4;
	uint32_t index5;
	uint32_t index6;
	uint32_t index7;
	uint32_t index8;
	uint32_t index9;
	uint32_t index10;
	uint32_t index11;
	uint32_t index12;
	uint32_t index13;
	uint32_t index14;
	uint32_t index15;
	uint32_t index16;
}	t_row;

typedef struct s_hashmap
{
	// uint32_t size;
	t_row *rows;
	// char *tabs[2048];
}	hashmap_t;

int init_hashmap(hashmap_t *hashmap);
void destroy_hashmap(hashmap_t *hashmap);

/**
 * Insert a key in the hashmap
 * 
 * @param index The index of the key in the memory
 */
void insert(hashmap_t *hashmap, uint32_t index);

uint32_t lookup(hashmap_t *hashmap, char *key);

#endif

// char *data = key1\0value1\0key2\0value2