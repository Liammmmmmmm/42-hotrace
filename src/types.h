/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:31:12 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 13:38:38 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

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

#endif