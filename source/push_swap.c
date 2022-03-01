/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:16:02 by asippy            #+#    #+#             */
/*   Updated: 2022/03/01 14:16:02 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

static void	ft_print_array(int *arr, size_t len, const char *title)
{
	printf("%s\n", title);
	for (size_t i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return ;
}

static void	ft_print_stack(t_stack *stack, const char *title)
{
	printf("%s\n", title);
	while (stack != (void *)0)
	{
		printf("POINTER:%p  ||  VALUE:%lu\n", stack, stack->value);
		stack = stack->next;
	}
	return ;
}

int	main(int argc, char **argv)
{
	int		*unsort_arr;
	int		*sort_arr;
	t_stack	*stack_a;
	size_t	length;
	
	if (argc == 1)
		return (1);
	length = ft_create_unsort_arr(argc, argv, &unsort_arr);
	printf("LENGTH: %lu\n", length);
	ft_print_array(unsort_arr, length, "UNSORTED ARRAY:");
	ft_create_sort_arr(&unsort_arr, &sort_arr, length);
	ft_print_array(sort_arr, length, "SORTED ARRAY:");
	stack_a = ft_create_stack_a(&unsort_arr, sort_arr, length);
	ft_print_stack(stack_a, "STACK_A:");
	return (0);
	
}