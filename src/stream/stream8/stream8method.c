/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream8method.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:40:31 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 23:32:17 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stream.h"

size_t	len8stream(t_8stream *stream)
{
	t_8buf	*tmp;
	size_t	len;

	len = 0;
	tmp = stream->out;
	while (tmp)
	{
		len += tmp->inx;
		tmp = tmp->next;
	}
	return (len);
}

int	push8stream(t_8stream *stream, char c)
{
	if (!stream->in)
		if (ext8stream(stream))
			return (-1);
	stream->in->buf[stream->in->inx] = c;
	stream->in->inx += 1;
	if (stream->in->inx == BUF8SIZE)
		if (ext8stream(stream))
			return (-1);
	return (0);
}

int	take8stream(t_8stream *stream, char *c)
{
	t_8buf	*tmp;

	if (!stream->out || stream->out->outx >= stream->out->inx)
		return (0);
	if (c)
		*c = stream->out->buf[stream->out->outx];
	stream->out->outx += 1;
	if (stream->out->outx >= BUF8SIZE)
	{
		tmp = stream->out;
		stream->out = stream->out->next;
		if (stream->in == tmp)
			stream->in = NULL;
		free(tmp->buf);
		free(tmp);
	}
	return (1);
}

char	*access8stream(t_8stream *stream, size_t index)
{
	t_8buf	*tmp;
	char	*c;

	c = 0;
	if (!stream->out)
		return (0);
	tmp = stream->out;
	while (tmp)
	{
		if (index < tmp->inx && index >= tmp->outx)
		{
			c = &tmp->buf[index + tmp->outx];
			return (c);
		}
		else
			index -= (tmp->inx - tmp->outx);
		tmp = tmp->next;
	}
	return (c);
}

char	*accesscreat8stream(t_8stream *stream, size_t index)
{
	t_8buf	*tmp;
	char	*c;

	c = 0;
	if (!stream->out)
		zext8stream(stream);
	tmp = stream->out;
	while (tmp)
	{
		if (index < tmp->inx && index >= tmp->outx)
		{
			c = &tmp->buf[index + tmp->outx];
			return (c);
		}
		else
			index -= (tmp->inx - tmp->outx);
		if (tmp->next == NULL)
			zext8stream(stream);
		tmp = tmp->next;
	}
	return (c);
}
