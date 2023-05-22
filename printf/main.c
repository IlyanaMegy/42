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
// alias -g norme_me="echo 'yes sir !\n'; norminette
//	-R CheckForbiddenSourceHeader"
// alias cl="clear; echo '\naww~ look at u all cleaned up :*'"
// alias -g cc_malloc="clang -Wextra -Wall -Werror -g3 -fsanitize=address"
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
//													~ TESTER ~
// gcl git@github.com:Tripouille/printfTester.git
// https://github.com/FreekBes/improved_intra
// ---------------------------------------------------------------------------------------------------------------------

#include "include/printf.h"
#include <stdio.h>

int	main(void)
{
	int i = 0;
	printf(" -> expected	: %d\n", printf(" %i\n", i));
	printf(" -> result	: %d\n",  ft_printf(" %i\n", i));
}