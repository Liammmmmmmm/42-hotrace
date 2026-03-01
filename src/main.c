/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:31:17 by ethebaul          #+#    #+#             */
/*   Updated: 2026/03/01 10:34:50 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stream.h"
#include "hashmap.h"

int	main(void)
{
	t_8stream	input;
	// t_64stream	hashmap;
	t_hashmap	hashmap;

	init8stream(&input);
	// init64stream(&hashmap);
	if (read8stream(&input, 0))
		return (1);
	if (init_hashmap(&hashmap))
		return (1);
	
	size_t index = fill_values(&hashmap, &input);
	find_values(&hashmap, &input, index);

	dest8stream(&input);
	// dest64stream(&hashmap);
	destroy_hashmap(&hashmap);
	return (0);
}
