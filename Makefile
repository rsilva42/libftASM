# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsilva <rsilva@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 10:03:41 by rsilva            #+#    #+#              #
#    Updated: 2018/02/26 10:08:38 by rsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libfts.a
ASMFLAGS =	-f macho64
CCFLAGS =	-Wall -Wextra -Werror -L. -lfts #-g -fsanitize=address
SRCS =		sources/ft_isalpha.s\
			sources/ft_bzero.s\
			sources/ft_strcat.s
OBJS =		objects/ft_isalpha.o\
			objects/ft_bzero.o\
			objects/ft_strcat.o
TSTFILE =	main.c

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

objects/%.o: sources/%.s
	@/bin/mkdir -p objects
	nasm $(ASMFLAGS) $< -o $@

test:
	@/bin/rm -f libftasm_test
	gcc $(CCFLAGS) $(TSTFILE) -o libftasm_test

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all


