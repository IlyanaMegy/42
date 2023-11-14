#include "ex00/ft_strlen.c"
#include "ex01/ft_putstr.c"
#include "ex02/ft_putnbr.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "ex03/ft_atoi.c"
// #include "ex04/ft_putnbr_base.c"

void	print_c(char c)
{
	write(1, &c, 1);
}

void	print_str(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		print_c(str[n]);
		++n;
	}
}

void	print_int(int nb)
{
	if (nb == -2147483648)
	{
		print_c('-');
		print_c('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		print_c('-');
		print_int(-nb);
	}
	else if (nb > 9)
	{
		print_int(nb / 10);
		print_c(nb % 10 + 48);
	}
	else
		print_c(nb + 48);
}

int	main(int argc, char *argv[])
{
	char *filename;
	int i;

	filename = argv[0];
	i = 0;
	print_str("filename = ");
	print_str(filename);
	print_str("\n");

	print_str("there is ");
	print_int(argc);
	print_str(" args.\n");

	while (i < argc)
	{
		print_str("argv[");
		print_int(i);
		print_str("] = ");
		print_str(argv[i]);
		print_str("\n");
		++i;
	}

	print_str("--------------------------\n");
	print_str("----------strlen----------\n");
	// char *s0;

	// if (argc > 1)
	// {
	// 	print_str("s0 = \"");
	// 	s0 = argv[1];
	// }
	// else
	// {
	// 	s0 = "default";
	// 	print_str("/!\\ no args entered\ns0 = \"");
	// }
	// print_str(s0);
	// print_str("\"\n");
	// print_str("len(s0) = ");
	// print_int(ft_strlen(s0));
	print_str("\n\n");

	print_str("--------------------------\n");
	print_str("----------putstr----------\n");
	char *s1;
	char *s2;

	if (argc > 2)
	{
		s1 = argv[1];
		s2 = argv[2];
		print_str("s1 = \"");
	}
	else
	{
		s1 = "Suc";
		s2 = "cess";
		print_str("/!\\ no args entered\ns1 = \"");
	}
	print_str(s1);
	print_str("\"\ns2 = \"");
	print_str(s2);
	print_str("\"\n");
	ft_putstr(s1);
	ft_putstr(s2);
	print_str("\n\n");

	print_str("--------------------------\n");
	print_str("----------putnbr----------\n");
	if (argc > 1)
	{
		print_str("res = \"");
		ft_putnbr(atoi(argv[1]));
		print_str("\"\n\n");
	}
	else
	{
		print_str("/!\\ no args entered\n");
		ft_putnbr(-42);
		print_str("\n");
		ft_putnbr(-2147483648);
		print_str("\n");
		ft_putnbr(2147483647);
		print_str("\n\n");
	}

	// print_str("--------------------------\n");
	// print_str("-----------atoi-----------\n");

	// print_str("42:%d\n", ft_atoi("  \n  42t4457"));
	// print_str("0:%d\n", ft_atoi(""));
	// print_str("0:%d\n", ft_atoi("\0 1337"));
	// print_str("0:%d\n", ft_atoi("-0"));
	// print_str("0:%d\n", ft_atoi(" -  1 3 2 5 6 3 2 1 6 7"));
	// print_str("-1325632167:%d\n", ft_atoi("-1325632167"));
	// print_str("-100:%d\n", ft_atoi("-100"));
	// print_str("min:%d\n", ft_atoi("\t---+2147483648"));
	// print_str("max:%d\n", ft_atoi("\v2147483647"));

	// print_str("--------------------------\n");
	// print_str("-------putnbr_base--------\n");
	// write(1, "-42:", 4);
	// ft_putnbr_base(-42, "0123456789");

	// write(1, "\n2a:", 4);
	// ft_putnbr_base(42, "0123456789abcdef");

	// write(1, "\n-2a:", 5);
	// ft_putnbr_base(-42, "0123456789abcdef");

	// write(1, "\n-vn:", 5);
	// ft_putnbr_base(-42, "poneyvif");

	// write(1, "\n:", 2);
	// ft_putnbr_base(42, "");

	// write(1, "\n:", 2);
	// ft_putnbr_base(42, "0");

	// write(1, "\n:", 2);
	// ft_putnbr_base(42, "+-0123456789abcdef");

	// print_str("--------------------------\n");
	// print_str("--------atoi base---------\n");

	return (0);
}