#include "libft.h"
#include <fcntl.h>
// https://github.com/Tripouille/libftTester
// https://www.programiz.com/dsa/linked-list-operations#delete
// https://github.com/VictorianRoques/libft/blob/master/ft_lstclear.c
// https://gitlab.com/42-Istanbul/libft/-/tree/main
// https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/19733-stockez-les-donnees-avec-les-listes-chainees


//  ##############################################################################################
//                                       PARTIE 1
//  ##############################################################################################

// int	main(void)
// {
// 	printf("\n#####   ft_calloc   #####\n");
// 	int	i;
// 	int	count = 10;
// 	int	*pointer = (int *)calloc(count, sizeof(int));
// 	assert(pointer != NULL);
// 	for (i = 0; i < count - 1; i++)
// 	{
// 		pointer[i] = i;
// 		printf("%d ", pointer[i]);
// 	}
// 	free(pointer);
// 	printf("\n	    OK!\n");

// 	printf("\n#####   ft_atoi     #####\n");
// 	assert(atoi("  \n  42t4457") == ft_atoi("  \n  42t4457"));
// 	assert(atoi("") == ft_atoi(""));
// 	assert(atoi("\0 1337") == ft_atoi("\0 1337"));
// 	assert(atoi("-0") == ft_atoi("-0"));
// 	assert(atoi(" -  1 3 2 5 6 3 2 1 6 7") == ft_atoi(" -  1 3 2 5 6 3 2 1 6 7"));
// 	assert(atoi("-1325632167") == ft_atoi("-1325632167"));
// 	assert(atoi("-100") == ft_atoi("-100"));
// 	assert(atoi("\t---+2147483648") == ft_atoi("\t---+2147483648"));
// 	assert(atoi("\v2147483647") == ft_atoi("\v2147483647"));
// 	printf("	    OK!\n");

// 	printf("\n#####   ft_isalnum   #####\n");
// 	assert(isalnum(103) && ft_isalnum(103));
// 	assert(isalnum(64) == ft_isalnum(64));
// 	assert(isalnum(95) == ft_isalnum(95));
// 	assert(isalnum(70) && ft_isalnum(70));
// 	assert(isalnum(48) && ft_isalnum(48));
// 	printf("	    OK!\n");

// 	printf("\n\n#####   ft_isalpha   #####\n");
// 	assert(isalpha(70) && ft_isalpha(70));
// 	assert(isalpha(55) == ft_isalpha(55));
// 	assert(isalpha(123) == ft_isalpha(123));
// 	assert(isalpha(97) && ft_isalpha(97));
// 	assert(isalpha(65) && ft_isalpha(65));
// 	printf("	    OK!\n");

// 	printf("\n\n#####   ft_isascii   #####\n");
// 	assert(isascii(-1) == ft_isascii(-1));
// 	assert(isascii(128) == ft_isascii(128));
// 	assert(isascii(127) && ft_isascii(127));
// 	assert(isascii(0) && ft_isascii(0));
// 	printf("	    OK!\n");

// 	printf("\n\n#####   ft_isdigit   #####\n");
// 	assert(isdigit(-1) == ft_isdigit(-1));
// 	assert(isdigit(58) == ft_isdigit(58));
// 	assert(isdigit(57) && ft_isdigit(57));
// 	assert(isdigit(48) && ft_isdigit(48));
// 	printf("	    OK!\n");

// 	printf("\n\n#####   ft_isprint   #####\n");
// 	assert(isprint(-1) == ft_isprint(-1));
// 	assert(isprint(127) == ft_isprint(127));
// 	assert(isprint(31) == ft_isprint(31));
// 	assert(isprint(32) && ft_isprint(32));
// 	assert(isprint(126) && ft_isprint(126));
// 	printf("	    OK!\n");

// 	printf("\n\n#####   ft_memchr    #####\n");
// 	char data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
// 	size_t size = 10;
// 	int try = 60;
// 	assert(memchr(data, try, size) == ft_memchr(data, try, size));
// 	printf("	    OK!\n");

