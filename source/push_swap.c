/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:16:02 by asippy            #+#    #+#             */
/*   Updated: 2022/03/10 23:25:27 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_clean_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack != (void *)0)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_arrays	arrays;
	t_stacks	stacks;

	if (argc == 1)
		return (1);
	arrays.length = ft_create_unsort_arr(argc, argv, &arrays.unsorted);
	ft_create_sort_arr(&arrays);
	stacks.a = ft_create_stack_a(&arrays);
	stacks.a_len = arrays.length;
	ft_sort(&stacks);
	free(arrays.sorted);
	ft_clean_stack(&stacks.a);
	return (0);
}
