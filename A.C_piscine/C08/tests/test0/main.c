#include "ft.h"
#include <stdio.h>

int	main(void)
{
	char *str;
	char *str2;
	int a;
	int b;
	str = "hello world !";
	str2 = "hello world";
	a = 4;
	b = 2;

	ft_putchar(str[0]);
	ft_putstr(str);
	printf("len = %d\n", ft_strlen(str));
	printf("cmp = %d\n", ft_strcmp(str, str2));
	printf("a = %d, b = %d", a, b);
	ft_swap(&a, &b);
	printf("a = %d, b = %d", a, b);

	return (0);
}