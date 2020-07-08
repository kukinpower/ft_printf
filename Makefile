# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romankukin <romankukin@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/29 17:38:53 by mkristie          #+#    #+#              #
#    Updated: 2020/07/07 22:01:41 by romankukin       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
LIBFT = libft/libft/
FLAGS = -Wall -Wextra -Werror #-g
HEADER = libftprintf.h

SRCS = ft_printf.c \
		handle_d.c \
		handle_p.c \
		handle_s.c \
		handle_u.c \
		handle_x.c \
		init_go.c \
		free_t_go.c \
		make_flags_zero.c \
		is_flag_zero.c \
		handle_precision.c \
		handle_width.c \
		handle_precision_u.c \
		handle_width_u.c \
		handle_precision_s.c \
		handle_width_s.c \
		is_hex_lower.c \
		check_flag.c \
		handle_flag_dot.c \

MTHR ?= -j

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re bonus main mainclean

all:	#$(NAME)
		@make -C $(LIBFT)
		@$(MAKE) $(MTHR) $(NAME)

$(NAME): $(OBJS)
		@cp libft/libft/libft.a ./$(NAME)
		@ar rcs $(NAME) $(OBJS)
		@echo "Libftprintf compiled"

%.o: %.c 
		@gcc $(FLAGS) -I $(HEADER) -c $< -o $@

main:	re
		@gcc main.c libftprintf.a -I libftprintf.h $(FLAGS)
		#@./a.out #| cat -e

mainclean:	
			@/bin/rm -f main.o
			@/bin/rm -f a.out

clean:
		@make clean -C $(LIBFT)
		@/bin/rm -f $(OBJS)
		@echo "libftprintf cleaned"

fclean:	clean mainclean
		@/bin/rm -f $(NAME)
		@echo "libftprintf full cleaned"

re:		fclean all