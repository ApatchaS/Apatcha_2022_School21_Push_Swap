/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:15:24 by asippy            #+#    #+#             */
/*   Updated: 2022/03/01 14:15:24 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> //function: write
# include <stdlib.h> //function: malloc free exit

typedef struct 		s_stack
{
	size_t			value;
	struct s_stack	*next;
}					t_stack;

//libft functions
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);

//utils
void	ft_print_error(void);
size_t	ft_find_length(const char **str);
void	ft_push_into_new(int **new, int **cur, size_t length, size_t flag);

//unsorted_array
size_t	ft_create_unsort_arr(int argc, char **argv, int **unsort_arr);

//sorted_array
void	ft_create_sort_arr(int **unsorted, int **sorted, size_t length);

//stack_a
t_stack	*ft_create_stack_a(int **unsort_arr, int *sort_arr, size_t length);

#endif