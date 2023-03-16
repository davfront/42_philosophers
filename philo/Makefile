# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 13:30:28 by dapereir          #+#    #+#              #
#    Updated: 2023/01/30 13:42:31 by dapereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# COLORS

RED					=	\033[0;31m
RED_BOLD			=	\033[1;31m
GREEN				=	\033[0;32m
GREEN_BOLD			=	\033[1;32m
YELLOW				=	\033[0;33m
YELLOW_BOLD			=	\033[1;33m
CYAN				=	\033[0;36m
CYAN_BOLD			=	\033[1;36m
BOLD				=	\033[1m
FAINT				=	\033[2m
EOC					=	\033[0m


# COMMANDS

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -pthread
RM					=	rm -rf

SILENTFLAG			= 	$(if $(filter s, $(MAKEFLAGS)),1,0)
ifeq ($(SILENTFLAG),1)
ECHO				=	\#
else
ECHO				=	echo
endif


# PROJECT

NAME				=	philo

SRCS_DIR			=	./src
OBJS_DIR			=	./obj

SRCS_FILES			=	\
						ft/ft_isdigit.c\
						ft/ft_strlen.c\
						ft/ft_putstr_fd.c\
						ft/ft_strncmp.c\
						ft/ft_itoa.c\
						ft/ft_atoi.c\
						\
						utils/phi_init.c\
						utils/phi_reset.c\
						utils/phi_error_exit.c\
						utils/phi_time.c\
						utils/phi_print.c\
						utils/phi_sleep.c\
						\
						phi_get_input.c\
						phi_is_philo_full.c\
						phi_is_philo_dead.c\
						phi_philo_routine.c\
						phi_create_data.c\
						phi_join_threads.c\
						phi_check_death.c\
						\
						main.c\

SRCS				=	$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS_FILES			=	$(SRCS_FILES:.c=.o)
OBJS				=	$(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

HEADER_DIR			=	./include
HEADER				=	$(HEADER_DIR)/philo.h
HEADER_INC			=	-I $(HEADER_DIR)

.PHONY: all
all:				$(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c Makefile $(HEADER)
					@mkdir -p $(@D)
					@$(ECHO) "$(GREEN)[create]$(EOC) $@"
					@$(CC) $(CFLAGS) $(HEADER_INC) -c $< -o $@

$(NAME):			$(OBJS)
					@$(ECHO) "$(GREEN)[create]$(EOC) $@"
					@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
					@$(ECHO) "$(GREEN_BOLD)✓ $(NAME) is ready!$(EOC)"

.PHONY: clean
clean:
					@$(ECHO) "$(RED)[delete]$(EOC) $(OBJS_DIR)"
					@$(RM) $(OBJS_DIR)

.PHONY: fclean
fclean:				clean
					@$(ECHO) "$(RED)[delete]$(EOC) $(NAME)"
					@$(RM) $(NAME)
					@$(ECHO) "$(RED_BOLD)✓ $(NAME) is fully cleaned!$(EOC)"

.PHONY: re
re:					fclean
					@$(MAKE) --no-print-directory all
