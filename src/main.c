/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:31:17 by ethebaul          #+#    #+#             */
/*   Updated: 2026/03/01 18:01:08 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "vector.h"

int	read_pro_max(t_vector *vec, t_hashmap *hashmap);

void	concentre_toi(void)
{
	__asm__ volatile (
		"mov $141, %%rax \n\t"
		"xor %%rdi, %%rdi \n\t"
		"xor %%rsi, %%rsi \n\t"
		"mov $-20, %%rdx \n\t"
		"syscall"
		: : : "rax", "rdi", "rsi", "rdx", "rcx", "r11"
	);
}

int	main(void)
{
	t_vector	vec;
	t_hashmap	hashmap;

	CONCENTRE_TOI();
	if (vector_init(&vec, 30000000))
		return (1);
	if (init_hashmap(&hashmap))
	{
		free(vec.data);
		return (1);
	}
	if (read_pro_max(&vec, &hashmap))
	{
		free(vec.data);
		destroy_hashmap(&hashmap);
		return (1);
	}
	free(vec.data);
	destroy_hashmap(&hashmap);
	return (0);
}
