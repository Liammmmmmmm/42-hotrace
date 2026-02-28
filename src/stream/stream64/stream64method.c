/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream64method.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:40:31 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 23:32:00 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stream.h"

size_t	len64stream(t_64stream *stream)
{
	t_64buf	*tmp;
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

int	push64stream(t_64stream *stream, char c)
{
	if (!stream->in)
		if (ext64stream(stream))
			return (-1);
	stream->in->buf[stream->in->inx] = c;
	stream->in->inx += 1;
	if (stream->in->inx == BUF64SIZE)
		if (ext64stream(stream))
			return (-1);
	return (0);
}

int	take64stream(t_64stream *stream, char *c)
{
	t_64buf	*tmp;

	if (!stream->out)
		return (0);
	if (stream->out->outx >= stream->out->inx)
		return (0);
	if (c)
		*c = stream->out->buf[stream->out->outx];
	stream->out->outx += 1;
	if (stream->out->outx >= BUF64SIZE)
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

size_t	*access64stream(t_64stream *stream, size_t index)
{
	t_64buf	*tmp;
	size_t	*c;

	c = 0;
	if (!stream->out)
		return (0);
	tmp = stream->out;
	while (tmp)
	{
		if (index < tmp->inx && index >= tmp->outx)
		{
			c = &tmp->buf[index];
			return (c);
		}
		else
			index -= tmp->inx;
		tmp = tmp->next;
	}
	return (c);
}

size_t	*accesscreat64stream(t_64stream *stream, size_t index)
{
	t_64buf	*tmp;
	size_t	*c;

	c = 0;
	if (!stream->out)
		zext64stream(stream);
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
			zext64stream(stream);
		tmp = tmp->next;
	}
	return (c);
}
