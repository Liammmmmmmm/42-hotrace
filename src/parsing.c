/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:44:53 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 17:13:57 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "stream.h"

int	align(t_stream *stream, size_t i, t_phase *phase, size_t *srch)
{
	while (i % 32 > 0)
	{
		if (stream_pushc(stream, '\0'))
			return (-1);
		++i;
	}
	if (*phase == DEFAULT)
		*phase = EOL;
	else if (*phase == EOL)
		*srch = stream_len(stream);
	return (0);
}

int	parse_buffer(t_stream *stream, size_t *srch, t_stringv buf, t_phase *phase)
{
	size_t		i;

	i = 0;
	while (i < buf.size)
	{
		if (buf.ptr[i] == '\n')
			if (align(stream, i, phase, srch))
				return (-1);
		if (buf.ptr[i] != '\n')
		{
			*phase = DEFAULT;
			if (stream_pushc(stream, buf.ptr[i]))
				return (-1);
		}
		++i;
	}
	return (0);
}

int	parse_input(t_stream *stream, size_t *srch)
{
	t_stringv	buffer;
	t_phase		phase;
	long		size;

	size = 0;
	phase = DEFAULT;
	if (smalloc(CACHE_LINE, (void *)&buffer.ptr))
		return (-1);
	while (!sread(0, buffer.ptr, CACHE_LINE, &size))
	{
		buffer.size = size;
		parse_buffer(stream, srch, buffer, &phase);
	}
	return (size);
}
