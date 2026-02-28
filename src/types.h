/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:31:12 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 09:29:19 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stddef.h>
# define BUFFER_SIZE 64000

typedef unsigned char	t_8b;
typedef unsigned short	t_16b;
typedef unsigned int	t_32b;
typedef unsigned long	t_64b;

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

#endif