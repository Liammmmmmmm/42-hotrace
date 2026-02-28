/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_ext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:45:17 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 16:07:41 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "stream.h"

int	stream_pushc(t_stream *stream, char c)
{
	if (!stream->in)
		if (stream_add_buffer(stream))
			return (-1);
	stream->in->buffer[stream->in->inx] = c;
	stream->in->inx += 1;
	if (stream->in->inx == BUFFER_SIZE)
		if (stream_add_buffer(stream))
			return (-1);
	return (0);
}

char	stream_getx(t_stream *stream, char *c, size_t index)
{
	t_buffer	*tmp;

	if (!stream->out)
		return (0);
	tmp = stream->out;
	while (tmp)
	{
		if (index < tmp->inx)
		{
			*c = tmp->buffer[index];
			return (1);
		}
		else
			index -= tmp->inx;
		tmp = tmp->next;
	}
	return (0);
}

size_t	stream_len(t_stream *stream)
{
	t_buffer	*tmp;
	size_t		len;

	len = 0;
	tmp = stream->out;
	while (tmp)
	{
		len += tmp->inx;
		tmp = tmp->next;
	}
	return (len);
}
