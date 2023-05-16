// ---------------------------------------------------------------------------------------------------------------------
//												~ DOCUMENTATION ~
// https://koor.fr/C/cstdio/fprintf.wp
// https://www.sciencedirect.com/topics/computer-science/printf
// https://teampixelcode.wordpress.com/2012/11/01/tuto-reecriture-du-printf-en-c/
// https://public.iutenligne.net/informatique/algorithme-et-programmation/priou/LangageC/61_affichage__laide_de_la_fonction_printf.html
// https://docs.oracle.com/cd/E19253-01/819-6958/6n8ugrl2q/index.html
// http://ressources.unit.eu/cours/Cfacile/co/ch4_p5_5.html
// https://csnotes.medium.com/ft-printf-tutorial-42project-f09b6dc1cd0e
// https://www.bien-programmer.fr/variadics.htm
// https://koor.fr/C/cstdarg/va_arg.wp
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
// 													~ ALIAS ~
// alias -g cc_me="cc -Wall -Wextra -Werror"
// alias -g norme_me="echo 'yes sir !\n'; norminette -R CheckForbiddenSourceHeader"
// alias cl="clear; echo '\naww~ look at u all cleaned up :*'"
// alias -g cc_malloc="clang -Wextra -Wall -Werror -g3 -fsanitize=address"
// ---------------------------------------------------------------------------------------------------------------------

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

// int	main(int argc, char *argv[])
int	main(void)
{
	char *empty = 0;
	// ft_printf("%dhello\n %");
	// unsigned int i = 0;
	printf("%d expected %d\n", ft_printf("%i %i %i %i %i %i %i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42), printf("%i %i %i %i %i %i %i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	// printf("\n");
	return 0;
}