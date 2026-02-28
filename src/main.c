/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:31:17 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 17:11:54 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "stream.h"
#include "utils.h"
#include <stdio.h>


int	main(void)
{
	t_stream	stream;
	size_t		search;

	search = 0;
	stream_init(&stream);
	if (parse_input(&stream, &search))
		return (1);
	stream_destroy(&stream);
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
