# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asippy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 22:41:46 by asippy            #+#    #+#              #
#    Updated: 2022/03/15 21:09:20 by asippy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME								=	push_swap
B_NAME								=	checker

BOLD								=	\033[1m
RED									=	\033[31m
GREEN								=	\033[32m
YELLOW								=	\033[33m
RESET								=	\033[0m

SRCS_DIR							=	source/
SRCS_LIST							=	push_swap.c\
										ft_split.c ft_atoi.c\
										utils.c\
										unsorted_array.c sorted_array.c\
										list.c\
										stack_a.c stack_b.c\
										sort.c\
										instructions_general.c instructions_special.c\
										cost.c cost_utils.c
B_SRCS_DIR							=	source_bonus/
B_SRCS_LIST							=	checker_bonus.c\
										ft_split_bonus.c ft_atoi_bonus.c\
										get_next_line_bonus.c get_next_line_utils_bonus.c\
										utils_bonus.c\
										unsorted_array_bonus.c sorted_array_bonus.c\
										list_bonus.c\
										stack_a_bonus.c\
										check_bonus.c\
										instructions_bonus.c\
										commands_bonus.c

HEAD_DIR							=	include/
HEAD_NAME							=	push_swap.h
B_HEAD_DIR							=	include_bonus/
B_HEAD_NAME							=	checker_bonus.h
HEAD								=	$(HEAD_DIR)$(HEAD_NAME)

OBJS_DIR							=	object/
B_OBJS_DIR							=	object_bonus/
OBJS_LIST							=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS								=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

CC									=	gcc
OFLAGS								=	-O2
CFLAGS								=	#-Wall -Werror -Wextra
RM									=	rm -rf

$(NAME):							$(OBJS_DIR) $(OBJS)
									@echo "$(YELLOW)CREATING $(NAME)...$(RESET)"
									$(CC) $(OBJS) -o $(NAME)
									@echo "$(GREEN)$(BOLD)$(NAME) DONE!$(RESET)"

all:								$(NAME)

$(OBJS_DIR)%.o:						$(SRCS_DIR)%.c $(HEAD)
									$(CC) $(OFLAGS) $(CFLAGS) -I$(HEAD_DIR) -c $< -o $@
									@echo "$(GREEN)$(BOLD)$@ DONE!$(RESET)"
$(OBJS_DIR):
									@echo "$(YELLOW)CREATING $(OBJS_DIR)...$(RESET)"
									mkdir $(OBJS_DIR)
									@echo "$(GREEN)$(BOLD)$(OBJS_DIR) DONE!$(RESET)"

bonus:
									@echo "$(YELLOW)CREATING BONUS...$(RESET)"
									@make NAME="$(B_NAME)" SRCS_DIR="$(B_SRCS_DIR)" SRCS_LIST="$(B_SRCS_LIST)" HEAD_DIR="$(B_HEAD_DIR)" HEAD_NAME="$(B_HEAD_NAME)" OBJS_DIR="$(B_OBJS_DIR)"
									@echo "$(GREEN)$(BOLD)BONUS DONE!$(RESET)"

clean:
									@echo "$(RED)REMOVING OBJECTS...$(RESET)"
									$(RM) $(OBJS_DIR) $(B_OBJS_DIR)
									@echo "$(RED)$(BOLD)OBJECTS REMOVED!$(RESET)"

fclean:								clean
									@echo "$(RED)REMOVING $(NAME) $(B_NAME)...$(RESET)"
									$(RM) $(NAME) $(B_NAME)
									@echo "$(RED)$(BOLD)$(NAME) $(B_NAME) REMOVED!$(RESET)"

re:									fclean all

.PHONY:								all bonus clean fclean re