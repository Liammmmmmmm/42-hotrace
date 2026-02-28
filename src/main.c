/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:31:17 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/28 22:52:28 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stream.h"
#include "hashmap.h"

int	main(void)
{
	t_8stream	input;
	t_64stream	hashmap;

	init8stream(&input);
	init64stream(&hashmap);
	if (read8stream(&input, 0))
		return (1);
	if (init_hashmap(&hashmap, &input))
		return (1);
	dest8stream(&input);
	dest64stream(&hashmap);
	return (0);
}
