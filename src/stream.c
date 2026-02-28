/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 08:11:42 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 15:58:36 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "stream.h"

void	stream_init(t_stream *stream)
{
	stream->in = NULL;
	stream->out = NULL;
}

void	stream_destroy(t_stream *stream)
{
	t_buffer	*tmp;

	while (stream->out)
	{
		tmp = stream->out;
		stream->out = stream->out->next;
		free(tmp->buffer);
		free(tmp);
	}
	stream->out = NULL;
	stream->in = NULL;
}

int	stream_add_buffer(t_stream *stream)
{
	t_buffer	*tmp;

	tmp = malloc(sizeof(t_buffer));
	if (!tmp)
		return (-1);
	tmp->next = NULL;
	tmp->inx = 0;
	tmp->outx = 0;
	tmp->buffer = malloc(BUFFER_SIZE);
	if (!tmp->buffer)
		return (-1);
	if (stream->in)
		stream->in->next = tmp;
	stream->in = tmp;
	if (!stream->out)
		stream->out = tmp;
	return (0);
}

long	stream_read(t_stream *stream, int fd)
{
	long	size;
	size_t	inx;

	if (!stream->in)
		if (stream_add_buffer(stream))
			return (-1);
	inx = stream->in->inx;
	size = read(fd, &stream->in->buffer[inx], BUFFER_SIZE - stream->in->inx);
	if (size > 0)
		stream->in->inx += size;
	if (stream->in->inx == BUFFER_SIZE)
		if (stream_add_buffer(stream))
			return (-1);
	return (size);
}

char	stream_getc(t_stream *stream, char *c)
{
	t_buffer	*tmp;

	if (!stream->out)
		return (0);
	if (stream->out->outx >= stream->out->inx)
		return (0);
	if (c)
		*c = stream->out->buffer[stream->out->outx];
	stream->out->outx += 1;
	if (stream->out->outx >= BUFFER_SIZE)
	{
		tmp = stream->out;
		stream->out = stream->out->next;
		if (stream->in == tmp)
			stream->in = NULL;
		free(tmp->buffer);
		free(tmp);
	}
	return (1);
}
