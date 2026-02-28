/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   murmur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:25:16 by bfitte            #+#    #+#             */
/*   Updated: 2026/02/28 15:06:59 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "../types.h"

uint64_t	last_bytes(uint64_t h, const unsigned char *data, size_t len,
	const uint64_t m)
{
	int	r;

	r = 47;
	if ((len & 7) == 7)
		h ^= ((uint64_t)data[6]) << 48;
	if ((len & 7) >= 6)
		h ^= ((uint64_t)data[5]) << 40;
	if ((len & 7) >= 5)
		h ^= ((uint64_t)data[4]) << 32;
	if ((len & 7) >= 4)
		h ^= ((uint64_t)data[3]) << 24;
	if ((len & 7) >= 3)
		h ^= ((uint64_t)data[2]) << 16;
	if ((len & 7) >= 2)
		h ^= ((uint64_t)data[1]) << 8;
	if ((len & 7) >= 1)
	{
		h ^= ((uint64_t)data[0]);
		h *= m;
	}
	h ^= h >> r;
	h *= m;
	h ^= h >> r;
	return (h);
}

uint64_t	murmurhash64(t_stringv *str, uint64_t seed)
{
	const uint64_t	m = 0xc6a4a7935bd1e995ULL;
	uint64_t		h;
	const uint64_t	*data;
	const uint64_t	*end;
	uint64_t		k;

	h = seed ^ (str->size * m);
	data = (const uint64_t *)str->ptr;
	end = data + (str->size / 32);
	while (data != end)
	{
		k = *data++;
		k *= m;
		k ^= k >> 47;
		k *= m;
		h ^= k;
		h *= m;
	}
	return (last_bytes(h, (const unsigned char *)data, str->size, m));
}
