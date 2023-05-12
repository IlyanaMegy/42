// ---------------------------------------------------------------------------------------------------------------------
//												~ DOCUMENTATION ~
// https://koor.fr/C/cstdio/fprintf.wp
// https://www.sciencedirect.com/topics/computer-science/printf
// https://teampixelcode.wordpress.com/2012/11/01/tuto-reecriture-du-printf-en-c/
// https://public.iutenligne.net/informatique/algorithme-et-programmation/priou/LangageC/61_affichage__laide_de_la_fonction_printf.html
// https://docs.oracle.com/cd/E19253-01/819-6958/6n8ugrl2q/index.html
// http://ressources.unit.eu/cours/Cfacile/co/ch4_p5_5.html
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
// 													~ ALIAS ~
// alias -g cc_me="cc -Wall -Wextra -Werror"
// alias -g norme_me="echo 'yes sir !\n'; norminette -R CheckForbiddenSourceHeader"
// alias cl="clear; echo '\naww~ look at u all cleaned up :*'"
// alias -g cc_malloc="clang -Wextra -Wall -Werror -g3 -fsanitize=address"
// ---------------------------------------------------------------------------------------------------------------------

#include "libftprintf.h"
#include <stdio.h>

// int	main(int argc, char *argv[])
int	main(void)
{
	printf("%d\n", printf(""));
	// printf("\n");
	return 0;
}