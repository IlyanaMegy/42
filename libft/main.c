#include "libft.h"

int	main(void)
{
	printf("\n#####   ft_calloc   #####\n");
	int	i;
	int	count = 10;
	int	*pointer = (int *)calloc(count, sizeof(int));
	assert(pointer != NULL);
	for (i = 0; i < count - 1; i++)
	{
		pointer[i] = i;
		printf("%d ", pointer[i]);
	}
	free(pointer);
	printf("\n	    OK!\n");

	printf("\n#####   ft_atoi     #####\n");
	assert(atoi("  \n  42t4457") == ft_atoi("  \n  42t4457"));
	assert(atoi("") == ft_atoi(""));
	assert(atoi("\0 1337") == ft_atoi("\0 1337"));
	assert(atoi("-0") == ft_atoi("-0"));
	assert(atoi(" -  1 3 2 5 6 3 2 1 6 7") == ft_atoi(" -  1 3 2 5 6 3 2 1 6 7"));
	assert(atoi("-1325632167") == ft_atoi("-1325632167"));
	assert(atoi("-100") == ft_atoi("-100"));
	assert(atoi("\t---+2147483648") == ft_atoi("\t---+2147483648"));
	assert(atoi("\v2147483647") == ft_atoi("\v2147483647"));
	printf("	    OK!\n");

	printf("\n#####   ft_isalnum   #####\n");
	assert(isalnum(103) && ft_isalnum(103));
	assert(isalnum(64) == ft_isalnum(64));
	assert(isalnum(95) == ft_isalnum(95));
	assert(isalnum(70) && ft_isalnum(70));
	assert(isalnum(48) && ft_isalnum(48));
	printf("	    OK!\n");

	printf("\n\n#####   ft_isalpha   #####\n");
	assert(isalpha(70) && ft_isalpha(70));
	assert(isalpha(55) == ft_isalpha(55));
	assert(isalpha(123) == ft_isalpha(123));
	assert(isalpha(97) && ft_isalpha(97));
	assert(isalpha(65) && ft_isalpha(65));
	printf("	    OK!\n");

	printf("\n\n#####   ft_isascii   #####\n");
	assert(isascii(-1) == ft_isascii(-1));
	assert(isascii(128) == ft_isascii(128));
	assert(isascii(127) && ft_isascii(127));
	assert(isascii(0) && ft_isascii(0));
	printf("	    OK!\n");

	printf("\n\n#####   ft_isdigit   #####\n");
	assert(isdigit(-1) == ft_isdigit(-1));
	assert(isdigit(58) == ft_isdigit(58));
	assert(isdigit(57) && ft_isdigit(57));
	assert(isdigit(48) && ft_isdigit(48));
	printf("	    OK!\n");

	printf("\n\n#####   ft_isprint   #####\n");
	assert(isprint(-1) == ft_isprint(-1));
	assert(isprint(127) == ft_isprint(127));
	assert(isprint(31) == ft_isprint(31));
	assert(isprint(32) && ft_isprint(32));
	assert(isprint(126) && ft_isprint(126));
	printf("	    OK!\n");

	printf("\n\n#####   ft_memchr    #####\n");
	char data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	size_t size = 10;
	int try = 60;
	assert(memchr(data, try, size) == ft_memchr(data, try, size));
	printf("	    OK!\n");

	printf("\n\n#####   ft_memcmp    #####\n");
	int array1[] = {54, 85, 20, 63, 21};
	int array2[] = {54, 85, 19, 63, 21};
	size_t s = sizeof(int) * 5;
	assert(memcmp(array1, array2, s) == ft_memcmp(array1, array2, s));
	assert(memcmp(array1, array1, s) == ft_memcmp(array1, array1, s));
	assert(memcmp(array2, array1, s) == ft_memcmp(array2, array1, s));
	printf("	    OK!\n");

	printf("\n\n#####   ft_memcpy    #####\n");
	int array[] = {54, 85, 20, 63, 21};
	int *copy = NULL;
	int length = sizeof(int) * 5;
	copy = (int *)malloc(length);
	assert(memcpy(copy, array, length) == ft_memcpy(copy, array, length));
	printf("	    OK!\n");
	free(copy);

	printf("\n\n#####   ft_memset    #####\n");
	int buffer[]= {1, 2, 3, 4, 5};
	assert(memset( buffer, 0, (sizeof (int) * 5)) == ft_memset( buffer, 0, (sizeof (int) * 5)));
	printf("	    OK!\n");

	printf("\n\n#####   ft_strchr    #####\n");
	char *string = "hello world !";
	int	c = 101;
	assert(ft_strchr(string, c) == strchr(string, c));
	printf("	    OK!\n");

	printf("\n\n#####   ft_strrchr   #####\n");
	assert(ft_strrchr(string, c) == strrchr(string, c));
	printf("	    OK!\n");
	return (0);
}
