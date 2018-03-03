# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 09:16:22 by ndubouil          #+#    #+#              #
#    Updated: 2018/02/18 18:41:19 by ndelest          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binaries
CC		=	/usr/bin/gcc
AR		=	/usr/bin/ar
RANLIB	=	/usr/bin/ranlib
RM		=	/bin/rm
# Directories
HEADER	=	srcs/includes/
PATH_PS	=	srcs/srcs_push_swap/
LIBPATH =	libft/ft_printf/
# Compilation flags
CFLAGS	=	-Wall -Wextra -Werror
# Files
SRC_PS	=	$(PATH_PS)instructions_a.c	\
			$(PATH_PS)main_p_s.c		\
			$(PATH_PS)basic_algo1.c		\
			$(PATH_PS)checker.c			\
			$(PATH_PS)index_algo.c		\
			$(PATH_PS)sort_index.c		\
			$(PATH_PS)index_algo2.c		\
			$(PATH_PS)index_algo3.c		\
			$(PATH_PS)tri_fusion.c
OBJ_PS	=	$(patsubst %.c,%.o,$(SRC_PS))
HFILES	=	$(HEADER)push_swap.h
LIB		=	libft/libftprintf.a
# Name
NAME1	=	push_swap
.PHONY: all clean fclean re

all: $(NAME1)

$(NAME1):	$(OBJ_PS) $(LIB) Makefile
			@echo "Compiling $(NAME1)"
			@$(CC) $(CFLAGS) $(OBJ_PS) $(LIB) -I$(HEADER) -o $(NAME1)
			@echo "The executable $(NAME1) is ready"

%.o:		%.c $(LIB)
			@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

$(LIB):
			@make -C $(LIBPATH)

clean:
			@$(RM) -f $(OBJ_PS)
			@make clean -C $(LIBPATH)

fclean:		clean
			@$(RM) -f $(NAME1)
			@make fclean -C $(LIBPATH)

re: 		fclean
			@make
