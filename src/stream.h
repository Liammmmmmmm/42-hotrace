/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 09:33:26 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 09:38:01 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAM_H
# define STREAM_H

# include <stddef.h>

# define BUFFER_SIZE 64000

typedef struct s_buffer
{
	struct s_buffer	*next;
	char			*buffer;
	size_t			inx;
	size_t			outx;
}	t_buffer;

typedef struct s_stream
{
	t_buffer	*out;
	t_buffer	*in;
}	t_stream;

char	stream_getc(t_stream *stream, char *c);
int		stream_add_buffer(t_stream *stream);
long	read_stream(t_stream *stream, int fd);

#endif