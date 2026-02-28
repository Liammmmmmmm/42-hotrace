/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:31:17 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 10:40:34 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include "stream.h"

int	main(void)
{
	t_stream	stream;
	int			fd;
	char		c;

	stream_init(&stream);
	while (stream_read(&stream, fd))
	{
		while (stream_getc(&stream, &c))
			;
	}
	stream_destroy(&stream);
	return (0);
}
