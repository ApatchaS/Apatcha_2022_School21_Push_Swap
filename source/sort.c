/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:33:29 by asippy            #+#    #+#             */
/*   Updated: 2022/03/16 00:01:03 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort(t_stacks *stacks)
{
	stacks->b = (void *)0;
	stacks->b_len = 0;
	if (!ft_check_sort(stacks->a, stacks->a_len))
	{
		if (stacks->a_len == 5)
			ft_create_stack_b_from_five_len(stacks);
		else
			ft_create_stack_b(stacks);
		ft_sort_tree(&stacks->a);
		ft_push_from_b_to_a(stacks);
	}
	ft_final_sort(&stacks->a, stacks->a_len);
	return ;
}
