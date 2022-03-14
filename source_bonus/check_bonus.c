/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:07:35 by asippy            #+#    #+#             */
/*   Updated: 2022/03/14 16:46:48 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/checker_bonus.h"

static size_t	ft_check_if_sorted(t_stacks *stacks, size_t size)
{
	t_stack	*tmp;
	size_t	flag;

	if (stacks->b_len != 0 || stacks->a_len != size)
		return (0);
	tmp = stacks->a;
	flag = 1;
	while (tmp->next != (void *)0)
	{
		if (tmp->value > tmp->next->value)
		{
			flag = 0;
			break ;
		}
		tmp = tmp->next;
	}
	return (flag);
}

static void	ft_check_command(const char *com)
{
	if (com != "ra\n" && com != "rb\n" && com != "rr\n"
		&& com != "rra\n" && com != "rrb\n" && com != "rrr\n"
		&& com != "sa\n" && com != "sb\n" && com != "ss\n"
		&& com != "pa\n" && com != "pb\n")
		ft_print_error();
	return ;
}

void	ft_check(t_stacks *stacks)
{
	size_t	size;
	size_t	flag;
	char	*command;

	size = stacks->a_len;
	command = get_next_line(0);
	flag = ft_check_if_sorted(stacks, size);
	if (command == (void *)0)
		ft_print_result(flag);
	while (command != (void *)0)
	{
		ft_check_command(command);
		ft_pushs(stacks, command);
		ft_swaps(&stacks->a, &stacks->b, command);
		ft_rotates(&stacks->a, &stacks->b, command);
		ft_reverse_rotates(&stacks->a, &stacks->b, command);
		command = get_next_line(0);
	}
	flag = ft_check_if_sorted(stacks, size);
	ft_print_result(flag);
	return ;
}
