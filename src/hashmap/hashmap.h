/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:09:05 by ethebaul          #+#    #+#             */
/*   Updated: 2026/03/01 10:47:58 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include "stream.h"
# include "utils.h"

# define HASHMAP_SIZE 1000000

typedef struct __attribute__((aligned(16))) s_row
{
	t_32b index1;
	t_32b index2;
	t_32b index3;
	t_32b index4;
	t_32b index5;
	t_32b index6;
	t_32b index7;
	t_32b index8;
	t_32b index9;
	t_32b index10;
	t_32b index11;
	t_32b index12;
	t_32b index13;
	t_32b index14;
	t_32b index15;
	t_32b index16;
}	t_row;

typedef struct s_hashmap
{
	t_row *rows;
}	t_hashmap;

// int	init_hashmap(t_64stream *hashstream, t_8stream *inputstream);


int init_hashmap(t_hashmap *hashmap);
void destroy_hashmap(t_hashmap *hashmap);

void find_values(t_hashmap *hashmap, t_8stream *inputstream, size_t start);
size_t fill_values(t_hashmap *hashmap, t_8stream *inputstream);

void	insert(t_hashmap *hashmap, t_8stream *input, t_32b value);
t_32b	lookup(t_hashmap *hashmap, t_8stream *input, t_32b value);

#endif