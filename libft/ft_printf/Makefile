# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 09:16:22 by ndubouil          #+#    #+#              #
#    Updated: 2018/02/15 13:50:22 by ndelest          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binaries
CC		=	/usr/bin/gcc
AR		=	/usr/bin/ar
RANLIB	=	/usr/bin/ranlib
RM		=	/bin/rm
# Directories
HEADER	=	./
LIBPATH =	../srcs_libft/
LIB		=	$(LIBPATH)libft.a
# Compilation flags
CFLAGS	=	-Wall -Wextra -Werror -O3 -std=c11
# Files
SRC		=	ft_imtoa.c				\
			ft_printf.c				\
			int_decimaltype.c		\
			unsigned_decimaltype.c	\
			ft_putwchar.c			\
			ft_uitoa_base.c			\
			conv_distribution.c		\
			decimals_arg.c			\
			octohexadecimal_arg.c	\
			chars_arg.c				\
			ft_strcapitalize.c		\
			arg_config.c			\
			fill_params.c			\
			put_params.c			\
			errors.c				\
			string_unicode.c		\
			char_unicode.c

OBJ		=	$(patsubst %.c,%.o,$(SRC))
HFILES	=	$(HEADER)libftprintf.h
# Name
NAME	=	libftprintf.a
MAIN	=	mainTest.c 
.PHONY: all clean fclean re

all: $(NAME)

$(NAME):	$(OBJ) $(HFILES) Makefile
			@make -C $(LIBPATH)
			@echo "Building $(NAME) ..."
			@cp $(LIB) $(NAME)
			@$(AR) rc $(NAME) $(OBJ)
			@$(RANLIB) $(NAME)
			@mv $(NAME) ../
			@echo "The library $(NAME) is ready"

%.o:		%.c $(HFILES)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) -f $(OBJ)
			@make clean -C $(LIBPATH)

fclean:		clean
			@$(RM) -f ../$(NAME)
			@make fclean -C $(LIBPATH)

re: 		fclean
			@make
