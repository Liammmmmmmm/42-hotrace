/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 09:33:26 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 09:57:28 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAM_H
# define STREAM_H

# include <stddef.h>

# define BUFFER_SIZE 8

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

void	stream_init(t_stream *stream);
void	stream_destroy(t_stream *stream);
char	stream_getc(t_stream *stream, char *c);
int		stream_add_buffer(t_stream *stream);
long	stream_read(t_stream *stream, int fd);

#endif