/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:15:24 by asippy            #+#    #+#             */
/*   Updated: 2022/03/10 23:01:46 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> //function: write
# include <stdlib.h> //function: malloc free exit

typedef struct s_stack
{
	size_t			value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_arrays
{
	size_t	length;
	int		*unsorted;
	int		*sorted;
}			t_arrays;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	size_t	a_len;
	size_t	b_len;
}			t_stacks;

typedef struct s_cost
{
	size_t	ra;
	size_t	rb;
	size_t	rra;
	size_t	rrb;
	size_t	total;
}			t_cost;

//push_swap
void	ft_print_array(int *arr, size_t len, const char *title);
void	ft_print_stack(t_stack *stack, const char *title);

//libft functions
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);

//utils
void	ft_print_error(void);
size_t	ft_find_length(char **str);
void	ft_push_into_new(int **new, int **cur, size_t length, size_t flag);

//unsorted_array
size_t	ft_create_unsort_arr(int argc, char **argv, int **unsort_arr);

//sorted_array
void	ft_create_sort_arr(t_arrays *arrays);

//list
t_stack	*ft_lstnew(size_t value);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
size_t	ft_lstsize(t_stack *stack);

//stack_a
t_stack	*ft_create_stack_a(t_arrays *arrays);

//sort
void	ft_sort(t_stacks *stacks);

//instructions
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rrb(t_stack **b);

#endif