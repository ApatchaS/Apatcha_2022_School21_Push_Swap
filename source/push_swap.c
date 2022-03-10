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
#include <stdio.h>

void	ft_print_array(int *arr, size_t len, const char *title)
{
	size_t	iter;

	printf("%s\n", title);
	iter = 0;
	while (iter < len)
	{
		printf("%d ", arr[iter]);
		iter++;
	}
	printf("\n");
	return ;
}

void	ft_print_stack(t_stack *stack, const char *title)
{
	printf("%s\n", title);
	while (stack != (void *)0)
	{
		printf("POINTER:%15p  ||  VALUE:%5lu\n", stack, stack->value);
		stack = stack->next;
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
	printf("ARRAYS LENGTH: %lu\n", arrays.length);
	ft_print_array(arrays.unsorted, arrays.length, "UNSORTED ARRAY:");
	ft_create_sort_arr(&arrays);
	ft_print_array(arrays.sorted, arrays.length, "SORTED ARRAY:");
	stacks.a = ft_create_stack_a(&arrays);
	stacks.a_len = arrays.length;
	printf("A INIT LENGTH: %lu\n", stacks.a_len);
	ft_print_stack(stacks.a, "A INIT:");
	ft_sort(&stacks);
	return (0);
}
