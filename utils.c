/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:37:08 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 20:35:47 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

int	zalloc(size_t size, void **ret)
{
	size_t	i;

	if (smalloc(size, ret))
		return (-1);
	i = 0;
	while (i < size)
	{
		((char *)*ret)[i] = 0;
		++i;
	}
	return (0);
}

int	smalloc(size_t size, void **ret)
{
	*ret = malloc(size);
	if (*ret == NULL)
		return (1);
	return (0);
}

int	sread(int fd, char *buf, size_t len, long *ret)
{
	*ret = read(fd, buf, len);
	if (*ret < 0)
		return (-1);
	return (0);
}
