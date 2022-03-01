/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:57:52 by asippy            #+#    #+#             */
/*   Updated: 2022/03/01 22:39:11 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

size_t	ft_find_length(const char **str)
{
	size_t	iter;

	iter = 0;
	while (str[iter] != (void *)0)
		iter++;
	return (iter);
}

void	ft_push_into_new(int **new, int **cur, size_t length, size_t flag)
{
	size_t	iter;

	iter = 0;
	while (iter < length)
	{
		(*new)[iter] = (*cur)[iter];
		iter++;
	}
	if (flag && length != 0)
		free(*cur);
	return ;
}