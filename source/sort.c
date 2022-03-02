/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:50:17 by asippy            #+#    #+#             */
/*   Updated: 2022/03/02 22:55:57 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

static size_t	ft_special_cases(t_stack **stack, size_t length)
{
	t_stack	*iter;

	if (length == 1)
		return (1);
	iter = *stack;
	while (iter->next->next != (void *)0 && iter->value < iter->next->value)
		iter = iter->next;
	if (iter->next->next == (void *)0 && iter->value < iter->next->value)
		return (1);
	if (length == 2)
	{
		ft_ra(stack);
		return (1);
	}
	return (0);
}

static void	ft_butterfly_to_b(t_stack **a, t_stack **b, size_t length)
{
	size_t	iter;

	iter = 0;
	while (iter < length)
	{
		if ((*a)->value <= iter)
		{
			ft_pb(a, b);
			ft_rb(b);
			iter++;
		}
		else if ((*a)->value <= iter + 1)
		{
			ft_pb(a, b);
			iter++;
		}
		else
			ft_ra(a);
	}
	return ;
}

static void	ft_butterfly_to_a(t_stack **a, t_stack **b, size_t length)
{
	size_t	iter;
	t_stack	*buf;

	iter = 0;
	while (iter < length)
	{
		buf = *b;
		while (buf->next != (void *)0)
			buf = buf->next;
		if ((*b)->value >= buf->value)
			ft_pa(a, b);
		else
		{
			ft_rrb(b);
			ft_pa(a, b);
		}
		iter++;
	}
	return ;
}

void	ft_sort(t_stack **stack_a, size_t length)
{
	t_stack	*stack_b;

	stack_b = (void *)0;
	if (!ft_special_cases(stack_a, length))
	{
		ft_butterfly_to_b(stack_a, &stack_b, length);
		ft_print_stack(*stack_a, "CHANGED A:");
		ft_print_stack(stack_b, "CHANGED B:");
		ft_butterfly_to_a(stack_a, &stack_b, length);
	}
	ft_print_stack(*stack_a, "SORTED A:");
	ft_print_stack(stack_b, "SORTED B:");
	return ;
}
