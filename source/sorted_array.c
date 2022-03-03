/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:59:18 by asippy            #+#    #+#             */
/*   Updated: 2022/03/03 15:39:10 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}

static void	ft_insetion_sort(int **arr, size_t length)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < length)
	{
		j = i - 1;
		key = (*arr)[i];
		while (j >= 0)
		{
			if ((*arr)[j] < key)
				break ;
			ft_swap(&(*arr)[j], &(*arr)[j + 1]);
			j--;
		}
		i++;
	}
	return ;
}

static void	ft_check_dup(int **arr, size_t length)
{
	size_t	iter;

	iter = 0;
	while (iter < length - 1)
	{
		if ((*arr)[iter] == (*arr)[iter + 1])
			ft_print_error();
		iter++;
	}
	return ;
}

void	ft_create_sort_arr(int **unsorted, int **sorted, size_t length)
{
	*sorted = (int *)malloc(sizeof(int) * length);
	if (*sorted == (void *)0)
		ft_print_error();
	ft_push_into_new(sorted, unsorted, length, 0);
	ft_insetion_sort(sorted, length);
	ft_check_dup(sorted, length);
	return ;
}
