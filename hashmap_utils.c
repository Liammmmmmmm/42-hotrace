/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:53:49 by bfitte            #+#    #+#             */
/*   Updated: 2026/03/01 18:56:28 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

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
	return (hash);
}
