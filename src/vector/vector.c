/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 12:22:46 by lilefebv          #+#    #+#             */
/*   Updated: 2026/03/01 15:37:45 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "utils.h"

int	vector_realloc(t_vector *vector)
{
	void	*new_data;

	new_data = malloc(vector->element_size * vector->max_elements * 2);
	if (new_data == NULL)
		return (-1);
	ft_charcpy(new_data, vector->data,
		vector->element_size * vector->num_elements);
	free(vector->data);
	vector->data = new_data;
	vector->max_elements *= 2;
	return (0);
}

int	vector_init(t_vector *vector, size_t default_size)
{
	vector->element_size = sizeof(char);
	vector->max_elements = default_size;
	vector->num_elements = 0;
	vector->data = malloc(sizeof(char) * default_size);
	if (vector->data == NULL)
		return (-1);
	return (0);
}
