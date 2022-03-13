/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:33:29 by asippy            #+#    #+#             */
/*   Updated: 2022/03/13 19:53:30 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort(t_stacks *stacks)
{
	if (!ft_check_sort(stacks->a, stacks->a_len))
	{
		ft_create_stack_b(stacks);
		ft_sort_tree(&stacks->a);
		ft_push_from_b_to_a(stacks);
	}
	ft_final_sort(&stacks->a, stacks->a_len);
	return ;
}
