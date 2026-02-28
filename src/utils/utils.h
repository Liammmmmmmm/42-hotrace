/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:31:12 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 20:36:48 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

typedef unsigned char	t_8b;
typedef unsigned short	t_16b;
typedef unsigned int	t_32b;
typedef unsigned long	t_64b;

int	zalloc(size_t size, void **ret);
int	smalloc(size_t size, void **ret);
int	sread(int fd, char *buf, size_t len, long *ret);

#endif