// 	printf("\n\n#####   ft_memcmp    #####\n");
// 	int array1[] = {54, 85, 20, 63, 21};
// 	int array2[] = {54, 85, 19, 63, 21};
// 	size_t s = sizeof(int) * 5;
// 	assert(memcmp(array1, array2, s) == ft_memcmp(array1, array2, s));
// 	assert(memcmp(array1, array1, s) == ft_memcmp(array1, array1, s));
// 	assert(memcmp(array2, array1, s) == ft_memcmp(array2, array1, s));
// 	printf("	    OK!\n");

// 	printf("\n\n#####   ft_memcpy    #####\n");
// 	int array[] = {54, 85, 20, 63, 21};
// 	int *copy = NULL;
// 	int length = sizeof(int) * 5;
// 	copy = (int *)malloc(length);
// 	assert(memcpy(copy, array, length) == ft_memcpy(copy, array, length));
// 	printf("	    OK!\n");
// 	free(copy);

// 	printf("\n\n#####   ft_memset    #####\n");
// 	int buffer[]= {1, 2, 3, 4, 5};
// 	assert(memset( buffer, 0, (sizeof (int) * 5)) == ft_memset( buffer, 0, (sizeof (int) * 5)));
// 	printf("	    OK!\n");

// 	printf("\n\n#####   ft_strchr    #####\n");
// 	char *string = "hello world !";
// 	int	c = 101;
// 	assert(ft_strchr(string, c) == strchr(string, c));
// 	printf("	    OK!\n");

// 	printf("\n\n#####   ft_strrchr   #####\n");
// 	assert(ft_strrchr(string, c) == strrchr(string, c));
// 	printf("	    OK!\n");
// 	return (0);
// }

//  ##############################################################################################
//                                       PARTIE 2
//  ##############################################################################################

// char my_func(unsigned int i, char c)
// {
//     printf("My other function: index = %d and %c\n", i, c);
//     return c - 32;
// }

// void new_func(unsigned int i, char *str)
// {
//     printf("new function: index = %d and the string is %s\n", i, str);
// }

// int	main(void)
// {
//     printf("\n\n#####   ft_substr    #####\n");
// 	char src[] = "Hello World !";
//     int m = 0;
//     int n = 4;
//     char* dest = ft_substr(src, m, n);
//     printf("src = \"%s\"\nstart = %d\nlenght = %d\nnew = \"%s\"\n", src, m, n, dest);

//     printf("\n\n#####   ft_strjoin   #####\n");
// 	char    *s1 = "Hello ";
//     char    *s2 = "World !";
// 	char    *result = ft_strjoin(s1, s2);
// 	printf("%s\n", result);
// 	free(result);

//     printf("\n\n#####   ft_strtrim   #####\n");
//     char    *nasty = "oyoyHello World !yoy";
//     char    *sub = "yo";
//     result = ft_strtrim(nasty, sub);
// 	printf("%s\n", result);
// 	free(result);

//     printf("\n\n#####   ft_split     #####\n");
//     char test[] = "S58VHQ     p70fL       Kx2sRP0So 3E4rC9 bpv3J5ousO84Pa1HjUQOImUhjwZpGn    X28iT7Ap9   DIYAF9ZSpKcs0Rcv uzO   7zjE eonALOKQF5xq   Qxp0b1ufFKGJ 2n8R9zUvZEtOwmqf   ";
//     char arr = ft_split(test, 32);
//     int i = 0;
//     while (arr[i] != 0)
//     {
//         printf("'%s'\n", arr[i]);
//         free(arr[i]);
//         ++i;
//     }
//     printf("'%s'\n", arr[i]);
//     free(arr[i]);
//     free(arr);

//     printf("\n#####     ft_itoa     #####\n");
//     printf("424457 -> %s\n", ft_itoa(424457));
// 	printf("0 -> %s\n", ft_itoa(0));
// 	printf("1337 -> %s\n", ft_itoa(1337));
// 	printf("-0 -> %s\n", ft_itoa(-0));
// 	printf("+132 -> %s\n", ft_itoa(+132));
// 	printf("-2147483648 -> %s\n", ft_itoa(-2147483648));
//     printf("+2147483647 -> %s\n", ft_itoa(+2147483647));

