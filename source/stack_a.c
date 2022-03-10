/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:43:58 by asippy            #+#    #+#             */
/*   Updated: 2022/03/10 22:38:37 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
