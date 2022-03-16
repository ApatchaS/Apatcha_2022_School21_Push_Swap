/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:22:39 by asippy            #+#    #+#             */
/*   Updated: 2022/03/15 22:36:20 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	ft_lstadd_front(t_stack **stack, t_stack *new)
{
	if (new == (void *)0)
		return ;
	new->next = *stack;
	*stack = new;
	return ;
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

size_t	ft_lstsize(t_stack *stack)
{
	size_t	size;

	size = 0;
	while (stack != (void *)0)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
