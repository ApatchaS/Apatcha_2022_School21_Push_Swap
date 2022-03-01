/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:43:58 by asippy            #+#    #+#             */
/*   Updated: 2022/03/02 01:27:18 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

t_stack	*ft_lstnew(size_t value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == (void *)0)
		ft_print_error();
	new->value = value;
	new->next = (void *)0;
	return (new);
}

void	ft_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*iter;

	if (new == (void *)0)
		return ;
	if (*stack)
	{
		iter = *stack;
		while (iter->next != (void *)0)
			iter = iter->next;
		iter->next = new;
	}
	else
		*stack = new;
	return ;
}

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