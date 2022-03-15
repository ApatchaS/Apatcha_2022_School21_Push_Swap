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

static void	ft_handle_04123_case(t_stacks *stacks)
{
	ft_swap(&stacks->a, "sa\n");
	return ;
}

static void	ft_handle_42103_case(t_stacks *stacks)
{
	ft_rotate(&stacks->a, "ra\n");
	ft_swap(&stacks->a, "sa\n");
	ft_rotate(&stacks->a, "ra\n");
	ft_rotate(&stacks->a, "ra\n");
	ft_push(&stacks->a, &stacks->b, "pb\n");
	ft_reverse_rotate(&stacks->a, "rra\n");
	ft_reverse_rotate(&stacks->a, "rra\n");
	ft_push(&stacks->b, &stacks->a, "pa\n");
	return ;
}

static size_t	ft_handle_five_len_special_cases(t_stacks *stacks)
{
	size_t	first;
	size_t	second;
	size_t	third;
	size_t	fourth;
	size_t	fifth;

	first = stacks->a->value;
	second = stacks->a->next->value;
	third = stacks->a->next->next->value;
	fourth = stacks->a->next->next->next->value;
	fifth = stacks->a->next->next->next->next->value;
	if (first == 0 && second == 4 && third == 1 && fourth == 2 && fifth == 3)
	{
		ft_handle_04123_case(stacks);
		return (1);
	}
	if (first == 4 && second == 2 && third == 1 && fourth == 0 && fifth == 3)
	{
		ft_handle_42103_case(stacks);
		return (1);
	}
	return (0);
}

void	ft_sort(t_stacks *stacks)
{
	size_t	flag;

	flag = 0;
	if (!ft_check_sort(stacks->a, stacks->a_len))
	{
		if (stacks->a_len == 5)
			flag = ft_handle_five_len_special_cases(stacks);
		if (!flag)
		{
			ft_create_stack_b(stacks);
			ft_sort_tree(&stacks->a);
			ft_push_from_b_to_a(stacks);
		}
	}
	ft_final_sort(&stacks->a, stacks->a_len);
	return ;
}
