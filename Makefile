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
CCFLAGS =	-Wall -Wextra -Werror -L. -lfts
SRCS =		sources/ft_isalpha.s\
			sources/ft_bzero.s\
			sources/ft_strcat.s\
			sources/ft_isdigit.s\
			sources/ft_isalnum.s\
			sources/ft_isascii.s\
			sources/ft_isprint.s\
			sources/ft_toupper.s\
			sources/ft_tolower.s\
			sources/ft_puts.s\
			sources/ft_strlen.s\
			sources/ft_memset.s\
			sources/ft_memcpy.s\
			sources/ft_strdup.s\
			sources/ft_cat.s\
			sources/ft_upperlower.s\
			sources/ft_strncat.s\
			sources/ft_strndup.s\
			sources/ft_memalloc.s\
			sources/ft_memchr.s
OBJS =		objects/ft_isalpha.o\
			objects/ft_bzero.o\
			objects/ft_strcat.o\
			objects/ft_isdigit.o\
			objects/ft_isalnum.o\
			objects/ft_isascii.o\
			objects/ft_isprint.o\
			objects/ft_toupper.o\
			objects/ft_tolower.o\
			objects/ft_puts.o\
			objects/ft_strlen.o\
			objects/ft_memset.o\
			objects/ft_memcpy.o\
			objects/ft_strdup.o\
			objects/ft_cat.o\
			objects/ft_upperlower.o\
			objects/ft_strncat.o\
			objects/ft_strndup.o\
			objects/ft_memalloc.o\
			objects/ft_memchr.o
TSTFILE =	main.c
BNSFILE =	bonus.c

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

objects/%.o: sources/%.s
	@/bin/mkdir -p objects
	nasm $(ASMFLAGS) $< -o $@

test:
	@/bin/rm -f libftasm_test
	@/bin/rm -f bonus_test
	gcc $(CCFLAGS) $(TSTFILE) -o libftasm_test
	gcc $(CCFLAGS) $(BNSFILE) -o bonus_test

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all


