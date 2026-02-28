/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 08:11:42 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 21:00:11 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stream.h"
#include "utils.h"

void	init8stream(t_8stream *stream)
{
	stream->in = NULL;
	stream->out = NULL;
}

void	dest8stream(t_8stream *stream)
{
	t_8buf	*tmp;

	while (stream->out)
	{
		tmp = stream->out;
		stream->out = stream->out->next;
		free(tmp->buf);
		free(tmp);
	}
	stream->out = NULL;
	stream->in = NULL;
}

int	ext8stream(t_8stream *stream)
{
	t_8buf	*tmp;

	tmp = malloc(sizeof(t_8buf));
	if (!tmp)
		return (-1);
	tmp->next = NULL;
	tmp->inx = 0;
	tmp->outx = 0;
	tmp->buf = malloc(BUF8SIZE);
	if (!tmp->buf)
		return (-1);
	if (stream->in)
		stream->in->next = tmp;
	stream->in = tmp;
	if (!stream->out)
		stream->out = tmp;
	return (0);
}

int	zext8stream(t_8stream *stream)
{
	t_8buf	*tmp;

	if (smalloc(sizeof(t_8buf), (void *)&tmp))
		return (-1);
	tmp->next = NULL;
	tmp->inx = BUF8SIZE;
	tmp->outx = 0;
	if (zalloc(BUF8SIZE, (void *)&tmp->buf))
		return (-1);
	if (stream->in)
		stream->in->next = tmp;
	stream->in = tmp;
	if (!stream->out)
		stream->out = tmp;
	return (0);
}
