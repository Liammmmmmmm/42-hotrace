/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 08:11:42 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 09:15:27 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "types.h"

int	stream_add_buffer(t_stream *stream)
{
	t_buffer	*tmp;

	tmp = malloc(sizeof(t_buffer));
	if (!tmp)
		return (-1);
	tmp->next = NULL;
	tmp->in_head = 0;
	tmp->out_head = 0;
	tmp->buffer = malloc(BUFFER_SIZE);
	if (!tmp->buffer)
		return (-1);
	if (stream->current_in)
		stream->current_in->next = tmp;
	stream->current_in = tmp;
	return (0);
}

long	read_stream(t_stream *stream, int fd, char *buffer, size_t len)
{
	t_buffer	*tmp;
	long		size;

	if (!stream->current_in)
		if (stream_add_buffer(stream))
			return (-1);
	size = read(fd, stream->current_in->buffer, stream->current_capacity);
	if (size > 0)
		stream->current_capacity -= size;
	if (stream->current_capacity == 0)
	{
		tmp = malloc(sizeof(t_list));
		if (!tmp)
			return (-1);
		tmp->next = NULL;
		tmp->buffer = malloc(BUFFER_SIZE);
		if (!tmp->buffer)
			return (-1);
		stream->current_in->next = tmp;
		stream->current_in = tmp;
		stream->current_capacity = BUFFER_SIZE;
	}
	return (size);
}

char	stream_getc(t_stream *stream)
{
	t_buffer	*tmp;
	char		c;

	if (!stream->current_out)
		return (0);
	if (stream->current_out->out_head == stream->current_out->in_head)
		return (0);
	c = stream->current_out->buffer[stream->current_out->out_head];
	stream->current_out->out_head += 1;
	if (stream->current_out->out_head == BUFFER_SIZE)
	{
		tmp = stream->current_out;
		if (stream->current_in == tmp)
			stream->current_in = NULL;
		if (tmp->next)
			stream->current_out = tmp->next;
		free(tmp->buffer);
		free(tmp);
	}
	return (c);
}
