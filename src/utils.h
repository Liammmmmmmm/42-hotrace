/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:31:12 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 17:12:33 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "stream.h"
# include <stddef.h>

typedef unsigned char	t_8b;
typedef unsigned short	t_16b;
typedef unsigned int	t_32b;
typedef unsigned long	t_64b;

typedef struct s_stringv
{
	char	*ptr;
	size_t	size;
}	t_stringv;

typedef enum e_phase
{
	DEFAULT,
	EOL,
	ERROR
}	t_phase;

int	smalloc(size_t size, void **ret);
int	sread(int fd, char *buf, size_t len, long *ret);

int	align(t_stream *stream, size_t i, t_phase *phase, size_t *search);
int	parse_input(t_stream *stream, size_t *search);
int	parse_buffer(t_stream *stream, size_t *srch, t_stringv buf, t_phase *phase);


#endif