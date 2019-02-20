#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int		ft_upperlower(int c);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strndup(const char *s1, size_t n);
void	*ft_memalloc(size_t size);
void	*ft_memchr(void *s, int c, size_t n);

int		main(void)
{
	/*ft_upperlower tests*/
	printf("testing ft_upperlower----------------------------------------\n");

	printf("sys:\t%c\nmine:\t%c\n\n", tolower('H'), ft_upperlower('H'));
	printf("sys:\t%c\nmine:\t%c\n\n", toupper('i'), ft_upperlower('i'));
	printf("sys:\t%c\nmine:\t%c\n\n", toupper(' '), ft_upperlower(' '));
	printf("sys:\t%c\nmine:\t%c\n\n", tolower('M'), ft_upperlower('M'));
	printf("sys:\t%c\nmine:\t%c\n\n", toupper('o'), ft_upperlower('o'));
	printf("sys:\t%c\nmine:\t%c\n\n", toupper('m'), ft_upperlower('m'));
	printf("sys:\t%c\nmine:\t%c\n\n", toupper('!'), ft_upperlower('!'));
	printf("sys:\t%c\nmine:\t%c\n\n", toupper('1'), ft_upperlower('1'));

	/*ft_strncat tests*/
	printf("testing ft_strncat----------------------------------------\n");

	char	*cat1, *cat2, *cat3;

	cat1 = malloc(sizeof(char) * 9);
	cat3 = malloc(sizeof(char) * 9);
	cat2 = strdup("cat2");
	
	strcpy(cat1, "cat1");
	strcpy(cat3, "cat3");
	
	printf("og:\t%s\n", cat1);
	printf("sys:\t(returns) %s\t(sets dst to) %s\n", strncat(cat1, cat2, 4), cat1);
	printf("mine:\t(returns) %s\t(sets dst to) %s\n\n", ft_strncat(cat3, cat2, 4), cat3);

	strcpy(cat1, "dog1");
	strcpy(cat2, "dog2");
	strcpy(cat3, "dog3");

	printf("sys:\t(returns) %s\t(sets dst to) %s\n", strncat(cat1, cat2, 2), cat1);
	printf("mine:\t(returns) %s\t(sets dst to) %s\n\n", ft_strncat(cat3, cat2, 2), cat3);

	strcpy(cat1, "pup1");
	strcpy(cat2, "pup2");
	strcpy(cat3, "pup3");

	printf("sys:\t(returns) %s\t(sets dst to) %s\n", strncat(cat1, cat2, 8), cat1);
	printf("mine:\t(returns) %s\t(sets dst to) %s\n\n", ft_strncat(cat3, cat2, 8), cat3);

	free(cat1);
	free(cat2);
	free(cat3);

	/*ft_strndup tests*/
	printf("testing ft_strndup----------------------------------------\n");

	char	*string, *dup1, *dup2, *dup3, *dup4;

	string = strdup("copy this!");

	printf("og:\t%s\n", string);

	dup1 = strndup(string, 4);
	printf("sys:\t(address)%p\t%s\n", dup1, dup1);
	dup2 = ft_strndup(string, 4);
	printf("mine:\t(address)%p\t%s\n\n", dup2, dup2);

	dup3 = strndup(string, 15);
	printf("sys:\t(address)%p\t%s\n", dup3, dup3);
	dup4 = ft_strndup(string, 15);
	printf("mine:\t(address)%p\t%s\n\n", dup4, dup4);

	free(string);
	free(dup1);
	free(dup2);
	free(dup3);
	free(dup4);

	/*ft_memalloc tests*/
	printf("testing ft_memalloc----------------------------------------\n");

	char	*alloc;
	
	
	write(1, "ft_memalloc memory:\n", 21);
	alloc = ft_memalloc(5);
	for (int i = 0; i < 5; i++)
		if (alloc[i] == 0)
			write(1, "0", 1);
		else
			write(1, "X", 1);
	write(1, "\n\n", 2);

	free(alloc);

	/*ft_memchr tests*/
	printf("testing ft_memchr----------------------------------------\n");

	char	*chr;

	chr = strdup("let's make a deal");

	printf("og:\t%s\nsys:\t%s\nmine:\t%s\n\n", chr, memchr(chr, 'd', 17), ft_memchr(chr, 'd', 17));
	printf("og:\t%s\nsys:\t%s\nmine:\t%s\n", chr, memchr(chr, '!', 17), ft_memchr(chr, '!', 17));

	return (0);
}
