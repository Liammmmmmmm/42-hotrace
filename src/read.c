/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 12:23:30 by lilefebv          #+#    #+#             */
/*   Updated: 2026/03/01 13:58:02 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "hashmap.h"
#include "stdint.h"
#include <unistd.h>
#include <stdio.h>

#define READ_SIZE 100000

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void parse_content(t_vector *vec, t_hashmap *hashmap, size_t *parse_cursor)
{
	static uint32_t	wordpos = UINT32_MAX;
	static uint8_t	is_key = 1;
	static uint8_t	search_mode = 0;

	while (*parse_cursor < vec->num_elements)
	{
		if (!vec->data[*parse_cursor])
		{
			--(*parse_cursor);
			while (*parse_cursor > 0 && vec->data[*parse_cursor])
				--(*parse_cursor);
			if (!vec->data[*parse_cursor])
				++(*parse_cursor);
			return ;
		}
		else if (vec->data[*parse_cursor] == '\n')
		{
			vec->data[*parse_cursor] = 0;
			if (search_mode)
			{
				if (wordpos != UINT32_MAX)
				{
					t_32b index = lookup(hashmap, vec, wordpos);
					if (index == UINT32_MAX)
					{
						ft_putstr(vec->data + wordpos);
						write(1, ": Not found.\n", 13);
					}
					else
					{
						size_t	y = index;
						while (vec->data[y])
							y++;
						y++;
						ft_putstr(vec->data + y);
						write(1, "\n", 1);
					}
				}
			}
			else
			{
				if (wordpos == UINT32_MAX)
					search_mode = 1;
				else if (is_key)
				{
					insert(hashmap, vec, wordpos);
					is_key = 0;
				}
				else if (!is_key)
				{
					is_key = 1;
				}
			}
			wordpos = UINT32_MAX;
		}
		else if (wordpos == UINT32_MAX)
			wordpos = *parse_cursor;

		++(*parse_cursor);
	}
}

int	read_pro_max(t_vector *vec, t_hashmap *hashmap)
{
	ssize_t	n;
	size_t parse_cursor;

	parse_cursor = 0;
	n = 1;
	while (n > 0)
	{
		if (vec->max_elements - vec->num_elements < READ_SIZE)
		{
			if (vector_realloc(vec) == -1)
				return (-1);
		}
		n = read(0, vec->data + vec->num_elements, READ_SIZE - 1);
		if (n == -1)
			return (-1);
		else if (n == 0)
			return (0);
		vec->data[vec->num_elements + n] = 0;
		vec->num_elements += n;
		parse_content(vec, hashmap, &parse_cursor);
	}
	return (0);
}
