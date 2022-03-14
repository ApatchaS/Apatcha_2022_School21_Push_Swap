/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:27:49 by asippy            #+#    #+#             */
/*   Updated: 2022/03/14 16:40:58 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/checker_bonus.h"

t_stack	*ft_create_stack_a(t_arrays *arrays)
{
	t_stack	*stack_a;
	size_t	i;
	size_t	j;

	i = 0;
	stack_a = (void *)0;
	while (i < arrays->length)
	{
		j = 0;
		while (arrays->unsorted[i] != arrays->sorted[j])
			j++;
		ft_lstadd_back(&stack_a, ft_lstnew(j));
		i++;
	}
	free(arrays->unsorted);
	return (stack_a);
}
