/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:00:39 by asippy            #+#    #+#             */
/*   Updated: 2022/03/02 23:42:07 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	
	ft_lstadd_front(a, ft_lstnew((*b)->value));
	tmp = (*b)->next;
	free(*b);
	*b = tmp;
	write(1, "pa\n", 3);
	return ;
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	ft_lstadd_front(b, ft_lstnew((*a)->value));
	tmp = (*a)->next;
	free(*a);
	*a = tmp;
	write(1, "pb\n", 3);
	return ;
}

void	ft_ra(t_stack **a)
{
	t_stack	*tmp;
	
	if (ft_lstsize(*a) < 2)
		return ;
	ft_lstadd_back(a, ft_lstnew((*a)->value));
	tmp = (*a)->next;
	free(*a);
	*a = tmp;
	write(1, "ra\n", 3);
	return ;
}

void	ft_rb(t_stack **b)
{
	t_stack	*tmp;
	
	if (ft_lstsize(*b) < 2)
		return ;
	ft_lstadd_back(b, ft_lstnew((*b)->value));
	tmp = (*b)->next;
	free(*b);
	*b = tmp;
	write(1, "rb\n", 3);
	return ;
}
void	ft_rrb(t_stack **b)
{
	t_stack *iter;

	if (ft_lstsize(*b) < 2)
		return ;
	iter = *b;
	while (iter->next->next != (void *)0)
		iter = iter->next;
	ft_lstadd_front(b, ft_lstnew(iter->next->value));
	iter->next = (void *)0;
	free(iter->next);
	write(1, "rrb\n", 4);
	return ;
/*
	t_stack *iter;
	t_stack *jter;

	iter = *b;
	while (iter->next != (void *)0)
		iter = iter->next;
	ft_lstadd_front(b, ft_lstnew(iter->value));
	jter = *b;
	while (jter->next != iter)
		jter = jter->next;
	jter->next = (void *)0;
	free(iter);
	write(1, "rrb\n", 4);
	return ;
*/
}
