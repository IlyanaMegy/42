#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include "ex00/ft_iterative_factorial.c"
// #include "ex01/ft_recursive_factorial.c"
// #include "ex02/ft_iterative_power.c"
// #include "ex03/ft_recursive_power.c"
// #include "ex04/ft_fibonacci.c"
// #include "ex05/ft_sqrt.c"
// #include "ex06/ft_is_prime.c"
#include "ex07/ft_find_next_prime.c"

int	main(void)
{
	// printf("-----------------------------------\n");
	// printf("--------iterative factorial--------\n");
	// printf("-----------------------------------\n");
	// printf("0:%d\n", ft_iterative_factorial(-10));
	// printf("0:%d\n", ft_iterative_factorial(-1));
	// printf("1:%d\n", ft_iterative_factorial(0));
	// printf("1:%d\n", ft_iterative_factorial(1));
	// printf("3628800:%d\n", ft_iterative_factorial(10));
	// printf("6:%d\n", ft_iterative_factorial(3));

	// printf("-----------------------------------\n");
	// printf("--------recursive factorial--------\n");
	// printf("-----------------------------------\n");
	// printf("0:%d\n", ft_recursive_factorial(-10));
	// printf("0:%d\n", ft_recursive_factorial(-1));
	// printf("1:%d\n", ft_recursive_factorial(0));
	// printf("1:%d\n", ft_recursive_factorial(1));
	// printf("3628800:%d\n", ft_recursive_factorial(10));
	// printf("6:%d\n", ft_recursive_factorial(3));

	// printf("-----------------------------------\n");
	// printf("----------iterative power----------\n");
	// printf("-----------------------------------\n");
	// printf("0:%d\n", ft_iterative_power(1, -10));
	// printf("0:%d\n", ft_iterative_power(1, -1));
	// printf("1:%d\n", ft_iterative_power(10, 0));
	// printf("10:%d\n", ft_iterative_power(10, 1));
	// printf("100:%d\n", ft_iterative_power(10, 2));
	// printf("216:%d\n", ft_iterative_power(6, 3));

	// printf("-----------------------------------\n");
	// printf("----------recursive power----------\n");
	// printf("0:%d\n", ft_recursive_power(1, -10));
	// printf("0:%d\n", ft_recursive_power(1, -1));
	// printf("1:%d\n", ft_recursive_power(10, 0));
	// printf("10:%d\n", ft_recursive_power(10, 1));
	// printf("100:%d\n", ft_recursive_power(10, 2));
	// printf("216:%d\n", ft_recursive_power(6, 3));

	// printf("-----------------------------------\n");
	// printf("-------------fibonacci-------------\n");
	// printf("0:%d\n", ft_fibonacci(0));
	// printf("1:%d\n", ft_fibonacci(1));
	// printf("1:%d\n", ft_fibonacci(2));
	// printf("2:%d\n", ft_fibonacci(3));
	// printf("55:%d\n", ft_fibonacci(10));

	// printf("-----------------------------------\n");
	// printf("-------------squareroot------------\n");
	// printf("10:%d\n", ft_sqrt(100));
	// printf("6:%d\n", ft_sqrt(36));
	// printf("0:%d\n", ft_sqrt(37));
	// printf("100:%d\n", ft_sqrt(10000));
	// printf("0:%d\n", ft_sqrt(10001));
	// printf("2000:%d\n", ft_sqrt(4000000));
	// printf("0:%d\n", ft_sqrt(-36));

	printf("-----------------------------------\n");
	printf("----------------prime--------------\n");
	printf("%d\n", ft_is_prime(-1));
	printf("%d\n", ft_is_prime(0));
	printf("%d\n", ft_is_prime(1));
	printf("%d\n", ft_is_prime(2));
	printf("%d\n", ft_is_prime(3));
	printf("%d\n", ft_is_prime(4));
	printf("%d\n", ft_is_prime(997));

	printf("-----------------------------------\n");
	printf("-------------next prime------------\n");
	printf("%d\n", ft_find_next_prime(-1));  //0
	printf("%d\n", ft_find_next_prime(-3));  //0
	printf("%d\n", ft_find_next_prime(0));  //0
	printf("%d\n", ft_find_next_prime(1)); //0
	printf("%d\n", ft_find_next_prime(2));
	printf("%d\n", ft_find_next_prime(3));
	printf("%d\n", ft_find_next_prime(4));
	printf("%d\n", ft_find_next_prime(5));
	printf("%d\n", ft_find_next_prime(6));
	printf("%d\n", ft_find_next_prime(7));
	printf("%d\n", ft_find_next_prime(10));
	printf("%d\n", ft_find_next_prime(11));
	printf("%d\n", ft_find_next_prime(13));
	printf("%d\n", ft_find_next_prime(19));
	printf("%d\n", ft_find_next_prime(20));

	return (0);
}
