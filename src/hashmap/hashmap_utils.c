/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:53:49 by bfitte            #+#    #+#             */
/*   Updated: 2026/03/01 15:41:24 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

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
