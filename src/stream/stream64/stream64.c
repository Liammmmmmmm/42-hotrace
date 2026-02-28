/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream64.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 08:11:42 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 23:41:08 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stream.h"
#include "utils.h"

void	init64stream(t_64stream *stream)
{
	stream->in = NULL;
	stream->out = NULL;
}

void	dest64stream(t_64stream *stream)
{
	t_64buf	*tmp;

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

int	ext64stream(t_64stream *stream)
{
	t_64buf	*tmp;

	tmp = malloc(sizeof(t_64buf));
	if (!tmp)
		return (-1);
	tmp->next = NULL;
	tmp->inx = 0;
	tmp->outx = 0;
	tmp->buf = malloc(BUF64SIZE);
	if (!tmp->buf)
		return (-1);
	if (stream->in)
		stream->in->next = tmp;
	stream->in = tmp;
	if (!stream->out)
		stream->out = tmp;
	return (0);
}

int	zext64stream(t_64stream *stream)
{
	t_64buf	*tmp;

	if (smalloc(sizeof(t_64buf), (void *)&tmp))
		return (-1);
	tmp->next = NULL;
	tmp->inx = BUF64SIZE;
	tmp->outx = 0;
	if (zalloc(BUF64SIZE * sizeof(size_t), (void *)&tmp->buf))
		return (-1);
	if (stream->in)
		stream->in->next = tmp;
	stream->in = tmp;
	if (!stream->out)
		stream->out = tmp;
	return (0);
}
