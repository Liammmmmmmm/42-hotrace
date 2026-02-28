/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:31:17 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 09:21:12 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "types.h"

int	main(void)
{
	t_stream	stdin_stream;
	char		*buffer;
	size_t		size;
	size_t		i;

	buffer = malloc(64000);
	if (!buffer)
		return (1);
	size = read(0, buffer, 64000);
	while (size)
	{
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				buffer[i] = '\0';
				printf("Key[%s]\n", buffer);
			}
			++i;
		}
		size = read(0, buffer, 64000);
	}
	return (0);
}
