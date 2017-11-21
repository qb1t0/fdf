#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysalata <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 11:58:39 by ysalata           #+#    #+#              #
#    Updated: 2017/11/21 12:19:37 by ysalata          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC =		gcc -Wall -Wextra -Werror
MLX =		-lmlx -framework OpenGL -framework AppKit
NAME =		fdf
FILES = 	sources/main.o			\
			sources/parsing.o		\
			sources/onaction.o		\
	 		sources/algorithm.o		\
			sources/recalculating.o

all: $(NAME)

$(NAME) : libft.a $(FILES)
		@ $(GCC) $(FILES) -o $(NAME) $(MLX) ./libft/libft.a
		@ echo "\033[32mfdf was compiled \033[0m"

libft.a:
		@ make -C ./libft
		@ echo "\033[32mlibft was compiled \033[0m"

%.o: %.c
		@ $(GCC) -o $@ -c $< -I ./libft

clean:
		@ rm -rf $(FILES)
		@ make clean -C ./libft
		@ echo "\033[31mrm -rf *.o\033[0m"

fclean: clean
		@ rm -rf $(NAME)
		@ rm -rf ./libft/libft.a

re: fclean all