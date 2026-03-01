/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:09:05 by ethebaul          #+#    #+#             */
/*   Updated: 2026/03/01 15:35:54 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include "stream.h"
# include "vector.h"
# include "utils.h"

# define HASHMAP_SIZE 10000000

typedef struct __attribute__((aligned(16))) s_row
{
	t_32b	index[16];
}	t_row;

typedef struct s_hashmap
{
	t_row	*rows;
}	t_hashmap;

int		init_hashmap(t_hashmap *hashmap);
void	destroy_hashmap(t_hashmap *hashmap);

size_t	djb2(t_vector *vec, size_t index);
int		ft_strcmp(char *s1, char *s2);

t_32b	lookup(t_hashmap *hashmap, t_vector *vec, t_32b value);
void	insert(t_hashmap *hashmap, t_vector *vec, t_32b value);

size_t	ft_strlen(char *str);
void	ft_putstr(char *str);

#endif