#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *s1, const char *s2);
int		ft_isalpha(int c);

int		main(void)
{
	//ft_bzero tests
	printf("testing ft_bzero----------------------------------------\n");

	char	*hello;

	hello = malloc(sizeof(char) * 6);
	strcpy(hello, "Hello");
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

	//ft_strcat tests
	printf("testing ft_strcat----------------------------------------\n");

	char	*cat1, *cat2, *cat3;

	cat1 = malloc(sizeof(char) * 9);
	cat2 = malloc(sizeof(char) * 4);
	cat3 = malloc(sizeof(char) * 9);
	strcpy(cat1, "cat1");
	strcpy(cat2, "cat2");
	strcpy(cat3, "cat3");
	printf("og:\t%s\n", cat1);
	printf("sys:\t(returns) %s\t(sets dst to) %s\n", strcat(cat1, cat2), cat1);
	printf("mine:\t(returns) %s\t(sets dst to) %s\n\n", ft_strcat(cat3, cat2), cat3);

	//ft_isalpha tests
	printf("testing ft_isalpha----------------------------------------\n");

	printf("sys:\t%d\nmine:\t%d\n\n", isalpha(-12), ft_isalpha(-12));
	printf("sys:\t%d\nmine:\t%d\n\n", isalpha('L'), ft_isalpha('L'));
	printf("sys:\t%d\nmine:\t%d\n\n", isalpha('i'), ft_isalpha('i'));
	printf("sys:\t%d\nmine:\t%d\n\n", isalpha('['), ft_isalpha('['));

	return (0);
}
