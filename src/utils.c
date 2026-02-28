/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:37:08 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 15:05:35 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

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
	if (*ret <= 0)
		return (1);
	return (0);
}
