/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:25:25 by asippy            #+#    #+#             */
/*   Updated: 2022/03/14 16:25:25 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/checker_bonus.h"

void	ft_push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if ((*from) == (void *)0)
		ft_print_error();
	ft_lstadd_front(to, ft_lstnew((*from)->value));
	tmp = (*from)->next;
	free(*from);
	*from = tmp;
	return ;
}

void	ft_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (ft_lstsize(*stack) < 2)
		ft_print_error();
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	ft_lstadd_front(stack, ft_lstnew(tmp->value));
	free(tmp);
	return ;
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (ft_lstsize(*stack) < 2)
		ft_print_error();
	ft_lstadd_back(stack, ft_lstnew((*stack)->value));
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	return ;
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*iter;

	if (ft_lstsize(*stack) < 2)
		ft_print_error();
	iter = *stack;
	while (iter->next->next != (void *)0)
		iter = iter->next;
	ft_lstadd_front(stack, ft_lstnew(iter->next->value));
	free(iter->next);
	iter->next = (void *)0;
	return ;
}
