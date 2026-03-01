/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:31:17 by ethebaul          #+#    #+#             */
/*   Updated: 2026/03/01 19:12:39 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "vector.h"
#include "syscall.h"

int	read_pro_max(t_vector *vec, t_hashmap *hashmap);

int	main(void)
{
	t_vector	vec;
	t_hashmap	hashmap;

	set_max_niceness();
	set_cpu_affinity();
	set_best_scheduler();
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
