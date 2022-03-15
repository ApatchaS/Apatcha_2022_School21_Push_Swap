/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 04:41:24 by asippy            #+#    #+#             */
/*   Updated: 2022/03/15 04:47:45 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h> //function: write read
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

//libft functions
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);

//get_next_line_bonus get_next_line_utils_bonus
char	*get_next_line(int fd);
ssize_t	ft_find_line(char *buf);
size_t	ft_slen(char *str);
size_t	ft_res_to_new(char **new, char **res);

//utils_bonus
void	ft_print_error(void);
void	ft_print_result(size_t flag);
size_t	ft_find_length(char **str);
void	ft_push_into_new(int **new, int **cur, size_t length, size_t flag);

//unsorted_array_bonus
size_t	ft_create_unsort_arr(int argc, char **argv, int **unsorted);

//sorted_array_bonus
void	ft_create_sort_arr(t_arrays *arrays);

//list_bonus
t_stack	*ft_lstnew(size_t value);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
size_t	ft_lstsize(t_stack *stack);

//stack_a_bonus
t_stack	*ft_create_stack_a(t_arrays *arrays);

//check_bonus
void	ft_check(t_stacks *stacks);

//instructions_bonus
void	ft_push(t_stack **from, t_stack **to);
void	ft_swap(t_stack **stack);
void	ft_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack);

//commands_bonus
void	ft_pushs(t_stacks *stacks, size_t command_ind);
void	ft_swaps(t_stack **a, t_stack **b, size_t command_ind);
void	ft_rotates(t_stack **a, t_stack **b, size_t command_ind);
void	ft_reverse_rotates(t_stack **a, t_stack **b, size_t command_ind);

#endif