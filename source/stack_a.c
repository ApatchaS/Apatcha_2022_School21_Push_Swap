/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:43:58 by asippy            #+#    #+#             */
/*   Updated: 2022/03/03 15:39:21 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_create_stack_a(int **unsort_arr, int *sort_arr, size_t length)
{
	t_stack	*stack_a;
	size_t	i;
	size_t	j;

	i = 0;
	stack_a = (void *)0;
	while (i < length)
	{
		j = 0;
		while ((*unsort_arr)[i] != sort_arr[j])
			j++;
		ft_lstadd_back(&stack_a, ft_lstnew(j));
		i++;
	}
	free(*unsort_arr);
	return (stack_a);
}
