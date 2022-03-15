/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 04:42:30 by asippy            #+#    #+#             */
/*   Updated: 2022/03/15 04:43:29 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/checker_bonus.h"

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
	stacks.b = (void *)0;
	stacks.b_len = 0;
	ft_check(&stacks);
}
