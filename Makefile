# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asippy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 22:41:46 by asippy            #+#    #+#              #
#    Updated: 2022/03/10 22:48:38 by asippy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME								=	push_swap

SRCS_DIR							=	source/
SRCS_LIST							=	push_swap.c\
										ft_split.c ft_atoi.c\
										utils.c\
										unsorted_array.c sorted_array.c\
										list.c\
										stack_a.c\
										sort.c\
										instructions.c\

HEAD_DIR							=	include/
HEAD_NAME							=	push_swap.h
HEAD								=	$(HEAD_DIR)$(HEAD_NAME)

OBJS_DIR							=	object/
OBJS_LIST							=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS								=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

CC									=	gcc
OFLAGS								=	-O2
CFLAGS								=	-Wall -Werror -Wextra
RM									=	rm -rf

all:								$(NAME)

$(NAME):							$(OBJS_DIR) $(OBJS)
									$(CC) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o:						$(SRCS_DIR)%.c $(HEAD)
									$(CC) $(OFLAGS) $(CFLAGS) -I$(HEAD_DIR) -c $< -o $@

$(OBJS_DIR):
									mkdir $(OBJS_DIR)

clean:
									$(RM) $(OBJS_DIR)

fclean:								clean
									$(RM) $(NAME)

re:									fclean all

.PHONY:								all clean fclean re