/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:15:43 by asippy            #+#    #+#             */
/*   Updated: 2022/03/14 15:15:43 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/checker_bonus.h"

ssize_t	ft_find_line(char *buf)
{
	size_t	iter;

	iter = 0;
	while (buf[iter] != '\0' && buf[iter] != '\n')
		iter++;
	if (buf[iter] != '\n')
		return (-1);
	return (iter);
}

size_t	ft_slen(char *str)
{
	size_t	iter;

	iter = 0;
	while (str[iter] != '\0')
		iter++;
	return (iter);
}

size_t	ft_res_to_new(char **new, char **res)
{
	size_t	iter;

	iter = 0;
	while ((*res)[iter] != '\0')
	{
		(*new)[iter] = (*res)[iter];
		iter++;
	}
	free((*res));
	return (iter);
}
