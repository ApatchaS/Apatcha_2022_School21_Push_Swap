/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:50:17 by asippy            #+#    #+#             */
/*   Updated: 2022/03/10 23:25:00 by asippy           ###   ########.fr       */
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

static void	ft_butterfly_to_b(t_stacks *stacks)
{
	size_t	iter;

	iter = 0;
	stacks->b_len = 0;
	while (stacks->a_len != 0)
	{
		if (stacks->a->value <= iter)
		{
			ft_pb(&stacks->a, &stacks->b);
			ft_rb(&stacks->b);
			iter++;
			stacks->a_len--;
			stacks->b_len++;
		}
		else if (stacks->a->value <= iter + 1)
		{
			ft_pb(&stacks->a, &stacks->b);
			iter++;
			stacks->a_len--;
			stacks->b_len++;
		}
		else
			ft_ra(&stacks->a);
	}
	return ;
}

static void	ft_butterfly_to_a(t_stacks *stacks)
{
	t_stack	*buf;

	while (stacks->b_len != 0)
	{
		buf = stacks->b;
		while (buf->next != (void *)0)
			buf = buf->next;
		if (stacks->b->value >= buf->value)
			ft_pa(&stacks->a, &stacks->b);
		else
		{
			ft_rrb(&stacks->b);
			ft_pa(&stacks->a, &stacks->b);
		}
		stacks->b_len--;
		stacks->a_len++;
	}
	return ;
}

void	ft_sort(t_stacks *stacks)
{
	stacks->b = (void *)0;
	if (!ft_special_cases(&stacks->a, stacks->a_len))
	{
		ft_butterfly_to_b(stacks);

		printf("A CHANGED LENGTH: %lu\n", stacks->a_len);
		ft_print_stack(stacks->a, "A CHANGED:");
		printf("B CHANGED LENGTH: %lu\n", stacks->b_len);
		ft_print_stack(stacks->b, "B CHANGED:");

		ft_butterfly_to_a(stacks);
	}

	printf("A SORTED LENGTH: %lu\n", stacks->a_len);
	ft_print_stack(stacks->a, "A SORTED:");
	printf("B SORTED LENGTH: %lu\n", stacks->b_len);
	ft_print_stack(stacks->b, "B SORTED:");

	return ;
}
