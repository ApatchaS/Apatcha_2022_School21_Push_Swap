/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsorted_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:39:06 by asippy            #+#    #+#             */
/*   Updated: 2022/03/03 15:41:41 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static size_t	ft_fill_unsort_arr(const char *str, int **unsort_arr, size_t l)
{
	char	**elements;
	int		*new_unsort_arr;
	size_t	inc;
	size_t	iter;

	elements = ft_split(str, ' ');
	if (elements == (void *)0)
		ft_print_error();
	inc = ft_find_length(elements);
	new_unsort_arr = (int *)malloc(sizeof(int) * (l + inc));
	if (new_unsort_arr == (void *)0)
		ft_print_error();
	ft_push_into_new(&new_unsort_arr, unsort_arr, l, 1);
	iter = 0;
	while (iter < inc)
	{
		new_unsort_arr[l + iter] = ft_atoi(elements[iter]);
		free(elements[iter]);
		iter++;
	}
	free(elements);
	*unsort_arr = new_unsort_arr;
	return (inc);
}

static void	ft_check_err_input(const char *str)
{
	size_t	iter;

	iter = 0;
	while (str[iter] != '\0')
	{
		if ((str[iter] < '0' || str[iter] > '9')
			&& str[iter] != ' ' && str[iter] != '-' && str[iter] != '+')
			ft_print_error();
		iter++;
	}
	return ;
}

size_t	ft_create_unsort_arr(int argc, char **argv, int **unsort_arr)
{
	size_t	iter;
	size_t	length;

	iter = 1;
	length = 0;
	while (iter < argc)
	{
		ft_check_err_input(argv[iter]);
		length += ft_fill_unsort_arr(argv[iter], unsort_arr, length);
		iter++;
	}
	return (length);
}
