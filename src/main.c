/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:31:17 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 09:55:14 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "stream.h"

int	main(void)
{
	t_stream	stream;
	char		c;

	stream_init(&stream);
	while (stream_read(&stream, 0))
	{
		while (stream_getc(&stream, &c))
			write(1, &c, 1);
	}
	stream_destroy(&stream);
	return (0);
}
