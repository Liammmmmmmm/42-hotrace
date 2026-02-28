/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   djb2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 13:49:13 by bfitte            #+#    #+#             */
/*   Updated: 2026/02/28 14:06:58 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "../types.h"

uint64_t	djb2(t_stringv *str)
{
	uint64_t	hash;
	size_t			i;

	hash = 5381;
	i = 0;
	while (i < str->size)
		hash = ((hash << 5) + hash) + (unsigned char)str->ptr[i++];
	return (hash);
}
