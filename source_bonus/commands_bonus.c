/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:07:56 by asippy            #+#    #+#             */
/*   Updated: 2022/03/15 21:17:22 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/checker_bonus.h"

void	ft_pushs(t_stacks *stacks, size_t command_ind)
{
	if (command_ind == 0)
	{
		ft_push(&stacks->b, &stacks->a);
		stacks->a_len++;
		stacks->b_len--;
	}
	else if (command_ind == 1)
	{
		ft_push(&stacks->a, &stacks->b);
		stacks->a_len--;
		stacks->b_len++;
	}
	return ;
}

void	ft_swaps(t_stack **a, t_stack **b, size_t command_ind)
{
	if (command_ind == 2)
		ft_swap(a);
	else if (command_ind == 3)
		ft_swap(b);
	else if (command_ind == 4)
	{
		ft_swap(a);
		ft_swap(b);
	}
	return ;
}

void	ft_rotates(t_stack **a, t_stack **b, size_t command_ind)
{
	if (command_ind == 5)
		ft_rotate(a);
	else if (command_ind == 6)
		ft_rotate(b);
	else if (command_ind == 7)
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	return ;
}

void	ft_reverse_rotates(t_stack **a, t_stack **b, size_t command_ind)
{
	if (command_ind == 8)
		ft_reverse_rotate(a);
	else if (command_ind == 9)
		ft_reverse_rotate(b);
	else if (command_ind == 10)
	{
		ft_reverse_rotate(a);
		ft_reverse_rotate(b);
	}
	return ;
}
