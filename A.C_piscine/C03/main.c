#include <stdio.h>
#include <string.h>

#include "ex00/ft_strcmp.c"
// #include "ex01/ft_strncmp.c"
// #include "ex02/ft_strcat.c"
// #include "ex03/ft_strncat.c"
// #include "ex04/ft_strstr.c"
// #include "ex05/ft_strlcat.c"

int	main(int argc, char *argv[])
{
	int i;
	char *filename;

	i = 0;
	filename = argv[0];
	printf("filename is %s\n", filename);
	printf("argc = %d\n", argc);
	while (i < argc)
	{
		printf("argv[%d] --> %s\n", i, argv[i]);
		++i;
	}

	printf("--------------------------\n");
	printf("----------strcmp----------\n");
	char *str1;
	char *str2;

	if (argc >= 2)
	{
		str1 = argv[1];
		str2 = argv[2];
		printf("str1 = \"%s\" str2 = \"%s\"\n", str1, str2);
	}
	else
	{
		str1 = "aBcd", str2 = "abcd";
		printf("no args entered.\nstr1 = \"%s\", str2 \"%s\"\n", str1, str2);		
	}
	printf("ft_strcmp(str1, str2) = %d, expected result is %d\n",
			ft_strcmp(str1, str2),
			strcmp(str1, str2));

	// printf("--------------------------\n");
	// printf("----------strncmp---------\n");
	// char str3[] = "abcd.", str4[] = "abcd";
	// int	n = 5;
	// printf("ft_strncmp(str3, str4, n) = %d\n", ft_strncmp(str3, str4, n));

	// printf("--------------------------\n");
	// printf("----------strcat----------\n");
	// char str5[] = "abcd", str6[] = " efgh";
	// printf("str5 = %s\n", ft_strcat(str5, str6));

	// printf("--------------------------\n");
	// printf("----------strncat---------\n");
	// char str7[] = "hello", str8[] = " world !";
	// printf("str7 = %s\n", ft_strncat(str7, str8, n));

	// printf("--------------------------\n");
	// printf("----------strstr----------\n");
	// char str9[] = "hello world", str10[] = "llo wo";
	// printf("%s\n", strstr(str9, str10));

	// printf("--------------------------\n");
	// printf("----------strlcat---------\n");
	// char str11[] = "hello", str12[] = " world !";
	// printf("str11 = %d\n", ft_strlcat(str11, str12, n));

	return (0);
}