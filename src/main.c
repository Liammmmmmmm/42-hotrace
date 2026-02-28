/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:31:17 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 16:12:23 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "stream.h"
#include "utils.h"
#include <stdio.h>

int	align(t_stream *stream, size_t i, t_phase *phase, size_t *search)
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
		*search = stream_len(stream);
	return (0);
}

int	parse_input(t_stream *stream, size_t *search, char *buffer)
{
	t_phase		phase;
	long		size;
	long		i;

	phase = DEFAULT;
	size = 0;
	while (!sread(0, buffer, CACHE_LINE, &size))
	{
		i = 0;
		while (i < size)
		{
			if (buffer[i] == '\n')
				if (align(stream, i, &phase, search))
					return (-1);
			if (buffer[i] != '\n')
			{
				phase = DEFAULT;
				if (stream_pushc(stream, buffer[i]))
					return (-1);
			}
			++i;
		}
	}
	return (size);
}

int	main(void)
{
	char		*buffer;
	t_stream	stream;
	size_t		search;
	size_t		i;
	char		c;

	search = 0;
	stream_init(&stream);
	if (smalloc(CACHE_LINE, (void *)&buffer))
		return (-1);
	if (parse_input(&stream, &search, buffer))
		return (1);
	i = 0;
	while (stream_getc(&stream, &c))
	{
		if (i > search && search != 0)
		{
			printf("SEARCHING\n");
			search = 0;
		}
		write(1, &c, 1);
		++i;
	}
	stream_destroy(&stream);
	free(buffer);
	return (0);
}


// int	main(void)
// {
// 	t_stream	stream;
// 	char		c;

// 	stream_init(&stream);
// 	while (stream_read(&stream, 0))
// 		;
// 	printf("[%zu]\n", stream_len(&stream));
// 	while (stream_getc(&stream, &c))
// 		write(1, &c, 1);
// 	stream_destroy(&stream);
// 	return (0);
// }
