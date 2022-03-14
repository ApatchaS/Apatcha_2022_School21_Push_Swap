/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:07:56 by asippy            #+#    #+#             */
/*   Updated: 2022/03/14 16:46:44 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/checker_bonus.h"

void	ft_pushs(t_stacks *stacks, const char *com)
{
	if (com == "pa\n")
	{
		ft_push(&stacks->b, &stacks->a);
		stacks->a_len++;
		stacks->b_len--;
	}
	else if (com == "pb\n")
	{
		ft_push(&stacks->a, &stacks->b);
		stacks->a_len--;
		stacks->b_len++;
	}
	return ;
}

void	ft_swaps(t_stack **a, t_stack **b, const char *com)
{
	if (com == "sa\n")
		ft_swap(a);
	else if (com == "sb\n")
		ft_swap(a);
	else if (com == "ss\n")
	{
		ft_swap(a);
		ft_swap(b);
	}
	return ;
}

void	ft_rotates(t_stack **a, t_stack **b, const char *com)
{
	if (com == "ra\n")
		ft_rotate(a);
	else if (com == "rb\n")
		ft_rotate(b);
	else if (com == "rr\n")
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	return ;
}

void	ft_reverse_rotates(t_stack **a, t_stack **b, const char *com)
{
	if (com == "rra\n")
		ft_reverse_rotate(a);
	else if (com == "rrb\n")
		ft_reverse_rotate(b);
	else if (com == "rrr\n")
	{
		ft_reverse_rotate(a);
		ft_reverse_rotate(b);
	}
	return ;
}
