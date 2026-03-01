/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream8io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:14:55 by ethebaul          #+#    #+#             */
/*   Updated: 2026/03/01 11:19:57 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stream.h"
#include "utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	read8stream(t_8stream *stream, int fd)
{
	long	result;
	size_t	tmpv;

	result = 1;
	while (result)
	{
		if (!stream->in)
			if (ext8stream(stream))
				return (-1);
		tmpv = stream->in->inx;
		if (sread(fd, &stream->in->buf[tmpv], BUF8SIZE - tmpv, &result))
			return (-1);
		stream->in->inx += result;
		if (stream->in->inx >= BUF8SIZE)
			if (ext8stream(stream))
				return (-1);
	}
	push8stream(stream, '\n');
	return (result);
}

int	write8stream(t_8stream *stream, int fd)
{
	t_8buf	*tmp;
	size_t	tmpv;

	while (stream->out)
	{
		if (stream->out->outx >= stream->out->inx)
			return (0);
		tmpv = stream->out->outx;
		if (write(fd, &stream->out->buf[tmpv], stream->out->inx - tmpv) < 0)
			return (-1);
		stream->out->outx += stream->out->inx - stream->out->outx;
		if (stream->out->outx >= BUF8SIZE)
		{
			tmp = stream->out;
			stream->out = stream->out->next;
			if (stream->in == tmp)
				stream->in = NULL;
			free(tmp->buf);
			free(tmp);
		}
	}
	return (0);
}

void	print8stream(t_8stream *stream, size_t index)
{
	char	*c;

	c = access8stream(stream, index);
	if (c == NULL)
		return ;
	index++;
	while (*c)
	{
		write(1, c, 1);
		c = access8stream(stream, index);
		index++;
	}
	write(1, "\n", 1);
}
