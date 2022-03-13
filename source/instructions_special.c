/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_special.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:48:29 by asippy            #+#    #+#             */
/*   Updated: 2022/03/13 21:03:42 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate_both(t_stack **a, t_stack **b)
{
	ft_rotate(a, "");
	ft_rotate(b, "");
	ft_print_note("rr\n");
	return ;
}

void	ft_reverse_rotate_both(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a, "");
	ft_reverse_rotate(b, "");
	ft_print_note("rrr\n");
	return ;
}
