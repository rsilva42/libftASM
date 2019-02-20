/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:50:11 by rsilva            #+#    #+#             */
/*   Updated: 2019/02/18 11:50:14 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *s1, const char *s2);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_puts(const char *s);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
void	ft_cat(int fd);

int		main(void)
{
	/*ft_bzero tests*/
	printf("testing ft_bzero----------------------------------------\n");

	char	*hello;
	
	hello = strdup("Hello");
	
	printf("og:\t%s\n", hello);
	write(1, "sys:\t", 5);
	bzero(hello, 5);
	for (int i = 0; i < 5; i++)
		if (hello[i] == 0)
			write(1, "0", 1);
		else
			write(1, "X", 1);
	
	strcpy(hello, "Hello");
	
	write(1, "\nmine:\t", 7);
	ft_bzero(hello, 5);
	for (int i = 0; i < 5; i++)
		if (hello[i] == 0)
			write(1, "0", 1);
		else
			write(1, "X", 1);
	write(1, "\n\n", 2);

	strcpy(hello, "Hello");

	printf("og:\t%s\n", hello);
	write(1, "sys:\t", 5);
	bzero(hello, 2);
	for (int i = 0; i < 5; i++)
		if (hello[i] == 0)
			write(1, "0", 1);
		else
			write(1, "X", 1);

	strcpy(hello, "Hello");

	write(1, "\nmine:\t", 7);
	ft_bzero(hello, 2);
	for (int i = 0; i < 5; i++)
		if (hello[i] == 0)
			write(1, "0", 1);
		else
			write(1, "X", 1);
	write(1, "\n\n", 2);

	free(hello);

	/*ft_strcat tests*/
	printf("testing ft_strcat----------------------------------------\n");

	char	*cat1, *cat2, *cat3;

	cat1 = malloc(sizeof(char) * 9);
	cat3 = malloc(sizeof(char) * 9);
	cat2 = strdup("cat2");
	
	strcpy(cat1, "cat1");
	strcpy(cat3, "cat3");
	
	printf("og:\t%s\n", cat1);
	printf("sys:\t(returns) %s\t(sets dst to) %s\n", strcat(cat1, cat2), cat1);
	printf("mine:\t(returns) %s\t(sets dst to) %s\n\n", ft_strcat(cat3, cat2), cat3);

	strcpy(cat1, "dog1");
	strcpy(cat2, "dog2");
	strcpy(cat3, "dog3");

	printf("sys:\t(returns) %s\t(sets dst to) %s\n", strcat(cat1, cat2), cat1);
	printf("mine:\t(returns) %s\t(sets dst to) %s\n\n", ft_strcat(cat3, cat2), cat3);

	strcpy(cat1, "");
	strcpy(cat2, "pup2");
	strcpy(cat3, "");

	printf("sys:\t(returns) %s\t(sets dst to) %s\n", strcat(cat1, cat2), cat1);
	printf("mine:\t(returns) %s\t(sets dst to) %s\n\n", ft_strcat(cat3, cat2), cat3);

	free(cat1);
	free(cat2);
	free(cat3);

	/*ft_isalpha tests*/
	printf("testing ft_isalpha----------------------------------------\n");

	printf("sys:\t%d\nmine:\t%d\n\n", isalpha(-12), ft_isalpha(-12));
	printf("sys:\t%d\nmine:\t%d\n\n", isalpha('['), ft_isalpha('['));

	printf("sys:\t%d\nmine:\t%d\n\n", isalpha('L'), ft_isalpha('L'));
	printf("sys:\t%d\nmine:\t%d\n\n", isalpha('i'), ft_isalpha('i'));

	/*ft_isdigit tests*/
	printf("testing ft_isdigit----------------------------------------\n");

	printf("sys:\t%d\nmine:\t%d\n\n", isdigit(-12), ft_isdigit(-12));
	printf("sys:\t%d\nmine:\t%d\n\n", isdigit('/'), ft_isdigit('/'));

	printf("sys:\t%d\nmine:\t%d\n\n", isdigit('0'), ft_isdigit('0'));
	printf("sys:\t%d\nmine:\t%d\n\n", isdigit('9'), ft_isdigit('9'));

	/*ft_isalnum tests*/
	printf("testing ft_isalnum----------------------------------------\n");

	printf("sys:\t%d\nmine:\t%d\n\n", isalnum(-12), ft_isalnum(-12));
	printf("sys:\t%d\nmine:\t%d\n\n", isalnum(561), ft_isalnum(561));
	printf("sys:\t%d\nmine:\t%d\n\n", isalnum('['), ft_isalnum('['));
	printf("sys:\t%d\nmine:\t%d\n\n", isalnum('/'), ft_isalnum('/'));

	printf("sys:\t%d\nmine:\t%d\n\n", isalnum('L'), ft_isalnum('L'));
	printf("sys:\t%d\nmine:\t%d\n\n", isalnum('i'), ft_isalnum('i'));
	printf("sys:\t%d\nmine:\t%d\n\n", isalnum('0'), ft_isalnum('0'));
	printf("sys:\t%d\nmine:\t%d\n\n", isalnum('9'), ft_isalnum('9'));

	/*ft_isascii tests*/
	printf("testing ft_isascii----------------------------------------\n");

	printf("sys:\t%d\nmine:\t%d\n\n", isascii(-12), ft_isascii(-12));
	printf("sys:\t%d\nmine:\t%d\n\n", isascii(561), ft_isascii(561));
	printf("sys:\t%d\nmine:\t%d\n\n", isascii(99999), ft_isascii(99999));
	printf("sys:\t%d\nmine:\t%d\n\n", isascii(-5), ft_isascii(-5));

	printf("sys:\t%d\nmine:\t%d\n\n", isascii('['), ft_isascii('['));
	printf("sys:\t%d\nmine:\t%d\n\n", isascii('/'), ft_isascii('/'));
	printf("sys:\t%d\nmine:\t%d\n\n", isascii('L'), ft_isascii('L'));
	printf("sys:\t%d\nmine:\t%d\n\n", isascii('i'), ft_isascii('i'));
	printf("sys:\t%d\nmine:\t%d\n\n", isascii('0'), ft_isascii('0'));
	printf("sys:\t%d\nmine:\t%d\n\n", isascii('9'), ft_isascii('9'));
	printf("sys:\t%d\nmine:\t%d\n\n", isascii(9), ft_isascii(9));
	printf("sys:\t%d\nmine:\t%d\n\n", isascii('\n'), ft_isascii('\n'));

	/*ft_isprint tests*/
	printf("testing ft_isprint----------------------------------------\n");

	printf("sys:\t%d\nmine:\t%d\n\n", isprint(-12), ft_isprint(-12));
	printf("sys:\t%d\nmine:\t%d\n\n", isprint(561), ft_isprint(561));
	printf("sys:\t%d\nmine:\t%d\n\n", isprint(99999), ft_isprint(99999));
	printf("sys:\t%d\nmine:\t%d\n\n", isprint('\n'), ft_isprint('\n'));

	printf("sys:\t%d\nmine:\t%d\n\n", isprint('['), ft_isprint('['));
	printf("sys:\t%d\nmine:\t%d\n\n", isprint('/'), ft_isprint('/'));
	printf("sys:\t%d\nmine:\t%d\n\n", isprint('L'), ft_isprint('L'));
	printf("sys:\t%d\nmine:\t%d\n\n", isprint('i'), ft_isprint('i'));
	printf("sys:\t%d\nmine:\t%d\n\n", isprint('0'), ft_isprint('0'));
	printf("sys:\t%d\nmine:\t%d\n\n", isprint('9'), ft_isprint('9'));
	printf("sys:\t%d\nmine:\t%d\n\n", isprint(' '), ft_isprint(' '));
	printf("sys:\t%d\nmine:\t%d\n\n", isprint('~'), ft_isprint('~'));

	/*ft_toupper tests*/
	printf("testing ft_toupper----------------------------------------\n");

	printf("sys:\t%c\nmine:\t%c\n\n", toupper('W'), ft_toupper('W'));
	printf("sys:\t%c\nmine:\t%c\n\n", toupper('2'), ft_toupper('2'));

	printf("sys:\t%c\nmine:\t%c\n\n", toupper('b'), ft_toupper('b'));
	printf("sys:\t%c\nmine:\t%c\n\n", toupper('y'), ft_toupper('y'));

	/*ft_tolower tests*/
	printf("testing ft_tolower----------------------------------------\n");

	printf("sys:\t%c\nmine:\t%c\n\n", tolower('w'), ft_tolower('w'));
	printf("sys:\t%c\nmine:\t%c\n\n", tolower('2'), ft_tolower('2'));

	printf("sys:\t%c\nmine:\t%c\n\n", tolower('B'), ft_tolower('B'));
	printf("sys:\t%c\nmine:\t%c\n\n", tolower('Y'), ft_tolower('y'));

	/*ft_puts tests*/
	printf("testing ft_puts----------------------------------------\n");

	int		putsret, ft_putsret = 0;

	write(1, "sys:\t\t", 6);
	putsret = puts("this is a sentence");
	write(1, "mine:\t\t", 7);
	ft_putsret = ft_puts("this is a sentence");
	printf("sys ret:\t%d\nmy ret:\t\t%d\n\n", putsret, ft_putsret);

	write(1, "sys:\t\t", 6);
	putsret = puts("HeR3\t1s  aNOtheR 0Ne");
	write(1, "mine:\t\t", 7);
	ft_putsret = ft_puts("HeR3\t1s  aNOtheR 0Ne");
	printf("sys ret:\t%d\nmy ret:\t\t%d\n\n", putsret, ft_putsret);

	write(1, "sys:\t\t", 6);
	putsret = puts(NULL);
	write(1, "mine:\t\t", 7);
	ft_putsret = ft_puts(NULL);
	printf("sys ret:\t%d\nmy ret:\t\t%d\n\n", putsret, ft_putsret);

	/*ft_strlen tests*/
	printf("testing ft_strlen----------------------------------------\n");

	printf("sys:\t%zu\nmine:\t%zu\n\n", strlen("Hello world"), ft_strlen("Hello world"));
	printf("sys:\t%zu\nmine:\t%zu\n\n", strlen("123"), ft_strlen("123"));

	/*ft_memset tests*/
	printf("testing ft_memset----------------------------------------\n");

	char	*set1, *set2, *set3, *set4;

	set1 = strdup("set");
	set2 = strdup("set");
	set3 = strdup("onlyhalf");
	set4 = strdup("onlyhalf");

	printf("og:\t%s\n", set1);
	printf("sys:\t(returns) %s\t(sets dst to) %s\n", memset(set1, '*', 3), set1);
	printf("mine:\t(returns) %s\t(sets dst to) %s\n\n", ft_memset(set2, '*', 3), set2);

	printf("og:\t%s\n", set3);
	printf("sys:\t(returns) %s\t(sets dst to) %s\n", memset(set3, 'X', 4), set3);
	printf("mine:\t(returns) %s\t(sets dst to) %s\n\n", ft_memset(set4, 'X', 4), set4);

	free(set1);
	free(set2);
	free(set3);
	free(set4);

	/*ft_memcpy tests*/
	printf("testing ft_memcpy----------------------------------------\n");

	char	*cpy1, *cpy2, *cpy3, *cpy4;

	cpy1 = strdup("original");
	cpy2 = strdup("new copy");
	cpy3 = strdup("test number two");
	cpy4 = strdup("piece of cake!!");

	printf("og:\t%s\n", cpy1);
	printf("sys:\t(returns) %s\t(copys dst to) %s\n", memcpy(cpy1, cpy2, 8), cpy1);
	strcpy(cpy1, "original");
	printf("mine:\t(returns) %s\t(copys dst to) %s\n\n", ft_memcpy(cpy1, cpy2, 8), cpy1);

	printf("og:\t%s\n", cpy3);
	printf("sys:\t(returns) %s\t(copys dst to) %s\n", memcpy(cpy3, cpy4, 15), cpy3);
	strcpy(cpy3, "test number two");
	printf("mine:\t(returns) %s\t(copys dst to) %s\n\n", ft_memcpy(cpy3, cpy4, 15), cpy4);

	free(cpy1);
	free(cpy2);
	free(cpy3);
	free(cpy4);

	/*ft_strdup tests*/
	printf("testing ft_strdup----------------------------------------\n");

	char	*string, *dup1, *dup2;

	string = strdup("copy this!");

	printf("og:\t%s\n", string);

	dup1 = strdup(string);
	printf("sys:\t(address)%p\t%s\n", dup1, dup1);
	dup2 = ft_strdup(string);
	printf("mine:\t(address)%p\t%s\n\n", dup2, dup2);

	free(string);
	free(dup1);
	free(dup2);

	/*ft_cat tests*/
	printf("testing ft_cat----------------------------------------\n");

	int		fd;

	printf("-----printing author-----\n");
	fd = open("author", O_RDONLY);
	ft_cat(fd);
	close(fd);

	printf("\n-----printing ft_cat.s-----\n");
	fd = open("sources/ft_cat.s", O_RDONLY);
	ft_cat(fd);
	close(fd);

	printf("\n-----printing bonus.txt-----\n");
	fd = open("bonus.txt", O_RDONLY);
	ft_cat(fd);
	close(fd);

	printf("\n-----ft_cat STDOUT test (press contol + d when finished)-----\n");

	ft_cat(0);

	return (0);
}
