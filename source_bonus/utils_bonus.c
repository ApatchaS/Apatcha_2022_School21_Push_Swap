/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:21:26 by asippy            #+#    #+#             */
/*   Updated: 2022/03/14 15:54:20 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/checker_bonus.h"

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_print_result(size_t flag)
{
	if (flag)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(0);
}

size_t	ft_find_length(char **str)
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
	if ((flag == 1) && (length != 0))
		free(*cur);
	return ;
}
