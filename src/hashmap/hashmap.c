/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:54:07 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 23:42:25 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include "stream.h"

void	djb2(t_64stream *hashstream, t_8stream *input, size_t index)
{
	size_t	*bucket;
	size_t	hash;
	size_t	i;
	char	*c;

	hash = 5381;
	c = access8stream(input, index);
	i = index;
	while (*c)
	{
		hash = ((hash << 5) + hash) + (unsigned char)*c;
		i++;
		c = access8stream(input, i);
	}
	bucket = accesscreat64stream(hashstream, hash & BUF64SIZE);
	if (!bucket)
		return ;
	else
		*bucket = index;
}

int	init_hashmap(t_64stream *hashstream, t_8stream *inputstream)
{
	size_t	word;
	size_t	len;
	size_t	i;
	char	*c;

	i = 0;
	word = ULONG_MAX;
	len = len8stream(inputstream);
	while (i < len)
	{
		c = access8stream(inputstream, i);
		if (c == NULL)
			return (-1);
		if (*c == '\n')
		{
			*c = '\0';
			if (word != ULONG_MAX)
				djb2(hashstream, inputstream, word);
			word = ULONG_MAX;
		}
		else if (word == ULONG_MAX)
			word = i;
		++i;
	}
	return (0);
}
