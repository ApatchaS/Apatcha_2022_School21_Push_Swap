/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:07:35 by asippy            #+#    #+#             */
/*   Updated: 2022/03/15 21:16:23 by asippy           ###   ########.fr       */
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

static char	**ft_init_commands_list(void)
{
	int		iter;
	char	**commands;

	iter = -1;
	commands = (char **)malloc(sizeof(char *) * 12);
	while (++iter < 11)
	{
		if (iter > 7)
			commands[iter] = (char *)malloc(sizeof(char) * 5);
		else
			commands[iter] = (char *)malloc(sizeof(char) * 4);
	}
	commands[0] = "pa\n";
	commands[1] = "pb\n";
	commands[2] = "sa\n";
	commands[3] = "sb\n";
	commands[4] = "ss\n";
	commands[5] = "ra\n";
	commands[6] = "rb\n";
	commands[7] = "rr\n";
	commands[8] = "rra\n";
	commands[9] = "rrb\n";
	commands[10] = "rrr\n";
	commands[11] = (void *)0;
	return (commands);
}

static size_t	ft_check_command(const char *command, char **commands)
{
	size_t	iter;
	size_t	jter;

	iter = 0;
	while (commands[iter] != (void *)0)
	{
		jter = 0;
		while (command[jter] != '\0' && command[jter] == commands[iter][jter])
			jter++;
		if (command[jter] == '\0')
			return (iter);
		iter++;
	}
	ft_print_error();
	return (iter);
}

void	ft_check(t_stacks *stacks)
{
	size_t	size;
	char	**commands;
	char	*command;
	size_t	command_ind;

	size = stacks->a_len;
	commands = ft_init_commands_list();
	command = get_next_line(0);
	if (command == (void *)0)
		ft_print_result(ft_check_if_sorted(stacks, size));
	while (command != (void *)0)
	{
		command_ind = ft_check_command(command, commands);
		ft_pushs(stacks, command_ind);
		ft_swaps(&stacks->a, &stacks->b, command_ind);
		ft_rotates(&stacks->a, &stacks->b, command_ind);
		ft_reverse_rotates(&stacks->a, &stacks->b, command_ind);
		free(command);
		command = get_next_line(0);
	}
	ft_print_result(ft_check_if_sorted(stacks, size));
}