//     printf("\n#####   ft_strmapi    #####\n");
//     char *str = "hello";
//     printf("str = '%s'\n", str);
//     char *map = ft_strmapi(str, my_func);
//     printf("res = '%s'\n", map);

//     printf("\n#####   ft_striteri    #####\n");
// 	printf("str = '%s'\n", str);
// 	ft_striteri(str, new_func);



//     //	Open a file descriptor for the "test.txt" file, in
//     //	truncated write only mode, and create the file if it doesn't
//     //	already exist. Read and write permissions for the owner, read
//     //	permissions for the group.
//     int fd = open("write_in.txt", O_WRONLY | O_TRUNC | O_CREAT, 0640);
//     //	Stop everything if the file could not be opened
// 	if (fd == -1)
// 		return (1);
// 	// printf("fd = %d\n", fd);

//     printf("\n#####   ft_putchar_fd  #####\n");
// 	ft_putchar_fd('x', fd);
//     ft_putchar_fd('\n', fd);

//     printf("\n#####   ft_putstr_fd   #####\n");
//     ft_putstr_fd("hello world !", fd);
//     ft_putchar_fd('\n', fd);

//     printf("\n#####   ft_putendl_fd  #####\n");
//     ft_putendl_fd("this is me~", fd);
//     ft_putstr_fd("Life should be fun for everyone <3", fd);
//     ft_putchar_fd('\n', fd);

//     printf("\n#####   ft_putnbr_fd   #####\n");
//     ft_putnbr_fd(1312, fd);
//     ft_putchar_fd('\n', fd);

// 	close(fd);
// 	return 0;
// }

//  ##############################################################################################
//                                       PARTIE BONUS
//  ##############################################################################################

// int main()
// {
//     // printf("\n#####		ft_lstnew		#####\n");
//     // char *content = "CONTENT.";
// 	// t_list *l = ft_lstnew((void *)content);
// 	// /* 1 */ assert(l->content == (void*)content);
// 	// /* 2 */ assert(l->next == 0);
// 	// printf("	    OK!\n");

//     printf("\n#####		ft_lstadd_front		#####\n");
//     t_list *l = NULL;
// 	char	*old_first = "old_first";
// 	char	*new_first = "new first";
// 	assert(ft_lstlast(l) == 0);
// 	ft_lstadd_front(&l, ft_lstnew((void *)old_first));
//  ft_lstadd_front(&l,  ft_lstnew((void *)new_first));
// 	/* 1 */ assert(l->content == (void *)new_first);
// 	/* 2 */ assert(l->next->content == (void*)old_first);
// 	printf("	    OK!\n");

//     printf("\n#####		ft_lstsize		#####\n");
// 	/* 1 */ assert(ft_lstsize(l) == 2);
// 	// printf("size = %d\n", ft_lstsize(l));
// 	printf("	    OK!\n");

// 	printf("\n#####		ft_lstlast	#####\n");
// 	/* 1 */ assert(ft_lstlast(l)->content == (void *)old_first);
// 	// printf("last content = %s\n.",(char *)(ft_lstlast(l))->content );
// 	printf("	    OK!\n");

// 	printf("\n#####		ft_lstadd_back		#####\n");
// 	char	*last = "last";
// 	ft_lstadd_back(&l, ft_lstnew((void *)last));
	
// 	printf("\n#####    ft_lstdelone   #####\n");

	
// 	free(l);
//  	return 0;
// }


int main(void)
{
	printf("ft_lstclear\t: ");
	char	*n = "toto";
	t_list * l =  NULL;
	assert(ft_lstlast(l) == 0);
	for (int i = 0; i < 10; ++i)
	{
		ft_lstadd_front(&l, ft_lstnew((void *)n));
	}
	print_list(l);
	ft_lstclear(&l, free);
	// /* 1 */ assert(l == 0);
	// write(1, "\n", 1);
	return (0);
}