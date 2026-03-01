/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 09:33:26 by ethebaul          #+#    #+#             */
/*   Updated: 2026/03/01 14:23:18 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAM_H
# define STREAM_H

# include <stddef.h>

# define BUFSIZE	0xFFFF

# define BUF8SIZE	BUFSIZE

typedef struct s_8buf
{
	struct s_8buf	*next;
	char			*buf;
	size_t			inx;
	size_t			outx;
}	t_8buf;

typedef struct s_8stream
{
	t_8buf	*out;
	t_8buf	*in;
}	t_8stream;

void	init8stream(t_8stream *stream);
void	dest8stream(t_8stream *stream);
int		ext8stream(t_8stream *stream);
int		zext8stream(t_8stream *stream);
size_t	len8stream(t_8stream *stream);
int		push8stream(t_8stream *stream, char c);
int		take8stream(t_8stream *stream, char *c);
char	*access8stream(t_8stream *stream, size_t index);
int		read8stream(t_8stream *stream, int fd);
int		write8stream(t_8stream *stream, int fd);
void	print8stream(t_8stream *stream, size_t index);
char	*accesscreat8stream(t_8stream *stream, size_t index);

# define BUF64SIZE	BUFSIZE

typedef struct s_64buf
{
	struct s_64buf	*next;
	size_t			*buf;
	size_t			inx;
	size_t			outx;
}	t_64buf;

typedef struct s_64stream
{
	t_64buf	*out;
	t_64buf	*in;
}	t_64stream;

void	init64stream(t_64stream *stream);
void	dest64stream(t_64stream *stream);
int		ext64stream(t_64stream *stream);
int		zext64stream(t_64stream *stream);
size_t	len64stream(t_64stream *stream);
int		push64stream(t_64stream *stream, char c);
int		take64stream(t_64stream *stream, char *c);
size_t	*access64stream(t_64stream *stream, size_t index);
size_t	*accesscreat64stream(t_64stream *stream, size_t index);

#endif